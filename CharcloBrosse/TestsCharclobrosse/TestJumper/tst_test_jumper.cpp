#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/jumper.h"
#include "../../CharcloBrosse/tileset.h"

class test_Jumper : public QObject
{
    Q_OBJECT

    Jumper * jumper;
    TileSet * tileSet;

public:
    test_Jumper();
    ~test_Jumper();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_type();
};

test_Jumper::test_Jumper()
{

}

test_Jumper::~test_Jumper()
{

}

void test_Jumper::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Jumper::cleanupTestCase()
{
    delete tileSet;
}

void test_Jumper::init()
{
    jumper = new Jumper(32, 32, tileSet->getItsEnnemyJumperTilesList());
}

void test_Jumper::cleanup()
{
    delete jumper;
}

void test_Jumper::test_type()
{
    QCOMPARE(jumper->getItsType(), JUMPER);
    QCOMPARE(jumper->getJump(), false);
}

QTEST_MAIN(test_Jumper)

#include "tst_test_jumper.moc"
