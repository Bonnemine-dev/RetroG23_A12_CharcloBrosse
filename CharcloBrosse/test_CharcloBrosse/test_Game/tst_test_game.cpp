#include <QtTest>
#include <iostream>
#include "../../CharcloBrosse/game.h"


class test_Game : public QObject
{
    Q_OBJECT
    Game * game;
    TileSet * tileSet;
    Player * player;
    Level * level;
    HMI * hmi;
    Block * block;
    Enemy * enemy;
    Spawner * spawner;
    Despawner * despawner;
    QPixmap * sprite;
public:
    test_Game();
    ~test_Game();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_colBtwPlayerAndEnemy();
//    void test_colBtwEnemyAndEnemy();
//    void test_colBtwEnemyAndBlock();
//    void test_colBtwPlayerAndBlock();
//    void test_colBtwEnemyAndDespawner();
//    void test_isLevelFinished();
//    void test_isOnTop();
//    void test_collid();
};

test_Game::test_Game()
{
}

test_Game::~test_Game()
{
}

void test_Game::initTestCase()
{
    tileSet = new TileSet("tileset0.png");
    player = new Player(80, 80, 64, 32, sprite);
    level = new Level("level1.json",tileSet);
    block = new Block(0, 0, 32, 32, sprite);
    enemy = new Enemy(32, 32, sprite);
    spawner = new Spawner(0, 200, 64, 64, sprite);
    despawner = new Despawner(spawner, 0, 200, 64, 64, sprite);
}

void test_Game::cleanupTestCase()
{
    delete tileSet;
    delete player;
    delete level;
    delete block;
    delete enemy;
    delete spawner;
    delete despawner;
}

void test_Game::init()
{
    game = new Game();
}

void test_Game::cleanup()
{
    delete game;
}

void test_Game::test_colBtwPlayerAndEnemy()
{
    player->setItsLivesNb(3);
    enemy->setX(80);
    enemy->setY(80);
    game->colBtwPlayerAndEnemy(player, enemy);
    QCOMPARE(player->getItsLivesNb(), (unsigned short)2);
    QCOMPARE(player->getItsX(), (unsigned short)(32*39)/2);
    QCOMPARE(player->getItsY(), (unsigned short)32);
    QCOMPARE(enemy->getItsX(), (unsigned short)80);
    QCOMPARE(enemy->getItsY(), (unsigned short)80);
}


QTEST_MAIN(test_Game)

#include "tst_test_game.moc"
