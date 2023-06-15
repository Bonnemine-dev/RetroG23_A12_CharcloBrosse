#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Block : public QObject
{
    Q_OBJECT

public:
    test_Block();
    ~test_Block();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Block::test_Block()
{

}

test_Block::~test_Block()
{

}

void test_Block::initTestCase()
{

}

void test_Block::cleanupTestCase()
{

}

void test_Block::test_case1()
{

}

QTEST_MAIN(test_Block)

#include "tst_test_block.moc"
