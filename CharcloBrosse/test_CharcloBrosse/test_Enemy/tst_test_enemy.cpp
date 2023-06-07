#include <QtTest>

// add necessary includes here

class test_Enemy : public QObject
{
    Q_OBJECT

public:
    test_Enemy();
    ~test_Enemy();

private slots:
    void test_case1();

};

test_Enemy::test_Enemy()
{

}

test_Enemy::~test_Enemy()
{

}

void test_Enemy::test_case1()
{

}

QTEST_APPLESS_MAIN(test_Enemy)

#include "tst_test_enemy.moc"
