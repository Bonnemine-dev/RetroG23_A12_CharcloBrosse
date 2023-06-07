/**
 * @file level.cpp
 * @brief Source file for class Level for the CharcloBrosse project
 * @author SIMON Kevin
 * @date 05/06/2023
 * @version 1.0
 */
#include "level.h"

std::vector<Block *> Level::getItsBlockList() const
{
    return itsBlockList;
}

std::vector<Enemy *> Level::getItsEnemiesList() const
{
    return itsEnemiesList;
}

std::vector<Spawner *> Level::getItsSpawnerList() const
{
    return itsSpawnerList;
}

std::vector<Despawner *> Level::getItsDespawnerList() const
{
    return itsDespawnerList;
}

void Level::display(QPainter *painter)
{
    for (unsigned short i = 0; i < itsBlockList.size(); i++){ // affiche tout les blocs
        itsBlockList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsEnemiesList.size(); i++){ // affiche tout les ennemis
        itsEnemiesList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsSpawnerList.size(); i++){ // affiche tout les spawner
        itsSpawnerList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsDespawnerList.size(); i++){ // daffiche tout les despwaner
        itsDespawnerList.at(i)->display(painter);
    }
}

void Level::removeEnemy(Enemy * enemy)
{
    for (std::vector<Enemy *>::iterator it=itsEnemiesList.begin(); it != itsEnemiesList.end(); it++){ // parcours la liste des enbemies apparus
        if ((*it)==enemy){ // compare
            itsEnemiesList.erase(it); // eneleve l'ennemi de la liste
            delete (*it); // supprime l'ennemi de la memoire
        }
    }
}

unsigned short Level::getItsId() const
{
    return itsId;
}

unsigned short Level::getItsMinDelay() const
{
    return itsMinDelay;
}

unsigned short Level::getItsMaxDelay() const
{
    return itsMaxDelay;
}

std::vector<unsigned short> Level::getItsEnemyAppearsTimes() const
{
    return itsEnemyAppearsTimes;
}

std::vector<Sides> Level::getItsEnemyAppearsSides() const
{
    return itsEnemyAppearsSides;
}

std::vector<Enemy *> Level::getItsRemainingEnemies() const
{
    return itsRemainingEnemies;
}

Level::Level(std::string levelFilePath, TileSet * tileSet) : itsLevelFile(levelFilePath)
{
    // open the file and parse it
    QFile jsonFile;
    jsonFile.setFileName(QString(itsLevelFile.c_str())); // spécifie le chemin du fichier à ouvrir
    if (!jsonFile.exists()){ // cerifi que le fichier soit lisible
        throw std::string("Level file does not exists");
    }
    jsonFile.open(QIODevice::ReadOnly); // tente d'ouvrir le fichier
    if (!jsonFile.isOpen()){ // verifi que le fichier soit ouvert
        throw std::string("Could not open the level file");
    }
    QString content = jsonFile.readAll(); // copie le contenu du fichier

    jsonFile.close();

    QJsonDocument jsonData = QJsonDocument::fromJson(content.toUtf8()); // parse les données vers un objet de type QjsonDocument
    QJsonObject jsonRoot = jsonData.object(); // convertie les donnée en forme de QJsonObject comme un dictionnaire


    // génere les données
    itsId = jsonRoot.value("id").toInt(0); // reccupere l'id du niveau
    QJsonArray level = jsonRoot.value("level").toArray(); // reccupère la liste des blocs
    QJsonArray Enemies = jsonRoot.value("enemies").toArray(); // reccupère la liste des ennemis
    itsMinDelay = jsonRoot.value("minDelay").toInt(0); // reccupere le delais minimum avant l'apparition du prochain ennemi
    itsMaxDelay = jsonRoot.value("maxDelay").toInt(0); // reccupere le delais maximum avant l'apparition du prochain ennemi


    // compute the data
    for (unsigned short line=0; line < level.size(); line++){ // pour chaque ligne du niveau
        QJsonArray jsonLine = level[line].toArray(); // créer un tableau contenant la ligne
        for (unsigned short col=0; col < jsonLine.size(); col++){ // pour chaque clonnes
            int block = jsonLine[col].toInt(0); // reccupere le numero du bloc (0 pour rien, 1 pour le sol, 2 pour la plateforme)
            if (block == 1){ // si un bloq de sol
                itsBlockList.push_back(new Block(col*32, line*32, 32, 32, tileSet->getItsGroundTile()));
            }
            if (block == 2){ // si un bloc de plateforme
                itsBlockList.push_back((new Block(col*32, line*32, 32, 32, tileSet->getItsBlockTile())));
            }
        }
    }

    for (unsigned short line=0; line < Enemies.size(); line++){ // pour chaque ennemis
        QJsonArray jsonLine = Enemies[line].toArray(); // reccupere le tableau
        std::string type = jsonLine[0].toString().toStdString(); // reccupere le type d'ennemi
        if (type == "standard"){ // si un ennemi standard
            itsRemainingEnemies.push_back(new Standard(32, 32, tileSet->getItsEnemyTile())); // creer l'ennemi et l'ajoute à la liste des ennemis à faire apparaitre
            if (jsonLine[1].toString().toStdString() == "left"){
                itsEnemyAppearsSides.push_back(LEFT); // met le point d'apparition au spawner gauche
            }
            else{
                itsEnemyAppearsSides.push_back(RIGHT); // met le point d'apparition au spawner droit
            }
        }
    }

    for (unsigned int i = 0; i < itsEnemiesList.size(); i++){ // reccupere le delais d'appartion de chaque ennemis (en sens inverse)
        itsEnemyAppearsTimes.push_back(itsMinDelay+((itsMaxDelay - itsMinDelay)/(itsEnemiesList.size()-1))*i); // calcul le delais
    }
    std::reverse(itsEnemyAppearsTimes.begin(), itsEnemyAppearsTimes.end()); // inverse la liste

    itsSpawnerList.push_back(new Spawner(0, 32*3, 96, 64, tileSet->getItsSpawnerTile(0))); // ajoute le spawner gauche
    itsSpawnerList.push_back(new Spawner(32*38, 32*3, 96, 64, tileSet->getItsSpawnerTile(1))); // ajoute le spawner droit

    itsDespawnerList.push_back(new Despawner(itsSpawnerList.at(0), 0, 32*3, 96, 64, tileSet->getItsDespawnerTile(0))); // ajoute le despawner gauche
    itsDespawnerList.push_back(new Despawner(itsSpawnerList.at(1), 32*38, 32*3, 96, 64, tileSet->getItsDespawnerTile(1))); // ajoute le despawner despawner

}

void Level::appears(Enemy * enemy){
    //checher l'ennemi et le transfert de la liste a apparaite à clelle de ceux deja apparus
    for (std::vector<Enemy *>::iterator it=itsRemainingEnemies.begin(); it != itsRemainingEnemies.end(); it++){
        if ((*it)==enemy){
            itsRemainingEnemies.erase(it); // eneleve l'ennemi de la liste de ceux à apparaitre
            itsEnemiesList.push_back(*it); // l'ajoute a la liste de ceux etant apparus
            itsEnemyAppearsTimes.erase(itsEnemyAppearsTimes.begin()); // retire son delais d'apparition
            itsEnemyAppearsSides.erase(itsEnemyAppearsSides.begin()); // retire son point d'apparition
        }
    }
}
