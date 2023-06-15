#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Spawner : public QObject
{
    Q_OBJECT

public:
    test_Spawner();
    ~test_Spawner();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Spawner::test_Spawner()
{

}

test_Spawner::~test_Spawner()
{

}

void test_Spawner::initTestCase()
{

}

void test_Spawner::cleanupTestCase()
{

}

void test_Spawner::test_case1()
{

}

QTEST_MAIN(test_Spawner)

#include "tst_test_spawner.moc"
