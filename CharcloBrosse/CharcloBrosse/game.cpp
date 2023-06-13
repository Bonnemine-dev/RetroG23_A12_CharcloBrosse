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
    itsTileSet = new TileSet(TILESET_FILE_PATH, BACKGROUND_FILE_PATH);
    itsPlayer = new Player((32*39)/2, (32*18), 64, 32, itsTileSet->getItsPlayerRunningRightTile(1));
    itsLevel = nullptr;
    itsHMI = new HMI(nullptr, itsPlayer, this);
    itsEllapsedTime = 0;
    itsHMI->show();
    itsLoopCounter = NUMBER_LOOP_PER_SECOND;
    running = false;
    isBlockPOWHitted = false;

}
// Connexion des signaux et slots

void Game::onGameStart(){
    currentLevel = 1;
    itsPlayer->setItsLivesNb(3);
    itsScore = 0;
    openLevel();
    itsHMI->setLevel(itsLevel);
    itsHMI->displayLevelNumber();
    itsEllapsedTime = 0;
    gameLoop();
    running = true;
}

void Game::gameLoop()
{
    if(running){
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

        if(isLevelFinished()){
            if (currentLevel != MAX_LEVEL){
                if (currentTier != checkTier()){
                    currentTier = checkTier();
                    delete itsTileSet;
                    std::string tileSetFileName = ":/ressources/tileset" + std::to_string(((int) currentTier)-1) + ".png";
                    std::string BackgroundFileName = ":/ressources/background" + std::to_string(((int) currentTier)-1) + ".png";
                    itsTileSet = new TileSet(tileSetFileName, BackgroundFileName);
                }
                currentLevel++;
                openLevel();
                itsHMI->setLevel(itsLevel);
                itsHMI->displayLevelNumber();
                itsLoopCounter = NUMBER_LOOP_PER_SECOND;
                itsEllapsedTime = 0;
            }
            else{
                currentLevel = 1;
                itsHMI->stopGame();
            }
        }

        if(itsPlayer->getItsLivesNb() == 0)
        {
            currentLevel = 1;
            itsHMI->stopGame();
        }
    }
}


unsigned int Game::getItsScore() const
{
    return itsScore;
}

Player *Game::getItsPlayer() const
{
    return itsPlayer;
}


unsigned int Game::getItsMoney() const
{
    return itsMoney;
}

void Game::setItsMoney(unsigned int newItsMoney)
{
    itsMoney = newItsMoney;
}
void Game::spawnPlayer()
{
    itsPlayer->setItsYSpeed(0);
    itsPlayer->setItsXSpeed(0);
    itsPlayer->setX((32*39)/2);
    itsPlayer->setY((32*18));
}

