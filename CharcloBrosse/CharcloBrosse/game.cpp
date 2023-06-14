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
    //Définition du tileset pour la partie en cours, TILESET_FILE_PATH = le chemin vers le fichier .png du tileset
    itsTileSet = new TileSet(TILESET_FILE_PATH);
    //Création du joueur pour la partie en cours
    itsPlayer = new Player((32*39)/2, 250, 64, 32, itsTileSet->getItsPlayerTilesList(),&itsLoopCounter);
    //Dénition et création du niveau pour la partie, LEVEL_FILE_PATH = le chemin vers le fichier .json du niveau
    itsLevel = nullptr;
    //Création de l'interface homme machine lié au jeu
    itsHMI = new HMI(itsLevel, itsPlayer, this);
    //Definition de la variable du temps écoulé pour l'appartion des ennemies
    itsEllapsedTime = 0;
    //Affichage du jeu
    itsHMI->show();
    //Définition de la variable qui compte le nombre de fois ou la game loop s'execute, sert à coordonner les vitesses (definie à NUMBER_LOOP_PER_SECOND)
    itsLoopCounter = NUMBER_LOOP_PER_SECOND;
    running = false;
    isBlockPOWHitted = false;

}

void Game::onGameStart(){
    currentLevel = 1;
    itsTileSet = new TileSet(TILESET_FILE_PATH);
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
    checkTier();
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
                    itsTileSet = new TileSet(":/ressources/tileset0.png");
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
    //retourne le score de la partie
    return itsScore;
}

