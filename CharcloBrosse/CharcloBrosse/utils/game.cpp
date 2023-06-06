
#include "game.h"
#include "typedef.h"
Game::Game()
{

}
//bool isCollision(Entity* theFirstEntity, Spawner* theSpawner)
//{

//}
void Game::gameLoop()
{

}
void Game::colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy)
{
    if(theEnemy->getItsState())//qaund l'ennemie est KO
    {
        thePlayer->setItsLivesNumber(thePlayer->getItsLivesNumber() - 1);
        thePlayer->getItsRect()->moveTo(12,12);
    }
    else//quand l'enemie est KO
    {
        itsScore =+ theEnemy->getItsType();
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
}

void Game::checkAllCollid()
{
    /* Les collisions à check
     * P to E
     * //P to P
     * E to E
     * E to B
     * P to B
     * E to S
     * P to M
     */
    /*
     * Si une collision à lieu entre le joueur et un enemies :
     * lance une fonction colbtwplayerandenemy
     */
    for(size_t it = 0; it < itsLevel->getItsEnemiesList().size(); ++it){
        Enemy* theEnemy = itsLevel->getItsEnemiesList().at(it);
        if(itsPlayer->getItsRect().intersects(theEnemy->getItsRect()))//Check collid between Player and the ennemy number = it in the vector at the level
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
            if(theFirstEnemy->getItsRect().intersects(theSecondEnemy->getItsRect()))// si une collision a lieux
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
            if(theEnemy->getItsRect().intersects(theBlock->getItsRect()))//Check collid between Enemy and blocks
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
        if(theEnemy->getItsRect().intersects(theBlock->getItsRect()))//Check collid between Enemy and blocks
        {
            colBtwEnemyAndBlock(theEnemy, theBlock);
        }
    }

}
void Game::isLevelFinished()
{
    return;
}
void Game::moveAll()
{

}


