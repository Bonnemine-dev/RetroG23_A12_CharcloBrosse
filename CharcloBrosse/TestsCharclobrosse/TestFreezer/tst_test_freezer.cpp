#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/freezer.h"
#include "../../CharcloBrosse/tileset.h"

class test_Freezer : public QObject
{
    Q_OBJECT

    Freezer * freezer;
    TileSet * tileSet;

public:
    test_Freezer();
    ~test_Freezer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_type();

};

test_Freezer::test_Freezer()
{

}

test_Freezer::~test_Freezer()
{

}

void test_Freezer::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Freezer::cleanupTestCase()
{
    delete tileSet;
}

void test_Freezer::init()
{
    freezer = new Freezer(32, 32, tileSet->getItsEnnemyFreezerTilesList());
}

void test_Freezer::cleanup()
{
    delete freezer;
}

void test_Freezer::test_type()
{
    QCOMPARE(freezer->getItsType(), FREEZER);
}

QTEST_MAIN(test_Freezer)

#include "tst_test_freezer.moc"