Player *Game::getItsPlayer() const
{
    //retourne le pointeur vers le joueur du jeu
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

TileSet *Game::getItsTileSet() const
{
    return itsTileSet;
}

QString Game::getCheminBG() const
{
    return cheminBG;
}

short Game::getCurrentTier() const
{
    return currentTier;
}

void Game::checkAllCollid(){
    //Définie si la gravité doit être appliqué de base.
    //oui si le joueur n'a pas un saut en cours d'execution non sinon.

    //isBlockPOWHitted = false; // A retirer une fois le bloc pow immplémenter
    // player to block

    bool playerGravity = (itsPlayer->getItsRemaningJumpMove() == 0);
    //définie le joueur comme n'étant pas sur un bloc
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
                //Decremente le compteur du temps restant depuis le dernier touché
                block->setItsCounter(block->getItsCounter() - 1);
            }
            //Si NON :
            else
            {
                //Met l'état du bloc à faux (non touché)
                block->setItsState(false);
            }
        }
        //Condition qui vérifie que : une collision à lieu entre le joueur et le bloc
        if(collid(itsPlayer, block) == true){
            //Execute la fonction qui gère la collision
            colBtwPlayerAndBlock(itsPlayer, block);
            //Condition qui vérifie que : le joueur est sur le bloc
            if (isOnTop(itsPlayer, block)){
                //Change la varible qui définie si oui ou non le joueur doit subir la gravité
                playerGravity = false;
                //Définie l'attribut boolean du joueur à vrai, cet attribut est
                //vrai si il est sur une surface faux si il est dans le vide
                itsPlayer->setIsOnTheGround(true);
            }
        }
    }
    //------------------------------Fin de la vérification des collisions avec les blocks -------------------------------------------------------

    //------------------------------Début de la vérification des entre joueur et money -------------------------------------------------------
    for (Money * money : itsLevel->getItsMoneyList())
    {
        if(collid(itsPlayer,money))
        {
            colBtwPlayerAndMoney(itsPlayer,money);
        }
    }
    //------------------------------Fin de la vérification des collisions entre joueur et money -------------------------------------------------------

    //------------------------------Début de l'application de la gravitée ou pas pour le joueur -------------------------------------------------------
    if (playerGravity)
    {
        //Définie la vitesse du joueur sur l'axe des absices à 1
        itsPlayer->setItsYSpeed(GRAVITY);
    }
    else
    {
        //Définie la vitesse du joueur sur l'axe des absices à 0 si sa vitesse est positif
        //et ne la change pas si elle est négatif
        itsPlayer->setItsYSpeed(itsPlayer->getItsYSpeed() > STILL?STILL:itsPlayer->getItsYSpeed());
    }
    //------------------------------Fin de l'application de la gravitée ou pas pour le joueur -------------------------------------------------------

    //------------------------------Début de la vérification des collisions avec les ennemies -------------------------------------------------------
    //Crée un Vecteur avec tous les ennemies présent dans le niveau
    std::vector<Enemy *> enemyList = itsLevel->getItsEnemiesList();
    //Condition qui vérifie que : il y à au moins une enemie dans le niveau
    if (enemyList.size()>0)
    {
        //------------------------------Début de l'application de la gravité pour les ennemies -------------------------------------------------------
        //Crée un tableau d'une taille égale au nombre d'ennemies dans le niveau.
        //cette varibale est un boolean qui défini si oui ou non l'ennemie doit être soumis à la gravité
        bool gravityList[enemyList.size()];
        //crée une variable qui incrémente de 1 jusqu'à un nombre égale au nombres d'ennemies
        for (unsigned short i = 0; i < enemyList.size(); i++)
        {
            //dans le tableau crée en amont, à l'élément du même numéro que la variable
            //du dessus definie a vrai l'élémément soit : applique la gravité
            gravityList[i] = true;
        }
        //------------------------------Fin de l'application de la gravité pour les ennemies -------------------------------------------------------

        //------------------------------Parcours tous les ennemies pour vérifier les collisions avec : block, ennemies, player, despawner -----------
        //crée une variable qui incrémente de 1 jusqu'à un nombre égale au nombres d'ennemies
        for (unsigned short i1 = 0; i1 < enemyList.size(); i1++)
        {
            //crée une variable de type pointeur vers un ennemie qui prend l'ennemie
            //à l'emplacement égale  à la variable du dessus
            Enemy * enemy1 = enemyList.at(i1);
            //Condition qui vérifie que : une collision à lieu entre le joueur et l'ennemie
            //------------------------------Début de la vérification des collisions entre joueur et ennemie -------------------------------------------------------
            if (collid(itsPlayer, enemy1))
            {
                colBtwPlayerAndEnemy(itsPlayer, enemy1);
            }
            //------------------------------Fin de la vérification des collisions entre joueur et ennemie -------------------------------------------------------

            //------------------------------Début de la vérification des collisions entre despawner et ennemie -------------------------------------------------------
            for (Despawner * despawner : itsLevel->getItsDespawnerList())
            {
                if(collid(enemy1, despawner))
                {
                    colBtwEnemyAndDespawner(enemy1, despawner);
                }
            }
            //------------------------------Fin de la vérification des collisions entre despawner et ennemie -------------------------------------------------------

            //------------------------------Début de la vérification des collisions entre block et ennemie -------------------------------------------------------
            for (Block * block : itsLevel->getItsBlockList())
            {
                if (block->getItsType() != OBSTACLE && collid(enemy1, block))
                {
                    if (isOnTop(enemy1, block))
                    {
                        gravityList[i1] = false;
                    }
                    colBtwEnemyAndBlock(enemy1, block);
                }
            }
            //------------------------------Fin de la vérification des collisions entre block et ennemie -------------------------------------------------------

            if (enemyList.size() > 1)//Si il y a plusieurs ennemies dans le niveau en cours
            {
                for (unsigned int i2 = i1+1; i2 < enemyList.size(); i2++)//Selectionne l'ennemies situé à l'emplacement suivant dans la list
                {
                    Enemy * enemy2 = enemyList.at(i2);//Création d'un pointeur vers le dexième ennemie donc on à ici toujours deux ennemies différent : enemy1 et enemy2

                        //Sécurité qui permet en cas de détection d'un chevauchement d'ennemies d'en faire respawn 1 au spawner et donc de casser le bug
//                        if(enemy1->getItsRect()->intersected(*enemy2->getItsRect()).height() > 1 && enemy1->getItsRect()->intersected(*enemy2->getItsRect()).width() > 1)
//                        {
//                            qWarning()<<"two entities are inside each other";
//                            itsLevel->getItsDespawnerList().at(0)->disappear(enemy2);
//                        }
                        /*else*/ if (collid(enemy1, enemy2))
                        {
                            colBtwEnemyAndEnemy(enemy1, enemy2);
                            if (isOnTop(enemy1, enemy2))
                            {
                                gravityList[i1] = false;
                            }
                            else if (isOnTop(enemy2, enemy1))
                            {
                                gravityList[i2] = false;
                            }
                        }

                }
            }

            /*
            if (enemyList.size() >= 2 &&  (itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(STANDARD_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                for (unsigned int i2 = i1+1; i2 < enemyList.size(); i2++)
                {
                    Enemy * enemy2 = enemyList.at(i2);
                    if(enemy1->getItsRect()->intersected(*enemy2->getItsRect()).height() > 1 && enemy1->getItsRect()->intersected(*enemy2->getItsRect()).width() > 1)
                    {
                        qWarning()<<"two entities are inside each other";
                        itsLevel->getItsDespawnerList().at(0)->disappear(enemy2);
                    }
                    else if (collid(enemy1, enemy2))
                    {
                        colBtwEnemyAndEnemy(enemy1, enemy2);
                        if (isOnTop(enemy1, enemy2))
                        {
                            gravityList[i1] = false;
                        }
                        else if (isOnTop(enemy2, enemy1))
                        {
                            gravityList[i2] = false;
                        }
                    }
                }
            }
            */

            //------------------------------Début de l'application de la gravité en fonction des vérification efféctué--------------------------------
            if (gravityList[i1])
            {
                enemy1->setItsYSpeed(GRAVITY);
            }
            else
            {
                enemy1->setItsYSpeed(STILL);
            }
            //------------------------------Fin de l'application de la gravité en fonction des vérification efféctué--------------------------------

            if(enemy1->getItsNumberLoopKO() != 0)
            {
                enemy1->setItsNumberLoopKO(enemy1->getItsNumberLoopKO()-1);
            }
            else
            {
                switch (enemy1->getItsType())
                {
                case STANDARD:
                    enemy1->setItsState(true);
                    break;
                case GIANT:
                    enemy1->setItsState(true);
                    break;
                case ACCELERATOR:
                    enemy1->setItsState(true);
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
        int multiplier = tier; // Le multiplicateur est 1 plus 3 fois le tier. Si tier est 0, le multiplicateur est 1.
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
                // La loop de durée de KO est stopppé
                enemy->setItsNumberLoopKO(0);
            }
        }
    }
}

