#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/game.h"

class test_Game : public QObject
{
    Q_OBJECT

public:
    test_Game();
    ~test_Game();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Game::test_Game()
{

}

test_Game::~test_Game()
{

}

void test_Game::initTestCase()
{

}

void test_Game::cleanupTestCase()
{

}

void test_Game::test_case1()
{

}

QTEST_MAIN(test_Game)

#include "tst_test_game.moc"
