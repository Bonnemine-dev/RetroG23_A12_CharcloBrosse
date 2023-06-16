#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Accelerator : public QObject
{
    Q_OBJECT

    Accelerator * accel;
    TileSet * tileSet;

public:
    test_Accelerator();
    ~test_Accelerator();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_type();
    void test_speedState();

};

test_Accelerator::test_Accelerator()
{

}

test_Accelerator::~test_Accelerator()
{

}

void test_Accelerator::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Accelerator::cleanupTestCase()
{
    delete tileSet;
}

void test_Accelerator::init()
{
    accel = new Accelerator(32, 32, tileSet->getItsEnnemyAcceleratorTilesList());
}

void test_Accelerator::cleanup()
{
    delete accel;
}

void test_Accelerator::test_type()
{
    QCOMPARE(accel->getItsType(), ACCELERATOR);
}

void test_Accelerator::test_speedState()
{
    QCOMPARE(accel->getItsSpeedState(), 1);
    accel->addItsSpeedState();
    QCOMPARE(accel->getItsSpeedState(), 5);
    accel->addItsSpeedState();
    QCOMPARE(accel->getItsSpeedState(), 9);
    accel->addItsSpeedState();
    QCOMPARE(accel->getItsSpeedState(), 9);
}


QTEST_MAIN(test_Accelerator)

#include "tst_test_accelerator.moc"
