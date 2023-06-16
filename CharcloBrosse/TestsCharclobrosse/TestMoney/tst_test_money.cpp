#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Money : public QObject
{
    Q_OBJECT
    TileSet * tileSet;
    Money * red;
    Money * yellow;
    Money * bill;

public:
    test_Money();
    ~test_Money();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_Type();

};

test_Money::test_Money()
{

}

test_Money::~test_Money()
{

}

void test_Money::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Money::cleanupTestCase()
{
    delete tileSet;
}

void test_Money::init()
{
    red = new Money(RED, 0, 0, 32, 32, tileSet->getItsMoneyTilesList());
    yellow = new Money(YELLOW, 0, 0, 32, 32, tileSet->getItsMoneyTilesList());
    bill = new Money(BILL, 0, 0, 32, 32, tileSet->getItsMoneyTilesList());
}

void test_Money::cleanup()
{
    delete red;
    delete yellow;
    delete bill;
}

void test_Money::test_Type()
{
    QCOMPARE(red->getItsMoneyType(), RED);
    QCOMPARE(yellow->getItsMoneyType(), YELLOW);
    QCOMPARE(bill->getItsMoneyType(), BILL);
}

QTEST_MAIN(test_Money)

#include "tst_test_money.moc"
