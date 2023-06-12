/**
 * @file game.cpp
 * @brief Source file for class Game
 * @author Arthur Ancien
 * @date 05/06/2023
 * @version 1.2
 */

#include <chrono>
#include <QObject>
#include "game.h"
#include "typedef.h"
#include <iostream>
#include <QElapsedTimer>
#include <QDebug>
#include <iostream>
#include <QThread>


Game::Game()
{
    itsTileSet = new TileSet(TILESET_FILE_PATH);
    itsPlayer = new Player((32*39)/2, 250, 64, 32, itsTileSet->getItsPlayerTile());
    itsLevel = new Level(LEVEL_FILE_PATH,itsTileSet);
    itsHMI = new HMI(itsLevel, itsPlayer, this);
    itsEllapsedTime = 0;
    itsHMI->show();
    itsLoopCounter = NUMBER_LOOP_PER_SECOND;
}
// Connexion des signaux et slots

void Game::onGameStart(){
    itsLevel->activate();
    itsHMI->refreshAll();
    itsEllapsedTime = 0;
    gameLoop();
}

void Game::gameLoop()
{
    QElapsedTimer timer;
    timer.restart();
    if(itsLoopCounter == 0)itsLoopCounter = NUMBER_LOOP_PER_SECOND;
    itsEllapsedTime += 0.001;

    if (itsLevel->getItsRemainingEnemies().size() > 0){
        unsigned short pos = itsLevel->getItsRemainingEnemies().size()-1;
        if(!(itsLevel->getItsEnemyAppearsTimes().empty()) && itsEllapsedTime >= itsLevel->getItsEnemyAppearsTimes().at(pos))
        {
            Enemy * enemy = itsLevel->getItsRemainingEnemies().at(pos);
            Sides side = itsLevel->getItsEnemyAppearsSides().at(pos);
            switch(side){
            case LEFT:
                itsLevel->getItsSpawnerList().at(0)->appears(enemy);
                enemy->setItsXSpeed(RIGHT_X);
                break;
            case RIGHT:
                itsLevel->getItsSpawnerList().at(1)->appears(enemy);
                enemy->setItsXSpeed(LEFT_X);
                break;
            }

            itsLevel->appears(enemy);
            itsEllapsedTime = 0;
        }
    }
    checkAllCollid();
    moveAll();
    if(itsLoopCounter % (NUMBER_LOOP_PER_SECOND/FPS) == 0)itsHMI->refreshAll();
    itsLoopCounter--;
    if((itsLevel->getItsEnemiesList().empty() && itsLevel->getItsRemainingEnemies().empty()) || itsPlayer->getItsLivesNb() == 0)
    {
        itsHMI->stopGame();
    }
    unsigned int elapsedTime = timer.nsecsElapsed();
    qWarning() << "Game loop execution time in nanoseconds : " << elapsedTime;
}


unsigned int Game::getItsScore() const
{
    return itsScore;
}

Player *Game::getItsPlayer() const
{
    return itsPlayer;
}

