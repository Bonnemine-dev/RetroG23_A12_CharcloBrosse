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
    Game* itsGame;
    TileSet* itsTileSet;
    unsigned int itsScore;

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
    itsGame = new Game();
    itsTileSet = new TileSet("tileset.png");
    itsScore = 0;
}

void test_Game::cleanup_test_case1()
{
    delete itsGame;
    delete itsTileSet;
}

void test_Game::test_Constructor()
{
    // Vérifie que les objets ont été correctement initialisés.
    QVERIFY(itsGame->getItsTileSet() != nullptr);
    QVERIFY(itsGame->getItsPlayer() != nullptr);
    QVERIFY(itsGame->getItsLevel() != nullptr);
    QVERIFY(itsGame->getItsHMI() != nullptr);

    // Vérifie que les détails spécifiques de l'initialisation sont corrects.
    QCOMPARE(itsGame->getItsTileSet()->getImagePath(), QString("tileset.png"));
    QCOMPARE(itsGame->getItsPlayer()->getItsX(), 0);
    QCOMPARE(itsGame->getItsPlayer()->getItsY(), 0);
    QCOMPARE(itsGame->getItsLevel()->getLevelPath(), QString("level1.json"));
}


void test_Game::test_checkAllCollid()
{
    // Sert a r en fait vu que on les fait tous un a un
}

void test_Game::test_colBtwEnemyAndEnemy()
{
    // Créez deux ennemis avec différentes vitesses.
    Enemy* enemy1 = new Enemy(32, 32, itsTileSet->getItsEnemyTile());
    enemy1->setX(100);
    enemy1->setY(100);
    Enemy* enemy2 = new Enemy(32, 32, itsTileSet->getItsEnemyTile());
    enemy1->setX(130);
    enemy1->setY(100);

    // Enregistrez les vitesses initiales.
    int initialSpeed1 = enemy1->getItsXSpeed();
    int initialSpeed2 = enemy2->getItsXSpeed();

    // Faites les entrer en collision.
    itsGame->colBtwEnemyAndEnemy(enemy1, enemy2);

    // Vérifiez que les vitesses ont été inversées correctement.
    QCOMPARE(enemy1->getItsXSpeed(), -initialSpeed1);
    QCOMPARE(enemy2->getItsXSpeed(), -initialSpeed2);
}

void test_Game::test_colBtwEnemyAndBlock()
{
    // Créez un ennemi et un bloc.
    Enemy* enemy = new Enemy(32, 32, itsTileSet->getItsEnemyTile());
    enemy->setX(100);
    enemy->setY(69); //Pixel 1 pixel dans le block en y
    Block* block = new Block(100, 100, 32, 32, itsTileSet->getItsEnemyTile());

    // Faites les entrer en collision.
    itsGame->colBtwEnemyAndBlock(enemy, block);

    // Vérifiez que l'état de l'ennemi a été modifié correctement.
    QCOMPARE(enemy->getItsState(), false);
    QCOMPARE(enemy->getIsOnTheGround(), true);
}


void test_Game::test_colBtwPlayerAndBlock()
{
    // Créez un joueur et un bloc.
    Player* player = new Player(100, 165, 64, 32, itsTileSet->getItsPlayerTile());
    Block* block = new Block(100, 100, 32, 32, itsTileSet->getItsBlockTile());

    // Faites les entrer en collision.
    itsGame->colBtwPlayerAndBlock(player, block);

    // Vérifiez que l'état du joueur a été modifié correctement.
    QCOMPARE(player->getItsYSpeed(), STILL);
    QCOMPARE(player->getIsOnTheGround(), true);
}


void test_Game::test_colBtwEnemyAndDespawner()
{
    // Créez un ennemi, despawner et un spawner.
    Enemy* enemy = new Enemy(32, 32, itsTileSet->getItsEnemyTile());
    enemy->setX(100);
    enemy->setY(100);

    Spawner* spawner = new Spawner(0, 0, 96, 64, itsTileSet->getItsSpawnerTile(1));

    Despawner* despawner = new Despawner(spawner, 100, 100, 96, 64, itsTileSet->getItsDespawnerTile(1));

    // Faites-les entrer en collision.
    itsGame->colBtwEnemyAndDespawner(enemy, despawner);

    // Vérifiez que les coordonnées X et Y du joueur sont égales à celles du spawner.
        QCOMPARE(itsGame->getItsEnemy()->getItsX(), spawner->getItsX());
        QCOMPARE(itsGame->getItsEnemy()->getItsY(), spawner->getItsY());
}


void test_Game::test_gravity()
{
    // Créez un joueur et quelques ennemis.
    Player* player = new Player(100, 100, 64, 32, itsTileSet->getItsPlayerTile());

    Enemy* enemy = new Enemy(32, 32, itsTileSet->getItsEnemyTile());
    enemy->setX(100);
    enemy->setY(100);

    // Appliquez la gravité.
    itsGame->gravity();

    // Vérifiez que la vitesse Y du joueur et des ennemis a été modifiée.
    QCOMPARE(player->getItsYSpeed(), GRAVITY);
    QCOMPARE(enemy->getItsYSpeed(), GRAVITY);
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
