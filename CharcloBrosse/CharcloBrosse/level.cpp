/**
 * @file level.cpp
 * @brief Source file for class Level
 * @author Kevin Simon
 * @date 05/06/2023
 * @version 1.1
 */

#include "level.h"
#include "typedef.h"

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
    for (unsigned short i = 0; i < itsSpawnerList.size(); i++){ // affiche tout les spawner
        itsSpawnerList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsDespawnerList.size(); i++){ // daffiche tout les despwaner
        itsDespawnerList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsEnemiesList.size(); i++){ // affiche tout les ennemis
        itsEnemiesList.at(i)->display(painter);
    }
}

void Level::removeEnemy(Enemy * enemy) {
    itsEnemiesList.erase(std::remove(itsEnemiesList.begin(), itsEnemiesList.end(), enemy), itsEnemiesList.end());
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
    if (!jsonFile.exists()){ // cerifi que le fichier existe
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
    itsMinDelay = jsonRoot.value("minDelay").toInt(0); // get the minimum delay of appartition of an enemy
    itsMaxDelay = jsonRoot.value("maxDelay").toInt(0); // get the maximun delay of appartition of an enemy

    // compute the data
    for (unsigned short line=0; line < level.size(); line++){ // for each line of the level
        QJsonArray jsonLine = level[line].toArray(); // create the array for the column
        for (unsigned short col=0; col < jsonLine.size(); col++){ // for each column
            int block = jsonLine[col].toInt(0); // get the block number (0 for nothing, 1 for the ground, 2 for the platform)
            if (block == 1){ // if ground block
                itsBlockList.push_back(new Block(col*32, line*32, 32, 32, tileSet->getItsGroundTile(),GROUND));
            }
            else if (block == 2){ // if platform block
                itsBlockList.push_back((new Block(col*32, line*32, 32, 32, tileSet->getItsBlockTile(),BRICK)));
            }
            else if (block == 3){ // if obstacle
                itsBlockList.push_back((new Block(col*32, line*32, 32, 32, tileSet->getItsEnemyHitTile(),OBSTACLE)));
            }
        }
    }

    for (unsigned short line=0; line < Enemies.size(); line++){ // for each enemies
        QJsonArray jsonLine = Enemies[line].toArray(); // get the array
        std::string type = jsonLine[0].toString().toStdString(); // get the type of the enemy in string
        if (type == "standard"){ // if a standard enemy
            itsRemainingEnemies.push_back(new Standard(32, 32, tileSet->getItsEnemyTile())); // create the enemy and add it to the list
            if (jsonLine[1].toString().toStdString() == "left"){
                itsEnemyAppearsSides.push_back(LEFT); // set the appear point to left spawner
            }
            else{
                itsEnemyAppearsSides.push_back(RIGHT); // set the appear point to right spawner
            }
        }
    }

    if (itsRemainingEnemies.size() > 1){
        for (unsigned int i = 0; i < itsRemainingEnemies.size(); ++i){ // get the delay before apparition for each enemies (in reverse order)
            unsigned short temp = itsMinDelay+((itsMaxDelay - itsMinDelay)/(itsRemainingEnemies.size()-1))*i;
            itsEnemyAppearsTimes.push_back(temp); // compute the delay
        }
        // std::reverse(itsEnemyAppearsTimes.begin(), itsEnemyAppearsTimes.end()); // reverse the list
    }
    else {
        itsEnemyAppearsTimes.push_back(itsMaxDelay);
    }

    itsSpawnerList.push_back(new Spawner(0, 32*3, 96, 64, tileSet->getItsSpawnerTile(0)));
    itsSpawnerList.push_back(new Spawner(32*38, 32*3, 96, 64, tileSet->getItsSpawnerTile(1)));

    itsDespawnerList.push_back(new Despawner(itsSpawnerList.at(0), 0, 32*18, 96, 64, tileSet->getItsDespawnerTile(0)));
    itsDespawnerList.push_back(new Despawner(itsSpawnerList.at(1), 32*38, 32*18, 96, 64, tileSet->getItsDespawnerTile(1)));

    active = false;
}

void Level::appears(Enemy * enemy){
    itsRemainingEnemies.pop_back();
    itsEnemiesList.push_back(enemy);
    itsEnemyAppearsTimes.pop_back();
    itsEnemyAppearsSides.pop_back();
}

void Level::activate(){
    active = true;
}

bool Level::isActive(){
    return active;
}
