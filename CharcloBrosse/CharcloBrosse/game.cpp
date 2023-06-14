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
    //Création de l'interface homme machine lié au jeu
    itsHMI = new HMI(itsPlayer, this);
    //Definition de la variable du temps écoulé pour l'appartion des ennemies
    itsEllapsedTime = 0;
    //Affichage du jeu
    itsHMI->show();
    //Définition de la variable qui compte le nombre de fois ou la game loop s'execute, sert à coordonner les vitesses (definie à NUMBER_LOOP_PER_SECOND)
    itsLoopCounter = NUMBER_LOOP_PER_SECOND;
    running = false;
    //Est initialisé à false car pas frappé au commencement
    isBlockPOWHitted = false;

}

void Game::onGameStart(){
    //Niveau actuel
    currentLevel = 1;
    //Money
    itsMoney = 0;
    //Création du tileset
    itsTileSet = new TileSet(TILESET_FILE_PATH);
    //Initialisation du nombre de vies
    itsPlayer->setItsLivesNb(3);
    //Initialisation du nombre du score
    itsScore = 0;
    //Ouverture du niveau
    openLevel();
    //Initialisation de l'IHM avec le premier niveau
    itsHMI->setLevel(itsLevel);
    //Affichage du numéro du niveau
    itsHMI->displayLevelNumber();
    //Initialisation
    itsEllapsedTime = 0;
    checkTier();
    gameLoop();
    running = true;
}

