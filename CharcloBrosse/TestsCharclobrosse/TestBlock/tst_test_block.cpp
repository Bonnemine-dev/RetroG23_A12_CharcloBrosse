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
    void test_

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


QTEST_MAIN(test_Block)

#include "tst_test_block.moc"