void Game::checkAllCollid(){
    // player to block
    bool playerGravity = (itsPlayer->getItsRemaningJumpMove() == 0);
    itsPlayer->setIsOnTheGround(false);
    for (Block * block : itsLevel->getItsBlockList()){
        if(block->getItsType() == BRICK){
            if(block->getItsCounter() != 0)//changement de la tuile quand elle est frappé
            {
                block->setItsCounter(block->getItsCounter() - 1);
                block->setItsSprite(itsTileSet->getItsBlockHitTile());
            }
            else
            {
                block->setItsState(false);
                block->setItsSprite(itsTileSet->getItsBlockTile());
            }
        }
        if(collid(itsPlayer, block) == true){
            colBtwPlayerAndBlock(itsPlayer, block);
            if (isOnTop(itsPlayer, block)){
                playerGravity = false;
                itsPlayer->setIsOnTheGround(true);
            }
        }
    }


    if (playerGravity)
    {
        itsPlayer->setItsYSpeed(GRAVITY);
    }
    else
    {
        itsPlayer->setItsYSpeed(itsPlayer->getItsYSpeed() > STILL?STILL:itsPlayer->getItsYSpeed());
    }
    std::vector<Enemy *> enemyList = itsLevel->getItsEnemiesList();

    if (enemyList.size()>0){
        // player to enemy

        bool gravityList[enemyList.size()];
        for (unsigned short i = 0; i < enemyList.size(); i++){
            gravityList[i] = true;
        }

        for (unsigned short i1 = 0; i1 < enemyList.size(); i1++){

            Enemy * enemy1 = enemyList.at(i1);
            if (collid(itsPlayer, enemy1)){
                colBtwPlayerAndEnemy(itsPlayer, enemy1);
            }

            for (Despawner * despawner : itsLevel->getItsDespawnerList()){
                if(collid(enemy1, despawner)){
                    colBtwEnemyAndDespawner(enemy1, despawner);
                }
            }
            for (Block * block : itsLevel->getItsBlockList()){
                if (collid(enemy1, block)){
                    if (isOnTop(enemy1, block)){
                        gravityList[i1] = false;
                    }
                    colBtwEnemyAndBlock(enemy1, block);
                }
            }
            if (enemyList.size() >= 2 &&  (itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(STANDARD_ENEMY_SPEED*BLOCK_SIZE))) == 0){
                for (unsigned int i2 = i1+1; i2 < enemyList.size(); i2++){
                    Enemy * enemy2 = enemyList.at(i2);
                    if (enemy1 != enemy2 && collid(enemy1, enemy2)){
                        qWarning()<<itsLoopCounter;
                        colBtwEnemyAndEnemy(enemy1, enemy2);
                        if (isOnTop(enemy1, enemy2)){
                            gravityList[i1] = false;
                        }
                        else if (isOnTop(enemy2, enemy1)){
                            gravityList[i2] = false;
                        }
                    }
                }
            }
            if (gravityList[i1]){
                enemy1->setItsYSpeed(GRAVITY);
            }
            else{
                enemy1->setItsYSpeed(STILL);
            }
            if(enemy1->getItsNumberLoopKO() != 0)enemy1->setItsNumberLoopKO(enemy1->getItsNumberLoopKO()-1);
            else
            {
                enemy1->setItsState(true);
                enemy1->setItsSprite(itsTileSet->getItsEnemyTile());
            }
        }
    }
}


void Game::colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy)
{

    if(theEnemy->getItsState())//quand l'ennemie n'est PAS KO
    {
        thePlayer->setItsLivesNb(thePlayer->getItsLivesNb() - 1);
        thePlayer->setX((BLOCK_SIZE*39)/2);
        thePlayer->setY(32);
        thePlayer->getItsRect()->moveTo((BLOCK_SIZE*39)/2,32);
        thePlayer->setItsRemaningJumpMove(0);
        thePlayer->setItsCurrentMove(NONE);
        thePlayer->setItsNextMove(NONE);
    }
    else//quand l'enemie est KO
    {
        itsScore += theEnemy->getItsType();
        itsLevel->removeEnemy(theEnemy);

    }
}

void Game::colBtwEnemyAndEnemy(Enemy* theFirstEnemy, Enemy* theSecondEnemy)
{
    if (!isOnTop(theFirstEnemy, theSecondEnemy) && !isOnTop(theSecondEnemy, theFirstEnemy)){
        if((theFirstEnemy->getItsXSpeed() < 0) != (theSecondEnemy->getItsXSpeed() < 0))//si les deux enemy sont dans des directions différentes
        {
            theFirstEnemy->setItsXSpeed(theFirstEnemy->getItsXSpeed()*(-1));
        }
        theSecondEnemy->setItsXSpeed(theSecondEnemy->getItsXSpeed()*(-1));
    }
}

