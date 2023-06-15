#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Block : public QObject
{
    Q_OBJECT
    Block * pow;
    Block * brick;
    Block * obstacle;
    Block * ground;
    TileSet * tileSet;

public:
    test_Block();
    ~test_Block();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_Type();
    void test_constructor();
    void test_state();
    void test_counter();
    void test_increment();
};

test_Block::test_Block()
{

}

test_Block::~test_Block()
{

}

void test_Block::initTestCase()
{
    tileSet = new TileSet(":/ressources/tileset1.png");
}

void test_Block::cleanupTestCase()
{
    delete tileSet;
}

void test_Block::init(){
    pow = new Block(0, 0, 64, 64, tileSet->getItsBlockTilesList(), POW);
    brick = new Block(0,0, 32, 32, tileSet->getItsBlockTilesList(), BRICK);
    obstacle = new Block(0, 0, 32, 32, tileSet->getItsBlockTilesList(), OBSTACLE);
    ground = new Block(0, 0, 32, 32, tileSet->getItsBlockTilesList(), GROUND);
}


void test_Block::cleanup()
{
    delete pow;
    delete brick;
    delete obstacle;
    delete ground;
}
void test_Block::test_Type()
{
    QCOMPARE(pow->getItsType(), POW);
    QCOMPARE(brick->getItsType(), BRICK);
    QCOMPARE(obstacle->getItsType(), OBSTACLE);
    QCOMPARE(ground->getItsType(), GROUND);
}


void test_Block::test_constructor()
{
    QVERIFY(pow != nullptr);
    QVERIFY(brick != nullptr);
    QVERIFY(obstacle != nullptr);
    QVERIFY(ground != nullptr);
}

void test_Block::test_state()
{
    pow->setItsState(true);
    QCOMPARE(pow->getItsState(), true);
    brick->setItsState(true);
    QCOMPARE(brick->getItsState(), true);
    obstacle->setItsState(true);
    QCOMPARE(obstacle->getItsState(), true);
    ground->setItsState(true);
    QCOMPARE(ground->getItsState(), true);
}

void test_Block::test_counter()
{
    QCOMPARE(pow->getItsCounter(), (unsigned short)0);
    QCOMPARE(brick->getItsCounter(), (unsigned short)0);
    QCOMPARE(ground->getItsCounter(), (unsigned short)0);
    QCOMPARE(obstacle->getItsCounter(), (unsigned short)0);
}

void test_Block::test_increment()
{
    pow->increment();
    QCOMPARE(pow->getItsCounter(), (unsigned short)1);
    QCOMPARE(pow->getItsState(), false);
    brick->increment();
    QCOMPARE(brick->getItsCounter(), (unsigned short)1);
    QCOMPARE(brick->getItsState(), false);
    ground->increment();
    QCOMPARE(ground->getItsCounter(), (unsigned short)1);
    QCOMPARE(ground->getItsState(), false);
    obstacle->increment();
    QCOMPARE(obstacle->getItsCounter(), (unsigned short)1);
    QCOMPARE(obstacle->getItsState(), false);
}

QTEST_MAIN(test_Block)

#include "tst_test_block.moc"
