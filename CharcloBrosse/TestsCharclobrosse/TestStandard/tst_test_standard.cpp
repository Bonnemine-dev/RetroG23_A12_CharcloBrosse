#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Standard : public QObject
{
    Q_OBJECT

    Standard * standard;
    TileSet * tileSet;

public:
    test_Standard();
    ~test_Standard();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_type();

};

test_Standard::test_Standard()
{

}

test_Standard::~test_Standard()
{

}

void test_Standard::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Standard::cleanupTestCase()
{
    delete tileSet;
}


void test_Standard::init()
{
    standard = new Standard(32, 32, tileSet->getItsEnnemyStandardTilesList());
}

void test_Standard::cleanup()
{
    delete standard;
}

void test_Standard::test_type()
{
    QCOMPARE(standard->getItsType(), STANDARD);
}

QTEST_MAIN(test_Standard)

#include "tst_test_standard.moc"