void Game::colBtwEnemyAndEnemy(Enemy* theFirstEnemy, Enemy* theSecondEnemy)
{
    if (!isOnTop(theFirstEnemy, theSecondEnemy) && !isOnTop(theSecondEnemy, theFirstEnemy)){
//        if((theFirstEnemy->getItsXSpeed() < 0) != (theSecondEnemy->getItsXSpeed() < 0))//si les deux enemy sont dans des directions différentes
//        {
//            theFirstEnemy->setItsXSpeed(theFirstEnemy->getItsXSpeed()*(-1));
//        }
//        theSecondEnemy->setItsXSpeed(theSecondEnemy->getItsXSpeed()*(-1));

        if(theFirstEnemy->getItsRect()->left() <= theSecondEnemy->getItsRect()->right() && theFirstEnemy->getItsRect()->left() + 16 >= theSecondEnemy->getItsRect()->right())
        {
            if((theFirstEnemy->getItsXSpeed() < 0) != (theSecondEnemy->getItsXSpeed() < 0))
            {
            theFirstEnemy->setItsXSpeed(RIGHT_X);
            }
            theSecondEnemy->setItsXSpeed(LEFT_X);
        }
        else if(theFirstEnemy->getItsRect()->right() <= theSecondEnemy->getItsRect()->left() && theFirstEnemy->getItsRect()->right() + 16 >= theSecondEnemy->getItsRect()->left())
        {
            if((theFirstEnemy->getItsXSpeed() < 0) != (theSecondEnemy->getItsXSpeed() < 0))
            {
            theSecondEnemy->setItsXSpeed(RIGHT_X);
            }
            theFirstEnemy->setItsXSpeed(LEFT_X);
        }
        else
        {
            qInfo() <<"enemy1-X = "<<theFirstEnemy->getItsRect()->x();
            qInfo() <<"enemy1-Y = "<<theFirstEnemy->getItsRect()->y();

            qInfo() <<"enemy2-X = "<<theSecondEnemy->getItsRect()->x();
            qInfo() <<"enemy2-Y = "<<theSecondEnemy->getItsRect()->y();

            qInfo() <<"enemy1-top = "<<theFirstEnemy->getItsRect()->top();
            qInfo() <<"enemy2-bottom= "<<theSecondEnemy->getItsRect()->bottom();
            qInfo() <<"T/F : "<<isOnTop(theSecondEnemy, theFirstEnemy);
//            qFatal()<<"collision impossible";
        }
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
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            case GIANT:
                theEnemy->setItsState(false);
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            case ACCELERATOR:
                theEnemy->setItsState(false);
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                dynamic_cast<Accelerator*>(theEnemy)->addItsSpeedState();
                break;
            default:
                break;
            }
        }
        else if(!theEnemy->getItsState() && theEnemy->getItsNumberLoopKO() < (KO_TIME * NUMBER_LOOP_PER_SECOND)-((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME)-1)//+1 car problème de précision
        {
            switch (theEnemy->getItsType())
            {
            case STANDARD:
                theEnemy->setItsState(true);
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            case GIANT:
                theEnemy->setItsState(true);
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            case ACCELERATOR:
                theEnemy->setItsState(true);
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
    return entity1->getItsRect()->bottom() == entity2->getItsRect()->top();
}

bool Game::collid(Entity * entity1, Entity * entity2)
//{

//    if(entity1->getItsX() > (entity2->getItsX() + entity2->getItsWidth())){      // trop à droite
//        return false;
//    }
//    else if((entity1->getItsX() + entity1->getItsWidth()) < entity2->getItsX()){ // trop à gauche
//        return false;
//    }
//    else if(entity1->getItsY() > (entity2->getItsY() + entity2->getItsHeight())){ // trop en bas
//        return false;
//    }

//    else if((entity1->getItsY() + entity1->getItsHeight()) < entity2->getItsY()){  // trop en haut
//        return false;
//    }
//    return true;
//}
{
    return (entity1->getItsRect()->intersects(*entity2->getItsRect()));
}

int Game::checkTier()
{
    if (itsMoney >= 100)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 5; // Quatrième palier
    }
    else if (itsMoney >= 50)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 4; // Troisième palier
    }
    else if (itsMoney >= 25)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 3; // Deuxième palier
    }
    else if (itsMoney >= 10)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 2; // Premier palier
    }
    else
    {
        cheminBG = BACKGROUND1_FILE_PATH;
        return 1; // Pas encore de palier atteint
    }
}




