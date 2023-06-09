#include <chrono>
#include <QObject>
#include "game.h"
#include "typedef.h"
#include <iostream>
#include <QElapsedTimer>
#include <QDebug>
#include <iostream>

void displayCoord(Entity * entity1, Entity * entity2){
    qWarning() << entity1->getItsY();
    qWarning() << entity2->getItsY();

    //    qWarning() << "trop a droite : " << (entity2->getItsX() > entity1->getItsX() + entity1->getItsWidth());
    //    qWarning() << "trop a gauche : " << (entity2->getItsX() + entity2->getItsWidth() < entity1->getItsX());
    //    qWarning() << "trop en bas : " << (entity2->getItsY() > entity1->getItsY() + entity1->getItsHeight());
    //    qWarning() << "trop en haut : " << (entity2->getItsY() + entity2->getItsHeight() < entity1->getItsY());
}


Game::Game()
{
    itsTileSet = new TileSet("tileset0.png");
    itsPlayer = new Player((32*39)/2, 250, 64, 32, itsTileSet->getItsPlayerTile());
    itsLevel = new Level("level1.json",itsTileSet);
    itsHMI = new HMI(itsLevel, itsPlayer, this);
    itsEllapsedTime = 0;
    itsHMI->show();
}
// Connexion des signaux et slots

void Game::onGameStart(){
    itsLevel->activate();
    itsHMI->refreshAll();
    itsEllapsedTime = 0;
}

void Game::gameLoop()
{
//    QElapsedTimer timer;
//    timer.start();
    itsEllapsedTime += 0.16;//0.16




        if(!(itsLevel->getItsEnemyAppearsTimes().empty()) && itsEllapsedTime >= itsLevel->getItsEnemyAppearsTimes().at(0))
        {
        std::cout<<"Je passe dans la condition pour faire apparaitre un enemy \n";
        Enemy * enemy = itsLevel->getItsRemainingEnemies().at(0);
            Sides side = itsLevel->getItsEnemyAppearsSides().at(0);
            switch(side){
            case LEFT:
                itsLevel->getItsSpawnerList().at(0)->appears(enemy);
                break;
            case RIGHT:
                itsLevel->getItsSpawnerList().at(1)->appears(enemy);
                break;
            }
            itsLevel->appears(enemy);
            itsEllapsedTime = 0;
        }




//    system("clear");
    checkAllCollid();
//    //std::cout<<"Est sur une platforme : "<<itsPlayer->getIsOnTheGround()<<"\n";
    moveAll();
    itsHMI->refreshAll();
//    qint64 elapsed = timer.nsecsElapsed(); // Temps écoulé en nanosecondes
//    //std::cout << "Temps écoulé:" << elapsed << "nanosecondes";
}

