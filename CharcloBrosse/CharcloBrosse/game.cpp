#include <chrono>
#include "game.h"
#include "typedef.h"

Game::Game()
{

    itsTileSet = new TileSet("tilesettest.png");
    itsPlayer = new Player(0, 0, 32, 32, itsTileSet->getItsPlayerTile());
    itsLevel = new Level("level1.json",itsTileSet);
    itsHMI = new HMI(itsLevel, itsPlayer);
    HMI::connect(itsHMI, &HMI::leftKeyPressed, this, &Game::onLeftKeyPressed);
    HMI::connect(itsHMI, &HMI::rightKeyPressed, this, &Game::onRightKeyPressed);
    HMI::connect(itsHMI, &HMI::upKeyPressed, this, &Game::onUpKeyPressed);
    HMI::connect(itsHMI, &HMI::leftKeyReleased, this, &Game::onLeftKeyReleased);
    HMI::connect(itsHMI, &HMI::rightKeyReleased, this, &Game::onRightKeyReleased);
    HMI::connect(itsHMI, &HMI::gamePaused, this, &Game::onGamePaused);
    HMI::connect(itsHMI, &HMI::gameResumed, this, &Game::onGameResumed);
    itsHMI->show();
}
// Connexion des signaux et slots

void Game::gameLoop()
{
    bool first = true;
    double ellapsedTime = 0;
    auto end = std::chrono::high_resolution_clock::now();

    do{

        auto begin = std::chrono::high_resolution_clock::now();
        std::chrono::duration time = end - begin;
        long ms = std::chrono::duration_cast<std::chrono::milliseconds> (time).count();
        if (ms >= 10 or first){
            if(itsLevel->getItsEnemyAppearsTimes().at(0) == ellapsedTime){
                Enemy * enemy = itsLevel->getItsEnemiesList().at(0);
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
                ellapsedTime = 0;
            }
            moveAll();
            gravity();
            checkAllCollid();
            itsHMI->refreshAll();
            ellapsedTime+= 0.10;
        }
        if (first){
            first = false;
        }
    }while(!isLevelFinished() && itsPlayer->getItsLivesNb()!=0);
}

