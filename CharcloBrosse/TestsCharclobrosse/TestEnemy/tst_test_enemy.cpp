#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Enemy : public QObject
{
    Q_OBJECT

public:
    test_Enemy();
    ~test_Enemy();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Enemy::test_Enemy()
{

}

test_Enemy::~test_Enemy()
{

}

void test_Enemy::initTestCase()
{

}

void test_Enemy::cleanupTestCase()
{

}

void test_Enemy::test_case1()
{

}

QTEST_MAIN(test_Enemy)

#include "tst_test_enemy.moc"
