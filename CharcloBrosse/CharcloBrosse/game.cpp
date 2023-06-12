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
    itsPlayer = new Player((32*39)/2, 250, 64, 32, itsTileSet->getItsPlayerTile());
    //Dénition et création du niveau pour la partie, LEVEL_FILE_PATH = le chemin vers le fichier .json du niveau
    itsLevel = new Level(LEVEL_FILE_PATH,itsTileSet);
    //Création de l'interface homme machine lié au jeu
    itsHMI = new HMI(itsLevel, itsPlayer, this);
    //Definition de la variable du temps écoulé pour l'appartion des ennemies
    itsEllapsedTime = 0;
    //Affichage du jeu
    itsHMI->show();
    //Définition de la variable qui compte le nombre de fois ou la game loop s'execute, sert à coordonner les vitesses (definie à NUMBER_LOOP_PER_SECOND)
    itsLoopCounter = NUMBER_LOOP_PER_SECOND;
}

void Game::onGameStart(){
    //Active le niveau, donne l'autorisation d'être affiché (permet de ne pas afficher le
    //niveau quand une interface autre est ouverte)
    itsLevel->activate();
    //Permet de rafraichir l'interface homme machine avec les nouvelles valeurs
    itsHMI->refreshAll();
    //Definition de la variable du temps écoulé pour l'appartion des ennemies à 0
    itsEllapsedTime = 0;
    //Lancement de la fonction GameLoop
    gameLoop();
}

void Game::gameLoop()
{
    //Définition du compteur qui sert à compter le temps écoulé
    //lors de l'excution de la fonction GameLoop
    QElapsedTimer timer;
    //Lancement du compteur
    timer.restart();
    //Condition qui vérifie que : le compteur du nombre de fois que la gameloop est executé
    //est à 0 si oui la remet à NUMBER_LOOP_PER_SECOND sinon ne fait rien
    if(itsLoopCounter == 0)itsLoopCounter = NUMBER_LOOP_PER_SECOND;
    //Incrémente de 0.001 le temps écoulé
    itsEllapsedTime += 0.001;
    //Condition qui verifie que : il reste des ennemies à faire apparaitre dans la file d'attente
    if (itsLevel->getItsRemainingEnemies().size() > 0){
        //
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
    //Fonction lancé pour la vérification des collisions entre toutes les entitées
    checkAllCollid();
    //Fonction lancé pour faire bouger selon les nouvelles vitesse les entitées
    moveAll();
    //Condition qui vérifie que : la division du nombre de tours de la gameloop
    //divisé par le nombre de tours de boucle faite par secondes lui même divisé
    //par le nombre de FPS souhaité, est égal à 0. Soit la condition vrai "nombre de FPS" par secondes
    if(itsLoopCounter % (NUMBER_LOOP_PER_SECOND/FPS) == 0)itsHMI->refreshAll();
    //Decrémente le nombre de tours de loop pour pour le cycle suivant
    itsLoopCounter--;
    //Condition qui vérifie que : il ne reste plus d'ennemies ni en jeu ni en list d'attente, ou alors que le joueur n'a plus de vies
    if((itsLevel->getItsEnemiesList().empty() && itsLevel->getItsRemainingEnemies().empty()) || itsPlayer->getItsLivesNb() == 0)
    {
        //Fonction de HMI qui stop le jeu et lance l'écran de fin
        itsHMI->stopGame();
    }
    //création et initialisation d'une varible avec le nombre de temps écoulé depuis le lancement du chronomètre
    unsigned int elapsedTime = timer.nsecsElapsed();
    //Affichage du temps d'execution dans la console en moyen 10µs
    qWarning() << "Game loop execution time in nanoseconds : " << elapsedTime;
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

void Game::checkAllCollid(){
    //Définie si la gravité doit être appliqué de base.
    //oui si le joueur n'a pas un saut en cours d'execution non sinon.
    bool playerGravity = (itsPlayer->getItsRemaningJumpMove() == 0);
    //définie le joueur comme n'étant pas sur un bloc
    itsPlayer->setIsOnTheGround(false);
    //parcours la liste des blocs du niveau en définissant une variable
    for (Block * block : itsLevel->getItsBlockList()){
        //Condition qui vérifie que : le bloc spécifié est un bloc de type "BRICK"
        if(block->getItsType() == BRICK){
            //Condition qui vérifie que : le compteur du bloc (compte le temps restant depuis le dernier touché)
            //Si OUI :
            if(block->getItsCounter() != 0)
            {
                //Decremente le compteur du temps restant depuis le deernier touché
                block->setItsCounter(block->getItsCounter() - 1);
                //Met le sprite du Block avec le sprite de la brique touché
                block->setItsSprite(itsTileSet->getItsBlockHitTile());
            }
            //Si NON :
            else
            {
                //Met l'état du bloc à faux (non touché)
                block->setItsState(false);
                //Met le sprite du Block avec le sprite de la brique non touché
                block->setItsSprite(itsTileSet->getItsBlockTile());
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
    //Condition qui vérifie que : le joueur doit être soumis à la gravité
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
    //Crée un Vecteur avec tous les ennemies présent dans le niveau
    std::vector<Enemy *> enemyList = itsLevel->getItsEnemiesList();
    //Condition qui vérifie que : il y à au moins une enemie dans le niveau
    if (enemyList.size()>0){
        //Crée un tableau d'une taille égale au nombre d'ennemies dans le niveau.
        //cette varibale est un boolean qui défini si oui ou non l'ennemie doit être soumis à la gravité
        bool gravityList[enemyList.size()];
        //crée une variable qui incrémente de 1 jusqu'à un nombre égale au nombres d'ennemies
        for (unsigned short i = 0; i < enemyList.size(); i++){
            //dans le tableau crée en amont, à l'élément du même numéro que la variable
            //du dessus definie a vrai l'élémément soit : applique la gravité
            gravityList[i] = true;
        }
        //crée une variable qui incrémente de 1 jusqu'à un nombre égale au nombres d'ennemies
        for (unsigned short i1 = 0; i1 < enemyList.size(); i1++){
            //crée une variable de type pointeur vers un ennemie qui prend l'ennemie
            //à l'emplacement égale  à la variable du dessus
            Enemy * enemy1 = enemyList.at(i1);
            //Condition qui vérifie que : une collision à lieu entre le joueur et l'ennemie
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
    itsPlayer->setItsNextMove(LEFT_X);
}

void Game::onRightKeyPressed()
{
    itsPlayer->setItsNextMove(RIGHT_X);
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
    itsPlayer->setItsNextMove(NONE);
}

void Game::onRightKeyReleased()
{
    itsPlayer->setItsNextMove(NONE);
}

void Game::onGamePaused()
{
    isInPause = true;
}

void Game::onGameResumed()
{
    isInPause = false;
}