void Game::colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy)
{
    if(theEnemy->getItsState())//quand l'ennemie est KO
    {
        thePlayer->setItsLivesNb(thePlayer->getItsLivesNb() - 1);
        thePlayer->getItsRect()->moveTo(12,12);
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
    theEnemy->setItsYSpeed(0);//à remplacer le 0 par STILL
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
    if((thePlayer->getItsRect()->left() == theBlock->getItsRect()->right()) || (thePlayer->getItsRect()->right() == theBlock->getItsRect()->left()))
    {
        thePlayer->setItsXSpeed(STILL);
    }
}

void Game::colBtwEnemyAndDespawner(Enemy* theEnemy, Despawner* theDespawner)
{
    theDespawner->disappear(theEnemy);
}
void Game::gravity()
{
    itsPlayer->setItsYSpeed(GRAVITY);
    for(size_t itEnemies = 0; itEnemies < itsLevel->getItsEnemiesList().size(); ++itEnemies)
    {
        Enemy* theEnemy = itsLevel->getItsEnemiesList().at(itEnemies);
        theEnemy->setItsYSpeed(GRAVITY);
    }
}

/**
 * @brief Game::checkAllCollid
 */
void Game::checkAllCollid()
{
    /*
     * Si une collision à lieu entre le joueur et un enemies :
     * lance une fonction colbtwplayerandenemy
     */
    for(size_t it = 0; it < itsLevel->getItsEnemiesList().size(); ++it){
        Enemy* theEnemy = itsLevel->getItsEnemiesList().at(it);
        if(itsPlayer->getItsRect()->intersects(*theEnemy->getItsRect()))//Check collid between Player and the ennemy number = it in the vector at the level
        {
            colBtwPlayerAndEnemy(itsPlayer,theEnemy);
        }
    }
    /*
     * Si une collision à lieu entre deux enemy :
     * lance une fonction colBtwEnemyAndEnemy
     */
    for (size_t i = 0; i < itsLevel->getItsEnemiesList().size() - 1; i++) {
        for (size_t j = i + 1; j < itsLevel->getItsEnemiesList().size(); j++) {
            Enemy *theFirstEnemy = itsLevel->getItsEnemiesList().at(i), *theSecondEnemy = itsLevel->getItsEnemiesList().at(j);
            if(theFirstEnemy->getItsRect()->intersects(*theSecondEnemy->getItsRect()))// si une collision a lieux
            {
                colBtwEnemyAndEnemy(theFirstEnemy, theSecondEnemy);
            }
        }
    }
    /*
     * Si une collision à lieu entre un enemy et un block :
     * Lance une fonction colBtwEnemyAndBlock
     */
    for(size_t itEnemies = 0; itEnemies < itsLevel->getItsEnemiesList().size(); ++itEnemies)
    {
        Enemy* theEnemy = itsLevel->getItsEnemiesList().at(itEnemies);
        for(size_t itBlocks = 0; itBlocks < itsLevel->getItsBlockList().size(); ++itBlocks)
        {
            Block* theBlock = itsLevel->getItsBlockList().at(itBlocks);
            if(theEnemy->getItsRect()->intersects(*theBlock->getItsRect()))//Check collid between Enemy and blocks
            {
                colBtwEnemyAndBlock(theEnemy, theBlock);
            }
        }
    }
    /*
     * Si une collision à lieu entre un joueur et un block :
     * Lance une fonction colBtwPlayerAndBlock
     */
    for(size_t itBlocks = 0; itBlocks < itsLevel->getItsBlockList().size(); ++itBlocks)
    {
        Block* theBlock = itsLevel->getItsBlockList().at(itBlocks);
        if(itsPlayer->getItsRect()->intersects(*theBlock->getItsRect()))//Check collid between Enemy and blocks
        {
            colBtwPlayerAndBlock(itsPlayer, theBlock);
        }
    }
    /*
     * Si une collision à lieu entre un enemy et un despawner :
     * Lance une fonction colBtwEnemyAndDespawner
     */
    for(size_t itEnemies = 0; itEnemies < itsLevel->getItsEnemiesList().size(); ++itEnemies)
    {
        Enemy* theEnemy = itsLevel->getItsEnemiesList().at(itEnemies);
        for(size_t itSpawner = 0; itSpawner < itsLevel->getItsDespawnerList().size(); ++itSpawner)
        {
            Despawner* theDespawner = itsLevel->getItsDespawnerList().at(itEnemies);

            if(theEnemy->getItsRect()->intersects(*theDespawner->getItsRect()))//Check collid between Enemy and blocks
            {
                colBtwEnemyAndDespawner(theEnemy, theDespawner);
            }
        }
    }
}

bool Game::isLevelFinished()
{
    if (itsLevel->getItsEnemiesList().empty() || itsPlayer->getItsLivesNb() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::moveAll()
{
    if(itsPlayer->getIsOnTheGround())
    {
        itsPlayer->move();
    }
    for(size_t itEnemies = 0; itEnemies < itsLevel->getItsEnemiesList().size(); ++itEnemies)
    {
        Enemy* theEnemy = itsLevel->getItsEnemiesList().at(itEnemies);
        if(theEnemy->getIsOnTheGround())theEnemy->move();
    }
}

void Game::onLeftKeyPressed()
{
    itsPlayer->setItsXSpeed(-PLAYERMAXSPEED);
}

void Game::onRightKeyPressed()
{
    itsPlayer->setItsXSpeed(PLAYERMAXSPEED);
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

bool isInPause = false;
void Game::onGamePaused()
{
    isInPause = true;
    while(isInPause);
}

void Game::onGameResumed()
{
    isInPause = false;
}