void Game::colBtwEnemyAndBlock(Enemy* theEnemy, Block* theBlock)
{
    theEnemy->setItsYSpeed(STILL);
    if(theBlock->getItsState())
    {
        if(theEnemy->getItsState() && theEnemy->getItsNumberLoopKO() == 0)
        {
            theEnemy->setItsState(false);
            theEnemy->setItsSprite(itsTileSet->getItsEnemyHitTile());
            theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
        }
        else if(!theEnemy->getItsState() && theEnemy->getItsNumberLoopKO() < (KO_TIME * NUMBER_LOOP_PER_SECOND)-((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME)-1)//+1 car problème de précision
        {
            theEnemy->setItsState(true);
            theEnemy->setItsSprite(itsTileSet->getItsEnemyTile());
            theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
        }
    }
    theEnemy->setIsOnTheGround(true);
}

void Game::colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock)
{
    if(thePlayer->getItsRect()->top() == theBlock->getItsRect()->bottom() && thePlayer->getItsYSpeed() < STILL)
    {
        thePlayer->setItsRemaningJumpMove(0);//à remplacer par STILL pour l'instant inverse la vitesse
        theBlock->setItsState(true);
        theBlock->setItsCounter((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME);
    }
    if(thePlayer->getItsRect()->bottom() == theBlock->getItsRect()->top())//le joueur est sur un block
    {
        thePlayer->setItsYSpeed(thePlayer->getItsYSpeed() > STILL?STILL:thePlayer->getItsYSpeed());
        thePlayer->setIsOnTheGround(true);
    }

    if((thePlayer->getItsRect()->top() < theBlock->getItsRect()->bottom()) && (thePlayer->getItsRect()->bottom() > theBlock->getItsRect()->top())){
        if((thePlayer->getItsRect()->right() == theBlock->getItsRect()->left()))
        {
            thePlayer->setItsCurrentMove(NONE);
        }
        else if((thePlayer->getItsRect()->left() == theBlock->getItsRect()->right()))
        {
            thePlayer->setItsCurrentMove(NONE);
        }
    }
}

void Game::colBtwEnemyAndDespawner(Enemy* theEnemy, Despawner* theDespawner)
{
    theDespawner->disappear(theEnemy);
}

bool Game::isOnTop(Entity * entity1, Entity * entity2){
    return entity1->getItsY() + entity1->getItsHeight() <= entity2->getItsY();
}

bool Game::collid(Entity * entity1, Entity * entity2){

    if(entity1->getItsX() > (entity2->getItsX() + entity2->getItsWidth())){      // trop à droite
        return false;
    }
    if((entity1->getItsX() + entity1->getItsWidth()) < entity2->getItsX()){ // trop à gauche
        return false;
    }
    if(entity1->getItsY() > (entity2->getItsY() + entity2->getItsHeight())){ // trop en bas
        return false;
    }

    if((entity1->getItsY() + entity1->getItsHeight()) < entity2->getItsY()){  // trop en haut
        return false;
    }
    return true;
}


void Game::moveAll(){
    if(itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(PLAYERMAXSPEED*BLOCK_SIZE)) == 0)//NUMBER_LOOP_PER_SECOND/((NUMBER_LOOP_PER_SECOND/BLOCK_SIZE)/PLAYERMAXSPEED))
    {
        itsPlayer->move();
    }
    for (Enemy * enemy : itsLevel->getItsEnemiesList()){
        switch (enemy->getItsType()) {
        case STANDARD:
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(STANDARD_ENEMY_SPEED*BLOCK_SIZE))) == 0){
                enemy->move();
            }
            break;
        default:
            break;
        }
    }
}

void Game::onLeftKeyPressed()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(LEFT_X);
    /*    else */itsPlayer->setItsNextMove(LEFT_X);
}

void Game::onRightKeyPressed()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(RIGHT_X);
    /*    else */itsPlayer->setItsNextMove(RIGHT_X);
}

void Game::onUpKeyPressed()
{
    if(itsPlayer->getIsOnTheGround()){
        itsPlayer->setItsYSpeed(-1);
        itsPlayer->setItsRemaningJumpMove(PLAYER_JUMP_HEIGHT*BLOCK_SIZE);
    }
}

void Game::onLeftKeyReleased()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(NONE);
    /*    else */itsPlayer->setItsNextMove(NONE);
}

void Game::onRightKeyReleased()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(NONE);
    /*    else */itsPlayer->setItsNextMove(NONE);
}

void Game::onGamePaused()
{
    isInPause = true;
}

void Game::onGameResumed()
{
    isInPause = false;
}
