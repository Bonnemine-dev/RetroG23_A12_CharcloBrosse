#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Spawner : public QObject
{
    Q_OBJECT

    Spawner * spawner;
    Enemy * enemy;
    TileSet * tileSet;

public:
    test_Spawner();
    ~test_Spawner();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_constructor();
    void test_appears();
};

test_Spawner::test_Spawner()
{

}

test_Spawner::~test_Spawner()
{

}

void test_Spawner::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Spawner::cleanupTestCase()
{
    delete tileSet;
}

void test_Spawner::init()
{
    spawner = new Spawner(0, 64, 100, 100, tileSet->getItsSpawnerTilesList(), EAST);
    enemy = new Enemy(32, 32);
}

void test_Spawner::cleanup()
{
    delete spawner;
    delete enemy;
}

void test_Spawner::test_constructor()
{
    QVERIFY(spawner != nullptr);
}

void test_Spawner::test_appears()
{
    spawner->appears(enemy);
    QCOMPARE(enemy->getItsX(), (unsigned short)(spawner->getItsX() + 16));
    QCOMPARE(enemy->getItsY(), spawner->getItsY()+spawner->getItsHeight() - enemy->getItsHeight());
}

QTEST_MAIN(test_Spawner)

#include "tst_test_spawner.moc"
