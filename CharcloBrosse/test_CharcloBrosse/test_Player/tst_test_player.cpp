#include <QtTest>
// add necessary includes here
#include "../../CharcloBrosse/player.h"

class test_Player : public QObject
{
    Q_OBJECT

    Player * player;
    QPixmap * sprite;

public:
    test_Player();
    ~test_Player();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_constructor();
    void test_xspeed();
    void test_yspeed();
    void test_lives();
    void test_move();
    void test_isOnTheGround();
};

test_Player::test_Player()
{

}

test_Player::~test_Player()
{

}

void test_Player::initTestCase()
{
    sprite = new QPixmap();
}

void test_Player::cleanupTestCase()
{
    delete sprite;
}

void test_Player::init()
{
    player = new Player(0, 0, 100, 100, sprite);
}

void test_Player::cleanup()
{
    delete player;
}

void test_Player::test_constructor()
{
    QVERIFY(player != nullptr);
}

void test_Player::test_xspeed()
{
    player->setItsXSpeed(5);
    QCOMPARE(player->getItsXSpeed(), (short)5);
}

void test_Player::test_yspeed()
{
    player->setItsYSpeed(7);
    QCOMPARE(player->getItsYSpeed(), (short)7);
}

void test_Player::test_lives()
{
    player->setItsLivesNb(3);
    QCOMPARE(player->getItsLivesNb(), (unsigned short)3);
}

void test_Player::test_move()
{
    player->setItsXSpeed(5);
    player->setItsYSpeed(7);
    player->move();
    QCOMPARE(player->getItsX(), (unsigned short)5);
    QCOMPARE(player->getItsY(), (unsigned short)7);
}

void test_Player::test_isOnTheGround()
{
    player->setIsOnTheGround(true);
    QCOMPARE(player->getIsOnTheGround(), true);
}

QTEST_MAIN(test_Player)

#include "tst_test_player.moc"