void Game::checkAllCollid(){
    // player to block
    bool playerGravity = true;

    // qWarning() << "player to block";
    for (Block * block : itsLevel->getItsBlockList()){
        //        //std::cout<<"Le x de e2 : "<<itsPlayer->getItsX()<<" / le x + width de e1 : "<<block->getItsX() + block->getItsWidth()<<" / soit la condition : "<<(itsPlayer->getItsX() > (block->getItsX() + block->getItsWidth()))<<"\n";
        if(collid(itsPlayer, block) == true){
            displayCoord(itsPlayer, block);
            colBtwPlayerAndBlock(itsPlayer, block);
            if (isOnTop(itsPlayer, block)){
                playerGravity = false;
            }
        }
    }

    /*    for(unsigned int i = 0; i < itsLevel->getItsBlockList().size(); i++){
    //        Block * block = itsLevel->getItsBlockList().at(i);
    //        if(collid(itsPlayer, block)){
    //            qWarning() << "collid";
    //            colBtwPlayerAndBlock(itsPlayer, block);
    //            if (isOnTop(itsPlayer, block)){
    //                playerGravity = false;
    //            }
    //        }
    //    }
    */

    if (playerGravity){
        itsPlayer->setItsYSpeed(GRAVITY);
    }
    else {
        itsPlayer->setItsYSpeed(STILL);
    }

    std::vector<Enemy *> enemyList = itsLevel->getItsEnemiesList();

    if (enemyList.size()>0){
        // player to enemy

        qWarning() << "player to enemy";
        for(Enemy * enemy : enemyList){
            if(collid(itsPlayer, enemy)){
                std::cout<<"collision entre player et ennemy\n";
                colBtwPlayerAndEnemy(itsPlayer, enemy);
            }
        }

        // enemy to block
        qWarning() << "enemy to block";
        for(Enemy * enemy : enemyList){
            bool enemyGravity = true;
            for (Block * block : itsLevel->getItsBlockList()){
                if (collid(enemy, block)){
                    colBtwEnemyAndBlock(enemy, block);
                    if (isOnTop(enemy, block)){
                        enemyGravity = false;
                    }
                }
            }
            if (enemyGravity){
                std::cout<<"La gravité est appliqué\n";
                enemy->setItsYSpeed(GRAVITY);
            }
            else{
                enemy->setItsYSpeed(STILL);
            }
        }

        // enemy to enemy
        qWarning() << "enemy to enemy";

//        if (enemyList.size() >= 2){
//            for (std::vector<Enemy *>::iterator it1 = enemyList.begin(); it1 < (enemyList.end()--); it1++){
//                qWarning() << "enemy1";
//                for (std::vector<Enemy *>::iterator it2 = it1++; it2 < enemyList.end(); it2++){
//                    qWarning() << "enemy2";
//                    Enemy * enemy1 = *it1;
//                    Enemy * enemy2 = *it2;
//                    if (collid(enemy1, enemy2)){
//                        colBtwEnemyAndEnemy(enemy1, enemy2);
//                    }
//                }
//            }
//        }

        // enemy et despawner
        qWarning() << "enemy to despawner";
        for (Enemy * enemy : enemyList){
            for (Despawner * despawner : itsLevel->getItsDespawnerList()){
                if(collid(enemy, despawner)){
                    std::cout<<"je passe par la méthode colbtwenemyanddespawner\n";
                    colBtwEnemyAndDespawner(enemy, despawner);
                }
            }
        }
    }
}

void Game::colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy)
{
    std::cout<<"je suis dans la fonction qui crash\n";
    if(theEnemy->getItsState())//quand l'ennemie n'est KO
    {
        thePlayer->setItsLivesNb(thePlayer->getItsLivesNb() - 1);
        thePlayer->setX((32*39)/2);
        thePlayer->setY(32);
        thePlayer->getItsRect()->moveTo((32*39)/2,32);
    }
    else//quand l'enemie est KO
    {
        itsScore += theEnemy->getItsType();
        itsLevel->removeEnemy(theEnemy);
    }
}

void Game::colBtwEnemyAndEnemy(Enemy* theFirstEnemy, Enemy* theSecondEnemy)
{
    if((theFirstEnemy->getItsXSpeed() < 0) != (theSecondEnemy->getItsXSpeed() < 0))//si les deux enemy sont dans des directions différentes
    {
        theFirstEnemy->setItsXSpeed(theFirstEnemy->getItsXSpeed()*(-1));
    }
    theSecondEnemy->setItsXSpeed(theSecondEnemy->getItsXSpeed()*(-1));
}

void Game::colBtwEnemyAndBlock(Enemy* theEnemy, Block* theBlock)
{
    theEnemy->setItsYSpeed(STILL);
    if(theBlock->getItsState())
    {
        theEnemy->setItsState(false);
    }
    theEnemy->setIsOnTheGround(true);
}

void Game::colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock)
{
    if(thePlayer->getItsRect()->top() == theBlock->getItsRect()->bottom() && thePlayer->getItsYSpeed() < STILL)
    {
        thePlayer->setItsYSpeed(thePlayer->getItsYSpeed() * (-1));//à remplacer par STILL pour l'instant inverse le vitesse
        theBlock->setItsState(true);
    }
    if(thePlayer->getItsRect()->bottom() == theBlock->getItsRect()->top())//le joueur est sur un block
    {
        thePlayer->setItsYSpeed(STILL);
        thePlayer->setIsOnTheGround(true);
    }

    if((thePlayer->getItsRect()->top() < theBlock->getItsRect()->bottom()) && (thePlayer->getItsRect()->bottom() > theBlock->getItsRect()->top())){
        if((thePlayer->getItsRect()->right() == theBlock->getItsRect()->left()))
        {
            thePlayer->setItsXSpeed(thePlayer->getItsXSpeed() > 0?0:thePlayer->getItsXSpeed());
        }
        else if((thePlayer->getItsRect()->left() == theBlock->getItsRect()->right()))
        {
            thePlayer->setItsXSpeed(thePlayer->getItsXSpeed() < 0?0:thePlayer->getItsXSpeed());
        }
    }
}

