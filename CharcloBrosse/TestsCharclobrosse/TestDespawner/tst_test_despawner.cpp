#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Despawner : public QObject
{
    Q_OBJECT
    Despawner * despawner;
    Spawner * spawner;
    Enemy * enemy;
    TileSet * tileSet;

public:
    test_Despawner();
    ~test_Despawner();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_constructor();
    void test_disappear();
};

test_Despawner::test_Despawner()
{

}

test_Despawner::~test_Despawner()
{

}

void test_Despawner::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Despawner::cleanupTestCase()
{
    delete tileSet;
}

void test_Despawner::init()
{
    spawner = new Spawner(0, 0, 100, 100, tileSet->getItsSpawnerTilesList(), WEST);
    despawner = new Despawner(spawner, 200, 200, 100, 100, tileSet->getItsDespawnerTilesList(), EAST);
    enemy = new Enemy(100, 100);
    enemy->setItsXSpeed(10);
}

void test_Despawner::cleanup()
{
    delete spawner;
    delete despawner;
    delete enemy;
}

void test_Despawner::test_constructor()
{
    QVERIFY(despawner != nullptr);
}

void test_Despawner::test_disappear()
{
    despawner->disappear(enemy);
    QCOMPARE(enemy->getItsX(), spawner->getItsX());
    QCOMPARE(enemy->getItsY(), spawner->getItsY());
    QCOMPARE(enemy->getItsXSpeed(), (short)-10);
}

QTEST_MAIN(test_Despawner)

#include "tst_test_despawner.moc"
