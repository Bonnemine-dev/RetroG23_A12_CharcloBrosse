#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Jumper : public QObject
{
    Q_OBJECT

public:
    test_Jumper();
    ~test_Jumper();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Jumper::test_Jumper()
{

}

test_Jumper::~test_Jumper()
{

}

void test_Jumper::initTestCase()
{

}

void test_Jumper::cleanupTestCase()
{

}

void test_Jumper::test_case1()
{

}

QTEST_MAIN(test_Jumper)

#include "tst_test_jumper.moc"
