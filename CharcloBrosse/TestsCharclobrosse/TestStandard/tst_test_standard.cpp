#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Standard : public QObject
{
    Q_OBJECT

public:
    test_Standard();
    ~test_Standard();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Standard::test_Standard()
{

}

test_Standard::~test_Standard()
{

}

void test_Standard::initTestCase()
{

}

void test_Standard::cleanupTestCase()
{

}

void test_Standard::test_case1()
{

}

QTEST_MAIN(test_Standard)

#include "tst_test_standard.moc"
