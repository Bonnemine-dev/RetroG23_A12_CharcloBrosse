#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Player : public QObject
{
    Q_OBJECT

public:
    test_Player();
    ~test_Player();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Player::test_Player()
{

}

test_Player::~test_Player()
{

}

void test_Player::initTestCase()
{

}

void test_Player::cleanupTestCase()
{

}

void test_Player::test_case1()
{

}

QTEST_MAIN(test_Player)

#include "tst_test_player.moc"