void Game::gameLoop()
{
    if(running){
        //création du timer
        QElapsedTimer timer;
        //démarrage du time
        timer.restart();
        //Vrai si le compteur du nombre de loop arrive à zero
        if(itsLoopCounter == 0)itsLoopCounter = NUMBER_LOOP_PER_SECOND;
        //incrémentation du temps écoulé pour l'apparition des ennemies
        itsEllapsedTime += 0.001;
        //vrai si il reste des ennemies à faire apparraitre
        if (itsLevel->getItsRemainingEnemies().size() > 0){
            //Initialisation du pos
            unsigned short pos = itsLevel->getItsRemainingEnemies().size()-1;
            //vrai si il reste des ennemies à faire apparraitre et que le temps l'autorise
            if(!(itsLevel->getItsEnemyAppearsTimes().empty()) && itsEllapsedTime >= itsLevel->getItsEnemyAppearsTimes().at(pos))
            {
                //Initialisation d'un pointeur sur enemy
                Enemy * enemy = itsLevel->getItsRemainingEnemies().at(pos);
                //Initialisation d'une variable side
                Sides side = itsLevel->getItsEnemyAppearsSides().at(pos);
                //switch pour gérer les cas ou l'enemy doit apparraitre à gauche ou à droite
                switch(side){
                //cas ou il doit appparaitre a gauche
                case LEFT:
                    //Vas chercher l'enemy à faire apparraitre
                    itsLevel->getItsSpawnerList().at(0)->appears(enemy);
                    //Initialisation de sa direction
                    enemy->setItsXSpeed(RIGHT_X);
                    break;
                //cas ou il doit appparaitre a droite
                case RIGHT:
                    //Vas chercher l'enemy à faire apparraitre
                    itsLevel->getItsSpawnerList().at(1)->appears(enemy);
                    //Initialisation de sa direction
                    enemy->setItsXSpeed(LEFT_X);
                    break;
                }
                //Change de list l'enemy
                itsLevel->appears(enemy);
                //Redefinition du temps écoulé à 0
                itsEllapsedTime = 0;
            }
        }
        //Vérification des collisions
        checkAllCollid();
        //Met en mouvement les entités
        moveAll();
        //vrai si un refresh de l'ihm est autorisé, autorisé un nombre de fois égal au nombre de fps défini par secondes
        if(itsLoopCounter % (NUMBER_LOOP_PER_SECOND/FPS) == 0)itsHMI->refreshAll();
        //Décrémentation du nombre de boucle pour le cycle
        itsLoopCounter--;
        //Vrai si le niveau est finis
        if(isLevelFinished()){
            //Incrrémentation du score avec le temps restant
            itsScore += itsHMI->getTimerRemainingTime();
            //vrai si le niveau actuel n'est pas le niveau maximum
            if (currentLevel != MAX_LEVEL){
                //Vrai si le palier actuel est différent du palier auquel il doit être
                //Incrémentation du niveau actuel
                currentLevel++;

            }
            if (currentTier != checkTier()){
                // modification du pallier
                currentTier = checkTier();
                //Suppression du tileset actuel
                delete itsTileSet;
                //création du nouveau tileset
                itsTileSet = new TileSet(":/ressources/tileset0.png");
            }
            //ouverture du niveau
            openLevel();
            //Initialisation de l'IHM avec le premier niveau
            itsHMI->setLevel(itsLevel);
            //Affichage du numéro du niveau
            itsHMI->displayLevelNumber();
            //Réinitialisation du compteur du nombre de boucle dans le cycle
            itsLoopCounter = NUMBER_LOOP_PER_SECOND;
            //Réinitialisation du temps écoulé
            itsEllapsedTime = 0;
            openLevel();
            itsHMI->setLevel(itsLevel);
            itsHMI->displayLevelNumber();
            itsLoopCounter = NUMBER_LOOP_PER_SECOND;
            itsEllapsedTime = 0;
        }
        if(itsPlayer->getItsLivesNb() == 0)
        {
            //Définition du niveau actuel
            currentLevel = 1;
            //Arret du jeu car mort
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
    //Initialisation de sa vitesse sur l'axe Y à 0
    itsPlayer->setItsYSpeed(0);
    //Initialisation de sa vitesse sur l'axe X à 0
    itsPlayer->setItsXSpeed(0);
    //Initialisation de sa position sur l'axe X au centre
    itsPlayer->setX((32*39)/2);
    //Initialisation de sa position sur l'axe Y en bas
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
            colBtwPlayerAndMoney(money);
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
                    if (collid(enemy1, enemy2))
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
                case JUMPER:
                    enemy1->setItsState(true);
                    break;
                case FREEZER:
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
    //Vrai si l'enemy n'est pas KO
    if(theEnemy->getItsState())
    {
        //cette fonction fait exactement le même chose que ce qui doit être fait quand il touche un enemy pas KO
        colBtwPlayerAndObstacle(thePlayer);
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
    //Décrémente de 1 le nombre de vie du joueur
    thePlayer->setItsLivesNb(thePlayer->getItsLivesNb() - 1);
    //Initialisation de la position sur l'axe X au centre du niveau
    thePlayer->setX((BLOCK_SIZE*39)/2);
    //Initialisation de la position sur l'axe X en haut du niveau
    thePlayer->setY(0);
    //Initialisation de la position nouvelle position pour sa hitbox
    thePlayer->getItsRect()->moveTo((BLOCK_SIZE*39)/2,32);
    //Reinitialisation de son saut
    thePlayer->setItsRemaningJumpMove(0);
    //Reinitialisation de sa direction actuelle
    thePlayer->setItsCurrentMove(NONE);
    //Reinitialisation de sa direction suivante
    thePlayer->setItsNextMove(NONE);
}

// Fonction appelé dans la collision entre le joueur et le bloc POW
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
    //vrai si les enemies sont superposé
    if (!isOnTop(theFirstEnemy, theSecondEnemy) && !isOnTop(theSecondEnemy, theFirstEnemy)){
        //ennemie1 à droite et ennemie2 à gauche [E2][E1]
        if(theFirstEnemy->getItsRect()->left() <= theSecondEnemy->getItsRect()->right() && theFirstEnemy->getItsRect()->left() + 16 >= theSecondEnemy->getItsRect()->right())
        {
            //Vrai si les deux ennemies sont dans la même direction
            if(theFirstEnemy->getItsXSpeed() == theSecondEnemy->getItsXSpeed())
            {
                //vrai si la direction des deux ennemies est le droite
                if(theFirstEnemy->getItsXSpeed() == RIGHT_X)
                {
                    //Redefinie la direction de E1 vers la gauche car c'est E1 qui rattrape E2
                    theSecondEnemy->setItsXSpeed(LEFT_X);
                }
                else
                {
                    //Redefinie la direction E2 vers la droite car c'est E2 qui rattrape E1
                    theFirstEnemy->setItsXSpeed(RIGHT_X);
                }
            }
            else
            {
                //change la direction de E1 vers la droite
                theFirstEnemy->setItsXSpeed(RIGHT_X);
                //change la direction de E2 vers la gauche
                theSecondEnemy->setItsXSpeed(LEFT_X);
            }
        }//ennemie1 à droite et ennemie2 à gauche [E1][E2]
        else if(theFirstEnemy->getItsRect()->right() <= theSecondEnemy->getItsRect()->left() && theFirstEnemy->getItsRect()->right() + 16 >= theSecondEnemy->getItsRect()->left())
        {
            //Vrai si les deux ennemies sont dans la même direction
            if(theFirstEnemy->getItsXSpeed() == theSecondEnemy->getItsXSpeed())
            {
                //Vrai si les deux ennemies sont dans la même direction
                if(theFirstEnemy->getItsXSpeed() == RIGHT_X)
                {
                    //Redefinie la direction de E1 vers la gauche car c'est E1 qui rattrape E2
                    theFirstEnemy->setItsXSpeed(LEFT_X);
                }
                else
                {
                    //Redefinie la direction E2 vers la droite car c'est E2 qui rattrape E1
                    theSecondEnemy->setItsXSpeed(RIGHT_X);
                }
            }
            else
            {
                //change la direction de E1 vers la gauche
                theFirstEnemy->setItsXSpeed(LEFT_X);
                //change la direction de E2 vers la droite
                theSecondEnemy->setItsXSpeed(RIGHT_X);
            }
        }
        //Arette l'application si une collision étrange est detecté
        else qFatal("collision impossible");
    }
}

void Game::colBtwEnemyAndBlock(Enemy* theEnemy, Block* theBlock)
{
    //Redéfinie la vitesse de déplacement sur l'axe Y à "IMMOBILLE" soit 0
    theEnemy->setItsYSpeed(STILL);
    //Vrai si le block est touché
    if(theBlock->getItsState())
    {
        //Vrai si l'enemy est en vie et que le compteur du temps de mort de l'enemy est à 0
        if(theEnemy->getItsState() && theEnemy->getItsNumberLoopKO() == 0)
        {
            //Case pour chaque type d'ennemies
            switch (theEnemy->getItsType())
            {
            //cas ou l'enemy est un STANDARD
            case STANDARD:
                //met l'enemy KO
                theEnemy->setItsState(false);
                //Démarrage du compteur,pour le temps de mort
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            //cas ou l'enemy est un GIANT
            case GIANT:
                //met l'enemy KO
                theEnemy->setItsState(false);
                //Démarrage du compteur,pour le temps de mort
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            //cas ou l'enemy est un ACCELERATOR
            case ACCELERATOR:
                //met l'enemy KO
                theEnemy->setItsState(false);
                //Démarrage du compteur,pour le temps de mort
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                //Incrémente de 1 l'état de l'accelerator
                dynamic_cast<Accelerator*>(theEnemy)->addItsSpeedState();
                break;
            case JUMPER:
                theEnemy->setItsState(false);
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            case FREEZER:
                theEnemy->setItsState(false);
                theEnemy->setItsNumberLoopKO(KO_TIME * NUMBER_LOOP_PER_SECOND);
                break;
            default:
                break;
            }
        }
        //Vrai si l'enemy est KO et que sont compteur de temps de mort est inférieur au temps que met un block à revenir à son état normal
        else if(!theEnemy->getItsState() && theEnemy->getItsNumberLoopKO() < (KO_TIME * NUMBER_LOOP_PER_SECOND)-((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME)-1)//+1 car problème de précision
        {
            //Case pour chaque type d'ennemies
            switch (theEnemy->getItsType())
            {
            //cas ou l'enemy est un STANDARD
            case STANDARD:
                //met l'enemy en vie
                theEnemy->setItsState(true);
                //Définie son compteur de temps de mort à un temps légèrement superieur au temps que met un block à redevenir normal
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            //cas ou l'enemy est un GIANT
            case GIANT:
                //met l'enemy en vie
                theEnemy->setItsState(true);
                //Définie son compteur de temps de mort à un temps légèrement superieur au temps que met un block à redevenir normal
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            //cas ou l'enemy est un ACCELERATOR
            case ACCELERATOR:
                //met l'enemy en vie
                theEnemy->setItsState(true);
                //Définie son compteur de temps de mort à un temps légèrement superieur au temps que met un block à redevenir normal
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            case JUMPER:
                theEnemy->setItsState(true);
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            case FREEZER:
                theEnemy->setItsState(true);
                theEnemy->setItsNumberLoopKO(2+((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME));//+2 car problème de précision
                break;
            default:
                break;
            }
        }
    }
    //Définie l'attribue isontheground à true soit un attribut pour savoir si il est sur une surface
    theEnemy->setIsOnTheGround(true);
}

void Game::colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock)
{
    //vrai si le haut du joueur égale le bas du joueur et que le joueur est en pleine ascenssion soit le joueur vien de taper un block avec sa tête
    if(thePlayer->getItsRect()->top() == theBlock->getItsRect()->bottom() && thePlayer->getItsYSpeed() < STILL)
    {
        // Si le bloc est un bloc POW et qu'il n'a pas été frappé.
        if(theBlock->getItsType() == POW && !isBlockPOWHitted)
        {
            // On appelle la méthode correspondante.
            colBtwPlayerAndBlockPOW(thePlayer, theBlock);
        }
        // Sinon c'est on bloc normal.
        else
        {
            //Arrette le saut du joueur
            thePlayer->setItsRemaningJumpMove(0);
            //Met l'état du block à true soit : touché
            theBlock->setItsState(true);
            //Démarre le compteur du block pour le temps qu'il doit passé à true
            theBlock->setItsCounter((1000/NUMBER_LOOP_PER_SECOND)*BLOCK_HIT_TIME);
        }
    }
    //vrai si le bas du joueur égale le haut du block soit le joueur est sur le block
    if(thePlayer->getItsRect()->bottom() == theBlock->getItsRect()->top())//le joueur est sur un block
    {
        //Définie la vitesse du joueur sur l'axe Y à 0 si il est en descente et ne change pas si il est en ascenssion
        thePlayer->setItsYSpeed(thePlayer->getItsYSpeed() > STILL?STILL:thePlayer->getItsYSpeed());
        //Défini le joueur comme étant sur une surface
        thePlayer->setIsOnTheGround(true);
    }
    //vrai si le joueur à au minimum un pixel sur le même axe X qu'au minimum 1 pixel de block
    if((thePlayer->getItsRect()->top() < theBlock->getItsRect()->bottom()) && (thePlayer->getItsRect()->bottom() > theBlock->getItsRect()->top())){
        //vrai si le joueur touche le block par la droite
        if((thePlayer->getItsRect()->right() == theBlock->getItsRect()->left()))
        {
            //Empêche le déplacement du joueur sur l'axe X
            thePlayer->setItsCurrentMove(NONE);
        }
        //vrai si le joueur touche le block par la gauche
        else if((thePlayer->getItsRect()->left() == theBlock->getItsRect()->right()))
        {
            //Empêche le déplacement du joueur sur l'axe X
            thePlayer->setItsCurrentMove(NONE);
        }
    }
}

void Game::colBtwEnemyAndDespawner(Enemy* theEnemy, Despawner* theDespawner)
{
    //vrai si l'ennemie est rentré entièrement dans le despwaner
    if ((theEnemy->getItsX() <= theEnemy->getItsWidth()) ||(theEnemy->getItsX() >= WIDTH*32-theEnemy->getItsWidth())) {
        //fait réapparaitre l'ennemie dans le spawner lié au despawner
        theDespawner->disappear(theEnemy);
    }
}

void Game::colBtwPlayerAndMoney(Money* theMoney)
{
    //Si la piece est de type RED
    if (theMoney->getItsMoneyType()==RED)
    {
        //Incrémente le wallet de la game avec le valeur de la piece
        setItsMoney(getItsMoney() + RED);
    }
    //Si la piece est de type YELLOW
    else if (theMoney->getItsMoneyType()==YELLOW)
    {
        //Incrémente le wallet de la game avec le valeur de la piece
        setItsMoney(getItsMoney() + YELLOW);
    }
    //Si la piece est de type autre soit BILL
    else
    {
        //Incrémente le wallet de la game avec le valeur de la piece
        setItsMoney(getItsMoney() + BILL);
    }
    //Retire du niveau la piéce
    itsLevel->removeMoney(theMoney);
}

bool Game::isOnTop(Entity * entity1, Entity * entity2){
    //Retourne vrai si l'entité 1 est sur l'entité 2
    return entity1->getItsRect()->bottom() == entity2->getItsRect()->top();
}

bool Game::collid(Entity * entity1, Entity * entity2)
{
    //Retourne vrai l'entité 1 chevauche l'entité 2
    return (entity1->getItsRect()->intersects(*entity2->getItsRect()));
}

int Game::checkTier()
{
    //Vrai si le wallet de la game est supérieur ou égale à 100
    if (itsMoney >= 100)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 5; // Quatrième palier
    }
    //Vrai si le wallet de la game est supérieur ou égale à 50
    else if (itsMoney >= 50)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 4; // Troisième palier
    }
    //Vrai si le wallet de la game est supérieur ou égale à 25
    else if (itsMoney >= 25)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 3; // Deuxième palier
    }
    //Vrai si le wallet de la game est supérieur ou égale à 10
    else if (itsMoney >= 10)
    {
        cheminBG = BACKGROUND2_FILE_PATH;
        return 2; // Premier palier
    }
    //Vrai si le wallet de la game est supérieur ou inférieur à 10
    else
    {
        cheminBG = BACKGROUND1_FILE_PATH;
        return 1; // Pas encore de palier atteint
    }
}

