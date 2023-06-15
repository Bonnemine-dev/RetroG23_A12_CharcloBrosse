#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Giant : public QObject
{
    Q_OBJECT

public:
    test_Giant();
    ~test_Giant();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Giant::test_Giant()
{

}

test_Giant::~test_Giant()
{

}

void test_Giant::initTestCase()
{

}

void test_Giant::cleanupTestCase()
{

}

void test_Giant::test_case1()
{

}

QTEST_MAIN(test_Giant)

#include "tst_test_giant.moc"
