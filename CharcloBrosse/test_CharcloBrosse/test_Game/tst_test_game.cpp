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
    Enemy * enemy1;
    Enemy * enemy2;
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
    void test_colBtwEnemyAndEnemy();
    void test_colBtwEnemyAndBlock();
    void test_colBtwPlayerAndBlock();
    void test_colBtwEnemyAndDespawner();
    void test_isOnTop();
    void test_collid();
};

test_Game::test_Game()
{
}

test_Game::~test_Game()
{
}

void test_Game::initTestCase()
{
    tileSet = new TileSet("C:/Users/tombo/Desktop/src/tileset0.png");
    player = new Player(80, 80, 64, 32, sprite);
    level = new Level("C:/Users/tombo/Desktop/src/level1.json",tileSet);
    block = new Block(0, 0, 32, 32, sprite);
    enemy1 = new Enemy(32, 32, sprite);
    enemy2 = new Enemy(32, 32, sprite);
    spawner = new Spawner(0, 200, 64, 64, sprite);
    despawner = new Despawner(spawner, 0, 200, 64, 64, sprite);
}

void test_Game::cleanupTestCase()
{
    delete tileSet;
    delete player;
    delete level;
    delete block;
    delete enemy1;
    delete enemy2;
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
    enemy1->setX(80);
    enemy1->setY(80);
    game->colBtwPlayerAndEnemy(player, enemy1);
    QCOMPARE(player->getItsLivesNb(), 2);
    QCOMPARE(player->getItsX(), (32*39)/2);
    QCOMPARE(player->getItsY(), 32);
    QCOMPARE(enemy1->getItsX(), 80);
    QCOMPARE(enemy1->getItsY(), 80);
}

void test_Game::test_colBtwEnemyAndEnemy()
{
    enemy1->setX(50);
    enemy1->setY(50);
    enemy2->setX(50);
    enemy2->setY(50);
    enemy1->setItsXSpeed(10);
    enemy2->setItsXSpeed(10);
    game->colBtwEnemyAndEnemy(enemy1, enemy2);
    QCOMPARE(enemy2->getItsXSpeed(), (short)-10);
    game->colBtwEnemyAndEnemy(enemy1, enemy2);
    QCOMPARE(enemy1->getItsXSpeed(), (short)-10);
    QCOMPARE(enemy2->getItsXSpeed(), (short)10);
}

void test_Game::test_colBtwEnemyAndBlock()
{
    enemy1->setItsYSpeed(-5);
    block->setItsState(true);
    enemy1->setIsOnTheGround(false);
    game->colBtwEnemyAndBlock(enemy1, block);
}

void test_Game::test_colBtwPlayerAndBlock()
{
    player->setItsXSpeed(10);
    player->setItsYSpeed(-10);
    player->setIsOnTheGround(false);
    block->setX(10);
    block->setY(75);
    block->setItsState(false);
    game->colBtwPlayerAndBlock(player, block);
    QCOMPARE(player->getItsYSpeed(), 0);
    QCOMPARE(player->getIsOnTheGround(), true);
    QCOMPARE(block->getItsState(), true);
}

void test_Game::test_colBtwEnemyAndDespawner()
{
    enemy1->setX(10);
    enemy1->setY(10);
    game->colBtwEnemyAndDespawner(enemy1, despawner);
    QCOMPARE(enemy1->getItsX(), spawner->getItsX());
    QCOMPARE(enemy1->getItsY(), spawner->getItsY());
}

void test_Game::test_isOnTop()
{
    player->setX(10);
    player->setY(10);
    block->setX(10);
    block->setY(75);
    QVERIFY(game->isOnTop(player, block) == true);
    player->setX(10);
    player->setY(150);
    QVERIFY(game->isOnTop(player, block) == false);
}

void test_Game::test_collid()
{
    enemy1->setX(0);
    enemy1->setY(0);
    player->setX(150);
    player->setY(150);
    QCOMPARE(game->collid(enemy1, player), false);
    enemy1->setX(150);
    enemy1->setY(150);
    QCOMPARE(game->collid(enemy1, player), true);
}


QTEST_MAIN(test_Game)

#include "tst_test_game.moc"