void Game::checkAllCollid(){
    //isBlockPOWHitted = false; // A retirer une fois le bloc pow immplémenter
    // player to block
    bool playerGravity = (itsPlayer->getItsRemaningJumpMove() == 0);
    itsPlayer->setIsOnTheGround(false);

    for (Block * block : itsLevel->getItsBlockList())
    {
        if (block->getItsType() == OBSTACLE && collid(itsPlayer, block))
        {
            colBtwPlayerAndObstacle(itsPlayer);

        }

        if(block->getItsType() == BRICK)
        {
            if(block->getItsCounter() != 0)//changement de la tuile quand elle est frappé
            {
                block->setItsCounter(block->getItsCounter() - 1) ;
                block->setItsSprite(itsTileSet->getItsBlockHittedTile());
            }
            else
            {
                block->setItsState(false);
                block->setItsSprite(itsTileSet->getItsBlockTile());
            }
        }
        if(collid(itsPlayer, block) == true)
        {
            colBtwPlayerAndBlock(itsPlayer, block);
            if (isOnTop(itsPlayer, block))
            {
                playerGravity = false;
                itsPlayer->setIsOnTheGround(true);
            }
        }
    }
    for (Money * money : itsLevel->getItsMoneyList()){
        if(collid(itsPlayer,money))
        {
            colBtwPlayerAndMoney(itsPlayer,money);
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
                if (collid(enemy1, block) && (block->getItsType() == BRICK || block->getItsType() == GROUND || block->getItsType() == POW)){
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
                switch (enemy1->getItsType())
                {
                case STANDARD:
                    enemy1->setItsState(true);
                    enemy1->setItsSprite(itsTileSet->getItsEnemyStandardRunningRightTile(0));
                    break;
                case GIANT:
                    enemy1->setItsState(true);
                    enemy1->setItsSprite(itsTileSet->getItsEnemyGiantRunningRightTile(0));
                    break;
                case ACCELERATOR:
                    enemy1->setItsState(true);
                    enemy1->setItsSprite(itsTileSet->getItsEnemyAccelerator1RunningRightTile(0));
                    break;
                default:
                    break;
                }
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
        thePlayer->setY(0);
        thePlayer->getItsRect()->moveTo((BLOCK_SIZE*39)/2,32);
        thePlayer->setItsRemaningJumpMove(0);
        thePlayer->setItsCurrentMove(NONE);
        thePlayer->setItsNextMove(NONE);
    }
    else//quand l'enemie est KO
    {
        int tier = currentTier;
        int multiplier = tier * 3; // Le multiplicateur est 1 plus 3 fois le tier. Si tier est 0, le multiplicateur est 1.
        itsScore += theEnemy->getItsType() * multiplier;
        itsLevel->removeEnemy(theEnemy);
    }
}

void Game::colBtwPlayerAndObstacle(Player* thePlayer)
{
    thePlayer->setItsLivesNb(thePlayer->getItsLivesNb() - 1);
    thePlayer->setX((32*39)/2);
    thePlayer->setY(0);
    thePlayer->getItsRect()->moveTo((32*39)/2,32);
    thePlayer->setItsCurrentMove(NONE);
    thePlayer->setItsNextMove(NONE);
}

// Fonction appelé dans la collision entre le joueur et le bloc
void Game::colBtwPlayerAndBlockPOW(Player* thePlayer, Block *theBlockPOW)
{
    // Le bloc POW passe à l'état frappé dans la gameLoop.
    isBlockPOWHitted = true;
    // Le saut du joueur est stoppé.
    thePlayer->setItsRemaningJumpMove(0);
    // L'état du bloc POW passe à true.
    theBlockPOW->setItsState(true);
    // L'image du bloc POW est modifié.
    theBlockPOW->setItsSprite(itsTileSet->getItsPOWBlockHittedTile());
    // On parcours tous les ennemis présent sur le terrain
    for (Enemy * enemy : itsLevel->getItsEnemiesList())
    {
        // Les ennemis qui sont en train dde sauter ou tomber ne sont pas concerné.
        if(enemy->getItsYSpeed() == 0)
        {
            // Si l'ennemi n'est pas KO
            if((enemy->getItsState() == true))
            {
                // L'ennemi deveint KO
                enemy->setItsState(false);
                // L'image de l'ennemi est modifié
                enemy->setItsSprite(itsTileSet->getItsEnemyAccelerator1HittedRightTile(0));
                // La loop de durée de KO est démarré
                enemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                // Si l'ennemi est de type ACCELERATEUR il a un comportement spécial.
                if(enemy->getItsType() == ACCELERATOR)
                {
                    // L'état d'accélération est modifié
                    Accelerator* accelerator = dynamic_cast<Accelerator*>(enemy);
                    accelerator->addItsSpeedState();
                }
            }
            // Si l'ennemi est KO
            else if((enemy->getItsState() == false))
            {
                // L'ennemi redevient vivant
                enemy->setItsState(true);
                // L'image de l'ennemi est modifié
                enemy->setItsSprite(itsTileSet->getItsEnemyStandardRunningRightTile(0));
                // La loop de durée de KO est stopppé
                enemy->setItsNumberLoopKO(0);
            }
        }
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
            switch (theEnemy->getItsType())
            {
            case STANDARD:
                theEnemy->setItsState(false);
                theEnemy->setItsSprite(itsTileSet->getItsEnemyStandardHittedRightTile(0));
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            case GIANT:
                theEnemy->setItsState(false);
                theEnemy->setItsSprite(itsTileSet->getItsEnemyGiantHittedRightTile(0));
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            case ACCELERATOR:
                theEnemy->setItsState(false);
                theEnemy->setItsSprite(itsTileSet->getItsEnemyAccelerator1HittedRightTile(0));
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                Accelerator* accelerator = dynamic_cast<Accelerator*>(theEnemy);
                accelerator->addItsSpeedState();
                break;
            }
        }
        else if(!theEnemy->getItsState() && theEnemy->getItsNumberLoopKO() < (KO_TIME * NUMBER_LOOP_PER_SECOND)-((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME)-1)//+1 car problème de précision
        {
            switch (theEnemy->getItsType())
            {
            case STANDARD:
                theEnemy->setItsState(true);
                theEnemy->setItsSprite(itsTileSet->getItsEnemyStandardRunningLeftTile(0));
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            case GIANT:
                theEnemy->setItsState(true);
                theEnemy->setItsSprite(itsTileSet->getItsEnemyGiantRunningRightTile(0));
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            case ACCELERATOR:
                theEnemy->setItsState(true);
                theEnemy->setItsSprite(itsTileSet->getItsEnemyAccelerator1RunningRightTile(0));
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            default:
                break;
            }
        }
    }
    theEnemy->setIsOnTheGround(true);
}

void Game::colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock)
{
    if(thePlayer->getItsRect()->top() == theBlock->getItsRect()->bottom() && thePlayer->getItsYSpeed() < STILL)
    {
        // Si le bloc est un bloc POW et qu'il n'a pas été frappé.
        if((theBlock->getItsType() == POW) == (isBlockPOWHitted == false))
        {
            // On appelle la méthode correspondante.
            colBtwPlayerAndBlockPOW(thePlayer, theBlock);
        }
        // Sinon c'est on bloc normal.
        else
        {
            thePlayer->setItsRemaningJumpMove(0);//à remplacer par STILL pour l'instant inverse la vitesse
            theBlock->setItsState(true);
            theBlock->setItsCounter((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME);
        }


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
    if ((theEnemy->getItsX() <= theEnemy->getItsWidth()) ||(theEnemy->getItsX() >= WIDTH*32-theEnemy->getItsWidth())) {
        theDespawner->disappear(theEnemy);
    }
}

void Game::colBtwPlayerAndMoney(Player* thePlayer, Money* theMoney)
{
    if (theMoney->getItsMoneyType()==RED)
    {
        setItsMoney(getItsMoney()+1);
    }
    else if (theMoney->getItsMoneyType()==YELLOW)
    {
        setItsMoney(getItsMoney()+3);
    }
    else
    {
        setItsMoney(getItsMoney()+5);
    }
    itsLevel->removeMoney(theMoney);
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

int Game::checkTier()
{
    if (itsMoney >= 100)
        return 5; // Quatrième palier
    else if (itsMoney >= 50)
        return 4; // Troisième palier
    else if (itsMoney >= 25)
        return 3; // Deuxième palier
    else if (itsMoney >= 10)
        return 2; // Premier palier
    else
        return 1; // Pas encore de palier atteint
}



void Game::moveAll(){
    if(itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(PLAYERMAXSPEED*BLOCK_SIZE)) == 0)//NUMBER_LOOP_PER_SECOND/((NUMBER_LOOP_PER_SECOND/BLOCK_SIZE)/PLAYERMAXSPEED))
    {
        itsPlayer->move();
    }
    for (Enemy * enemy : itsLevel->getItsEnemiesList()){
        switch (enemy->getItsType())
        {
        case STANDARD:
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(STANDARD_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                enemy->move();
            }
            break;
        case GIANT:
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(GIANT_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                enemy->move();
            }
            break;
        case ACCELERATOR:
            Accelerator* accelerator = dynamic_cast<Accelerator*>(enemy);
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/((ACCELERATOR_ENEMY_SPEED+accelerator->getItsSpeedState())*BLOCK_SIZE))) == 0)
            {
                enemy->move();
            }
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
    running = false;
    itsLevel->desactivate();
}

void Game::onGameResumed()
{
    isInPause = false;
    running = true;
    itsLevel->activate();
}

void Game::openLevel(){
    std::string fileName = "://ressources/level" + std::to_string(currentLevel) + ".json";
    if (itsLevel != nullptr){
        delete itsLevel;
        itsLevel = nullptr;
    }
    itsLevel = new Level(fileName, itsTileSet);
}

void Game::levelTimeout()
{
    itsLevel->desactivate();
    running = false;
}

bool Game::isLevelFinished(){
    return itsLevel->getItsEnemiesList().empty() && itsLevel->getItsRemainingEnemies().empty();
}
