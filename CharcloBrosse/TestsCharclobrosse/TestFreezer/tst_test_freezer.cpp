#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Freezer : public QObject
{
    Q_OBJECT

public:
    test_Freezer();
    ~test_Freezer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Freezer::test_Freezer()
{

}

test_Freezer::~test_Freezer()
{

}

void test_Freezer::initTestCase()
{

}

void test_Freezer::cleanupTestCase()
{

}

void test_Freezer::test_case1()
{

}

QTEST_MAIN(test_Freezer)

#include "tst_test_freezer.moc"