//void Game::updateAnimation(Entity *theEntity)
//{
//    dynamic_cast<Block*>(theEntity)->increment();
//}



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
    itsPlayer->setItsNextMove(LEFT_X);
}

void Game::onRightKeyPressed()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(RIGHT_X);
    itsPlayer->setItsNextMove(RIGHT_X);
}

void Game::onUpKeyPressed()
{
    if(itsPlayer->getIsOnTheGround()){
        itsPlayer->setItsYSpeed(-1);
        itsPlayer->setItsRemaningJumpMove(PLAYER_JUMP_HEIGHT*BLOCK_SIZE);
    }

//    if(itsPlayer->getIsOnTheGround()){
//        itsPlayer->setItsYSpeed(-5);
//        QElapsedTimer jumpTimer;
//        jumpTimer.start();
//        startJump = jumpTimer.elapsed();
//        if (jumpTimer.elapsed() <= (startJump+2))
//        {
//            itsPlayer->setItsYSpeed(-5);
//        }
//        itsPlayer->setItsYSpeed(5);
//        //itsPlayer->setItsRemaningJumpMove(PLAYER_JUMP_HEIGHT*BLOCK_SIZE);
//    }
}

void Game::onLeftKeyReleased()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(NONE);
    itsPlayer->setItsNextMove(NONE);
}

void Game::onRightKeyReleased()
{
    //    if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(NONE);
    itsPlayer->setItsNextMove(NONE);
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
