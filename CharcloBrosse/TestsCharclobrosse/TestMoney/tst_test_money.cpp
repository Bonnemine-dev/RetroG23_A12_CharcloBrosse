#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Money : public QObject
{
    Q_OBJECT

public:
    test_Money();
    ~test_Money();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Money::test_Money()
{

}

test_Money::~test_Money()
{

}

void test_Money::initTestCase()
{

}

void test_Money::cleanupTestCase()
{

}

void test_Money::test_case1()
{

}

QTEST_MAIN(test_Money)

#include "tst_test_money.moc"
