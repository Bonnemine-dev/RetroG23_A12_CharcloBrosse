#include <QtTest>

// add necessary includes here

class test_Game : public QObject
{
    Q_OBJECT

public:
    test_Game();
    ~test_Game();

private slots:
    void test_case1();

};

test_Game::test_Game()
{

}

test_Game::~test_Game()
{

}

void test_Game::test_case1()
{

}

QTEST_APPLESS_MAIN(test_Game)

#include "tst_test_game.moc"