void Game::moveAll(){
    //vrai si le game loop à fait assez de tour valeur définie avec la speed du player
    if(itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(PLAYERMAXSPEED*BLOCK_SIZE)) == 0)//NUMBER_LOOP_PER_SECOND/((NUMBER_LOOP_PER_SECOND/BLOCK_SIZE)/PLAYERMAXSPEED))
    {
        itsPlayer->move();
    }
    //Parcours tous les enemy du niveau
    for (Enemy * enemy : itsLevel->getItsEnemiesList()){
        //Case pour tous les type d'enemy
        switch (enemy->getItsType())
        {
        //Cas ou l'enemy est de type STANDARD
        case STANDARD:
            //vrai si le game loop à fait assez de tour valeur définie avec la speed de l'ennemie standard
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(STANDARD_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                //execute sa fonction move
                enemy->move();
            }
            break;
        //Cas ou l'enemy est de type GIANT
        case GIANT:
            //vrai si le game loop à fait assez de tour valeur définie avec la speed du GIANT
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(GIANT_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                //execute sa fonction move
                enemy->move();
            }
            break;
        case JUMPER:
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(JUMPER_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                enemy->move();
            }
            break;
        case FREEZER:
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(FREEZER_ENEMY_SPEED*BLOCK_SIZE))) == 0)
            {
                enemy->move();
            }
            break;
        //Cas ou l'enemy est de type ACCELERATOR
        case ACCELERATOR:
            //Défini l'ennemy avec son objet accelerator
            Accelerator* accelerator = dynamic_cast<Accelerator*>(enemy);
            //vrai si le game loop à fait assez de tour valeur définie avec la speed de l'accelerator plus son boost
            if((itsLoopCounter % (NUMBER_LOOP_PER_SECOND/((ACCELERATOR_ENEMY_SPEED+accelerator->getItsSpeedState())*BLOCK_SIZE))) == 0)
            {
                //execute sa fonction move
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
    //Vrai si le joueur est sur une surface
    if(itsPlayer->getIsOnTheGround()){
        //Défini sa vitesse sur l'axe Y à -1 soit : il monte
        itsPlayer->setItsYSpeed(-1);
        //Démmarre son compteur de temps pour le saut
        itsPlayer->setItsRemaningJumpMove(PLAYER_JUMP_HEIGHT*BLOCK_SIZE);
    }
}

