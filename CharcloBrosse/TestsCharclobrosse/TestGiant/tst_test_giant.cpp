#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Giant : public QObject
{
    Q_OBJECT

    Giant * giant;
    TileSet * tileSet;

public:
    test_Giant();
    ~test_Giant();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_type();
};

test_Giant::test_Giant()
{

}

test_Giant::~test_Giant()
{

}

void test_Giant::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Giant::cleanupTestCase()
{
    delete tileSet;
}

void test_Giant::init()
{
    giant = new Giant(96, 64, tileSet->getItsEnnemyGiantTilesList());
}

void test_Giant::cleanup()
{
    delete giant;
}

void test_Giant::test_type()
{
    QCOMPARE(giant->getItsType(), GIANT);
}

QTEST_MAIN(test_Giant)

#include "tst_test_giant.moc"
