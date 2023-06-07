#include <QtTest>
// add necessary includes here
#include "../../CharcloBrosse/enemy.h"

class test_Enemy : public QObject
{
    Q_OBJECT

    Enemy * enemy;
    QPixmap * sprite;

public:
    test_Enemy();
    ~test_Enemy();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_constructor();
    void test_xspeed();
    void test_yspeed();
    void test_state();
    void test_move();
    void test_isOnTheGround();
    // add other tests as needed
};

test_Enemy::test_Enemy()
{

}

test_Enemy::~test_Enemy()
{

}

void test_Enemy::initTestCase()
{
    sprite = new QPixmap();
}

void test_Enemy::cleanupTestCase()
{
    delete sprite;
}

void test_Enemy::init()
{
    enemy = new Enemy(100, 100, sprite);
}

void test_Enemy::cleanup()
{
    delete enemy;
}

void test_Enemy::test_constructor()
{
    QVERIFY(enemy != nullptr);
}

void test_Enemy::test_xspeed()
{
    enemy->setItsXSpeed(5);
    QCOMPARE(enemy->getItsXSpeed(), (short)5);
}

void test_Enemy::test_yspeed()
{
    enemy->setItsYSpeed(7);
    QCOMPARE(enemy->getItsYSpeed(), (short)7);
}

void test_Enemy::test_state()
{
    enemy->setItsState(true);
    QCOMPARE(enemy->getItsState(), true);
}

void test_Enemy::test_move()
{
    enemy->setItsXSpeed(5);
    enemy->setItsYSpeed(7);
    enemy->move();
    QCOMPARE(enemy->getItsX(), (unsigned short)5);
    QCOMPARE(enemy->getItsY(), (unsigned short)7);
}

void test_Enemy::test_isOnTheGround()
{
    enemy->setIsOnTheGround(true);
    QCOMPARE(enemy->getIsOnTheGround(), true);
}

// Add other tests as needed

QTEST_MAIN(test_Enemy)

#include "tst_test_enemy.moc"
