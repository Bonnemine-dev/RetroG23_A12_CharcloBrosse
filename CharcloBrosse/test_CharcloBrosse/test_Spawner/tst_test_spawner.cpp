#include <QtTest>
// add necessary includes here
#include "../../CharcloBrosse/spawner.h"
#include "../../CharcloBrosse/enemy.h"

class test_Spawner : public QObject
{
    Q_OBJECT

    Spawner * spawner;
    Enemy * enemy;
    QPixmap * sprite;

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
    sprite = new QPixmap();
}

void test_Spawner::cleanupTestCase()
{
    delete sprite;
}

void test_Spawner::init()
{
    spawner = new Spawner(0, 64, 100, 100, sprite);
    enemy = new Enemy(32, 32, sprite);
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
    QCOMPARE(enemy->getItsY(), spawner->getItsY());
}

QTEST_MAIN(test_Spawner)

#include "tst_test_spawner.moc"