void Game::colBtwEnemyAndDespawner(Enemy* theEnemy, Despawner* theDespawner)
{
    theDespawner->disappear(theEnemy);
}

bool Game::isOnTop(Entity * entity, Block * block){
    return entity->getItsY() + entity->getItsHeight() <= block->getItsY();
}

bool Game::collid(Entity * entity1, Entity * entity2){

    //std::cout<<"La height du player = "<<entity1->getItsHeight()<<"\n";
    //std::cout<<"La width du player = "<<entity1->getItsWidth()<<"\n";
    //std::cout<<"Le Y du player : "<<entity1->getItsY()<<"\n";
    //std::cout<<"Le X du player : "<<entity1->getItsX()<<"\n";

    //std::cout<<"Est trop à droite : "<<(entity1->getItsX() > (entity2->getItsX() + entity2->getItsWidth()))<<"\n";
        //std::cout<<"Car le coté d de pl : "<<entity1->getItsX()<<" est plus grand que le coté g de bl : "<<(entity2->getItsX() + entity2->getItsWidth())<<"\n";
    if(entity1->getItsX() > (entity2->getItsX() + entity2->getItsWidth())){      // trop à droite
        // qWarning() << "trop à droite";
        //std::cout<<"Trop à droite\n";
            return false;
    }
    //std::cout<<"Est trop à gauche : "<<((entity1->getItsX() + entity1->getItsWidth()) < entity2->getItsX())<<"\n";
        if((entity1->getItsX() + entity1->getItsWidth()) < entity2->getItsX()){ // trop à gauche
        // qWarning() << "trop à gauche";
        //std::cout<<"Trop à gauche\n";
            return false;
    }
    //std::cout<<"Est trop en bas : "<<(entity1->getItsY() > (entity2->getItsY() + entity2->getItsHeight()))<<"\n";
    if(entity1->getItsY() > (entity2->getItsY() + entity2->getItsHeight())){ // trop en bas
        // qWarning() << "trop en bas";
        //std::cout<<"Trop en bas\n";
        return false;
    }

    //std::cout<<"Le Y + H de player : "<<(entity1->getItsY() + entity1->getItsHeight())<<" / le Y du block : "<<entity2->getItsY()<<" / soit la condition : "<<((entity1->getItsY() + entity1->getItsHeight()) > entity2->getItsY())<<"\n";
    if((entity1->getItsY() + entity1->getItsHeight()) < entity2->getItsY()){  // trop en haut
        // qWarning() << "trop en haut";
        //        //std::cout<<"La height du player = "<<entity1->getItsHeight()<<"\n";
        //        //std::cout<<"La width du player = "<<entity1->getItsWidth()<<"\n";
        //        //std::cout<<"Le Y du player : "<<entity1->getItsY()<<"\n";
        //std::cout<<"Trop en haut\n";
        return false;
    }
    //std::cout<<"En collision\n";
    return true;
}


void Game::moveAll(){
    itsPlayer->move();
    for (Enemy * enemy : itsLevel->getItsEnemiesList()){
        enemy->move();
    }
}

void Game::onLeftKeyPressed()
{
    itsPlayer->setItsXSpeed(-PLAYERMAXSPEED);
}

void Game::onRightKeyPressed()
{
    itsPlayer->setItsXSpeed(PLAYERMAXSPEED);
    //std::cout<<"appuie du right : "<<itsPlayer->getItsXSpeed()<<"\n";
}

void Game::onUpKeyPressed()
{
    if(itsPlayer->getIsOnTheGround())itsPlayer->setItsYSpeed(-PLAYERMAXSPEED);
}

void Game::onLeftKeyReleased()
{
    itsPlayer->setItsXSpeed(STILL);
}

void Game::onRightKeyReleased()
{
    itsPlayer->setItsXSpeed(STILL);
}

void Game::onGamePaused()
{
    isInPause = true;
}

void Game::onGameResumed()
{
    isInPause = false;
}
