#include <QtTest>
#include <QPainter>
// add necessary includes here
#include "../../CharcloBrosse/block.h"

class test_Block : public QObject
{
    Q_OBJECT

    Block * block;
    QPixmap * sprite; // you might want to use a mock sprite for testing

public:
    test_Block();
    ~test_Block();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

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
    sprite = new QPixmap();
}

void test_Block::cleanupTestCase()
{
    delete sprite;
}

void test_Block::init()
{
    block = new Block(0, 0, 100, 100, sprite);
}

void test_Block::cleanup()
{
    delete block;
}

void test_Block::test_constructor()
{
    QVERIFY(block != nullptr);
}

void test_Block::test_state()
{
    block->setItsState(true);
    QCOMPARE(block->getItsState(), true);
}

void test_Block::test_counter()
{
    QCOMPARE(block->getItsCounter(), (unsigned short)0);
}

void test_Block::test_increment()
{
    block->increment();
    QCOMPARE(block->getItsCounter(), (unsigned short)1);
    QCOMPARE(block->getItsState(), false);
}

QTEST_APPLESS_MAIN(test_Block)

#include "tst_test_block.moc"
