#include <QtTest>

// add necessary includes here

#include "../../CharcloBrosse/block.h"
#include "../../CharcloBrosse/despawner.h"
#include "../../CharcloBrosse/enemy.h"
#include "../../CharcloBrosse/entity.h"
#include "../../CharcloBrosse/level.h"
#include "../../CharcloBrosse/spawner.h"
#include "../../CharcloBrosse/tileset.h"


class test_Level : public QObject
{
    Q_OBJECT
private:
    std::string itsJsonFilePath = "../../CharcloBrosse/test_CharcloBrosse/test_Level/testFile.json";
    std::string itsJsonFileUnreadablePath = "../../CharcloBrosse/test_CharcloBrosse/test_Level/testFileUnreadable.json";
    Level* itsLevel;
    TileSet* itsTileset;

public:
    test_Level();
    ~test_Level();

private slots:
    void init();
    void cleanup();

    void test_Constructor_UnfoundFile_Exception();

    void test_Constructor_Generals();

    void test_Constructor_NumberBlock();
    void test_Constructor_PositionBlock();

    void test_Constructor_NumberEnemy();
    void test_Constructor_SideEnemy();

    void test_Constructor_NumberSpawner();
    void test_Constructor_PositionSpawner();

    void test_Constructor_NumberDispawner();
    void test_Constructor_PositionDispawner();

    void test_removeEnemy();

    void test_appears();

};

test_Level::test_Level()
{

}

test_Level::~test_Level()
{

}

void test_Level::init()
{


    try
    {
        itsLevel = new Level(itsJsonFilePath, itsTileset);
    }
    catch(const std::string exceptionMessage)
    {
        if(exceptionMessage == "Could not open the level file")
        {
            QFAIL("File not openeable");
        }
        else
        {
            QFAIL("Unknow exception");
        }
    }

}

void test_Level::cleanup()
{
    delete itsLevel;
    delete itsTileset;
}



void test_Level::test_Constructor_UnfoundFile_Exception()
{
    Level* unvalidLevel;
    try
    {
        unvalidLevel = new Level("../../../jjdu/kid.json", itsTileset);
        delete unvalidLevel;
        QFAIL("No_exception_throw");
    }
    catch(const std::string exceptionMessage)
    {
        QCOMPARE(exceptionMessage, "Could not open the level file");
    }

    delete unvalidLevel;
}

void test_Level::test_Constructor_Generals()
{
    QCOMPARE(itsLevel->getItsId(), 4);
    QCOMPARE(itsLevel->getItsMinDelay(), 5);
    QCOMPARE(itsLevel->getItsMinDelay(), 13);
}

void test_Level::test_Constructor_NumberBlock()
{
    QCOMPARE(itsLevel->getItsBlockList().size(), 4);
}

void test_Level::test_Constructor_PositionBlock()
{
    QCOMPARE(itsLevel->getItsBlockList().at(0)->getItsX(), 0);
    QCOMPARE(itsLevel->getItsBlockList().at(0)->getItsY(), 0);

    QCOMPARE(itsLevel->getItsBlockList().at(1)->getItsX(), 1248);
    QCOMPARE(itsLevel->getItsBlockList().at(1)->getItsY(), 0);

    QCOMPARE(itsLevel->getItsBlockList().at(0)->getItsX(), 0);
    QCOMPARE(itsLevel->getItsBlockList().at(0)->getItsY(), 672);

    QCOMPARE(itsLevel->getItsBlockList().at(1)->getItsX(), 1248);
    QCOMPARE(itsLevel->getItsBlockList().at(1)->getItsY(), 672);
}

void test_Level::test_Constructor_NumberEnemy()
{
    QCOMPARE(itsLevel->getItsRemainingEnemies().size(), 2);
}

void test_Level::test_Constructor_SideEnemy()
{
    QCOMPARE(itsLevel->getItsEnemyAppearsSides().at(0), LEFT);
    QCOMPARE(itsLevel->getItsEnemyAppearsSides().at(1), RIGHT);
}

void test_Level::test_Constructor_NumberSpawner()
{
    QCOMPARE(itsLevel->getItsSpawnerList().size(), 2);
}

void test_Level::test_Constructor_PositionSpawner()
{
    QCOMPARE(itsLevel->getItsSpawnerList().at(0)->getItsX(), 0);
    QCOMPARE(itsLevel->getItsSpawnerList().at(0)->getItsY(), 96);

    QCOMPARE(itsLevel->getItsSpawnerList().at(0)->getItsX(), 1248);
    QCOMPARE(itsLevel->getItsSpawnerList().at(0)->getItsY(), 96);
}

void test_Level::test_Constructor_NumberDispawner()
{
    QCOMPARE(itsLevel->getItsDespawnerList().size(), 2);
}

void test_Level::test_Constructor_PositionDispawner()
{
    QCOMPARE(itsLevel->getItsDespawnerList().at(0)->getItsX(), 0);
    QCOMPARE(itsLevel->getItsDespawnerList().at(0)->getItsY(), 576);

    QCOMPARE(itsLevel->getItsDespawnerList().at(0)->getItsX(), 1248);
    QCOMPARE(itsLevel->getItsDespawnerList().at(0)->getItsY(), 576);
}

void test_Level::test_removeEnemy()
{
    itsLevel->appears(itsLevel->getItsRemainingEnemies().at(0));
    QCOMPARE(itsLevel->getItsEnemiesList().size(), 1);
    itsLevel->removeEnemy(itsLevel->getItsEnemiesList().at(0));
    QCOMPARE(itsLevel->getItsEnemiesList().size(), 0);
}

void test_Level::test_appears()
{
    QCOMPARE(itsLevel->getItsEnemiesList().size(), 0);
    QCOMPARE(itsLevel->getItsRemainingEnemies().size(), 2);
    itsLevel->appears(itsLevel->getItsRemainingEnemies().at(0));
    QCOMPARE(itsLevel->getItsEnemiesList().size(), 1);
    QCOMPARE(itsLevel->getItsRemainingEnemies().size(), 1);
}


QTEST_APPLESS_MAIN(test_Level)

#include "tst_test_level.moc"