void Game::onLeftKeyReleased()
{
    //if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(NONE);
    itsPlayer->setItsNextMove(NONE);
}

void Game::onRightKeyReleased()
{
    //if(itsPlayer->getItsRemaningJumpMove() == 0)itsPlayer->setItsCurrentMove(NONE);
    itsPlayer->setItsNextMove(NONE);
}

void Game::onGamePaused()
{
    //pause flag a true
    isInPause = true;
    //Running flag à false
    running = false;
    //Deésactive le niveau
    itsLevel->desactivate();
}

void Game::onGameResumed()
{
    //pause flag a true
    isInPause = false;
    //runnig flag a true
    running = true;
    //Rééactive le niveau
    itsLevel->activate();
}

void Game::openLevel(){
    //Défini le chemin du niveau en fonction du niveau
    std::string fileName = "://ressources/level" + std::to_string(currentLevel) + ".json";
    //vrai si le niveau n'existe pas
    if (itsLevel != nullptr){
        //supprime le level
        delete itsLevel;
        //redéfini le level à nullptr
        itsLevel = nullptr;
    }
    //Création du nouveau niveau
    itsLevel = new Level(fileName, itsTileSet);
}

void Game::levelTimeout()
{
    //Désactive le niveau
    itsLevel->desactivate();
    //baisse le flag du running
    running = false;
}

bool Game::isLevelFinished(){
    //retourne vrai si il n'y a plus de ennemies
    return itsLevel->getItsEnemiesList().empty() && itsLevel->getItsRemainingEnemies().empty();
}
