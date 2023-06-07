#include <QtTest>

#include "../../CharcloBrosse/player.h"
#include "../../CharcloBrosse/hmi.h"
#include "../../CharcloBrosse/tileset.h"
#include "../../CharcloBrosse/level.h"
#include "../../CharcloBrosse/spawner.h"
#include "../../CharcloBrosse/despawner.h"
#include "../../CharcloBrosse/game.h"
#include "../../CharcloBrosse/typedef.h"

class test_Game : public QObject
{
    Q_OBJECT

public:
    test_Game();
    ~test_Game();

private slots:
    void init_test_case1();
    void cleanup_test_case1();
    void test_Constructor();
    void test_checkAllCollid();
    void test_colBtwPlayerAndEnemy();
    void test_colBtwEnemyAndEnemy();
    void test_colBtwEnemyAndBlock();
    void test_colBtwPlayerAndBlock();
    void test_colBtwEnemyAndDespawner();
    void test_gravity();
    void test_isLevelFinished();
    void test_moveAll();
    void test_gameLoop();
    void test_onLeftKeyPressed();
    void test_onRightKeyPressed();
    void test_onUpKeyPressed();
    void test_onLeftKeyReleased();
    void test_onRightKeyReleased();
    void test_onGamePaused();
    void test_onGameResumed();
};

test_Game::test_Game()
{}

test_Game::~test_Game()
{}

void test_Game::init_test_case1()
{

}

void test_Game::cleanup_test_case1()
{

}

void test_Game::test_Constructor()
{

}

void test_Game::test_checkAllCollid()
{
    // Sert a r en fait vu que on les fait tous un a un
}

void test_Game::test_colBtwEnemyAndEnemy()
{

}

void test_Game::test_colBtwEnemyAndBlock()
{

}

void test_Game::test_colBtwPlayerAndBlock()
{

}

void test_Game::test_colBtwEnemyAndDespawner()
{

}

void test_Game::test_gravity()
{

}

void test_Game::test_isLevelFinished()
{

}

void test_Game::test_moveAll()
{

}

void test_Game::test_gameLoop()
{

}

void test_Game::test_onLeftKeyPressed()
{

}

void test_Game::test_onRightKeyPressed()
{

}

void test_Game::test_onUpKeyPressed()
{

}

void test_Game::test_onLeftKeyReleased()
{

}

void test_Game::test_onRightKeyReleased()
{

}

void test_Game::test_onGamePaused()
{

}

void test_Game::test_onGameResumed()
{

}

QTEST_APPLESS_MAIN(test_Game)

#include "tst_test_game.moc"
