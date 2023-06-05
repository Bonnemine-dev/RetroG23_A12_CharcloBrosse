
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
    for (unsigned short i = 0; i < itsBlockList.size(); i++){ // display all the blocks
        itsBlockList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsEnemiesList.size(); i++){ // display all the enemies
        itsEnemiesList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsSpawnerList.size(); i++){ // display all the spawners
        itsSpawnerList.at(i)->display(painter);
    }
    for (unsigned short i = 0; i < itsDespawnerList.size(); i++){ // display all the despawners
        itsDespawnerList.at(i)->display(painter);
    }
}

void Level::removeEnemy(Enemy * enemy)
{
    for (std::vector<Enemy *>::iterator it=itsEnemiesList.begin(); it != itsEnemiesList.end(); it++){ // scan the ennemies list
        if ((*it)==enemy){ //if it's the good enemy
            itsEnemiesList.erase(it); // remove from the list
            delete (*it); // delete from memory
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
    jsonFile.setFileName(QString(itsLevelFile.c_str())); // set the file path
    if (!jsonFile.isReadable()){ // verify if the file is readable
        throw std::string("Level file is not readable");
    }
    jsonFile.open(QIODevice::ReadOnly); // open the file
    if (!jsonFile.isOpen()){ // verify if the file is opened
        throw std::string("Could not open the level file");
    }
    QString content = jsonFile.readAll(); // copy the content of the file

    QJsonDocument jsonData = QJsonDocument::fromJson(content.toUtf8()); // parse the data to a QjsonDocument object
    QJsonObject jsonRoot = jsonData.object(); // convert into a dictionnary like object


    // get the data
    itsId = jsonRoot.value("id").toInt(0); // get the id of the level
    QJsonArray level = jsonRoot.value("level").toArray(); // get the block list of the level
    QJsonArray Enemies = jsonRoot.value("enemies").toArray(); // get the enemies list of the level
    itsMinDelay = jsonRoot.value("minDelay").toInt(0); // get the minimum delay of appartition of an enemy
    itsMaxDelay = jsonRoot.value("maxDelay").toInt(0); // get the maximun delay of appartition of an enemy


    // compute the data
    for (unsigned short line=0; line < level.size(); line++){ // for each line of the level
        QJsonArray jsonLine = level[line].toArray(); // create the array for the column
        for (unsigned short col=0; col < jsonLine.size(); col++){ // for each column
            int block = jsonLine[col].toInt(0); // get the block number (0 for nothing, 1 for the ground, 2 for the platform)
            if (block != 1){ // if ground blocck
                itsBlockList.push_back(new Block(col*32, line*32, 32, 32, tileSet->getItsGroundTile()));
            }
            if (block == 2){ // if platform block
                itsBlockList.push_back((new Block(col*32, line*32, 32, 32, tileSet->getItsBlockTile(0))));
            }
        }
    }

    for (unsigned short line=0; line < Enemies.size(); line++){ // for each enemies
        QJsonArray jsonLine = Enemies[line].toArray(); // get the array
        std::string type = jsonLine[0].toString().toStdString(); // get the type of the enemy in string
        if (type == "standard"){ // if a standard enemy
            itsRemainingEnemies.push_back(new Standard(32, 32, tileSet->getItsEnemyTile(0,0))); // create the enemy and add it to the list
            if (jsonLine[1].toString().toStdString() == "left"){
                itsEnemyAppearsSides.push_back(LEFT); // set the appear point to left spawner
            }
            else{
                itsEnemyAppearsSides.push_back(RIGHT); // set the appear point to right spawner
            }
        }
    }

    for (unsigned int i = 0; i < itsEnemiesList.size(); i++){ // get the delay before apparition for each enemies (in reverse order)
        itsEnemyAppearsTimes.push_back(itsMinDelay+((itsMaxDelay - itsMinDelay)/(itsEnemiesList.size()-1))*i); // compute the delay
    }
    std::reverse(itsEnemyAppearsTimes.begin(), itsEnemyAppearsTimes.end()); // reverse the list

}

void Level::appears(Enemy * enemy){
    unsigned short i = 0;
    for (std::vector<Enemy *>::iterator it=itsRemainingEnemies.begin(); it != itsRemainingEnemies.end(); it++){ // scan the ennemies list
        if ((*it)==enemy){ //if it's the good enemy
            itsRemainingEnemies.erase(it); // remove from the list
            itsEnemiesList.push_back(*it);
            std::reverse(itsEnemyAppearsTimes.begin(), itsEnemyAppearsTimes.end()); // reverse the list
            itsEnemyAppearsTimes.pop_back();
            std::reverse(itsEnemyAppearsTimes.begin(), itsEnemyAppearsTimes.end()); // reverse the list
            std::reverse(itsEnemyAppearsSides.begin(), itsEnemyAppearsSides.end());
            itsEnemyAppearsSides.pop_back();
            std::reverse(itsEnemyAppearsSides.begin(), itsEnemyAppearsSides.end());
        }
        i++;
    }
}
