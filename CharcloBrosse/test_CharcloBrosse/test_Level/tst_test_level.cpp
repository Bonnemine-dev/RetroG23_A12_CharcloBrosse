#include <QtTest>

// add necessary includes here

class test_Level : public QObject
{
    Q_OBJECT

public:
    test_Level();
    ~test_Level();

private slots:
    void test_case1();

};

test_Level::test_Level()
{

}

test_Level::~test_Level()
{

}

void test_Level::test_case1()
{

}

QTEST_APPLESS_MAIN(test_Level)

#include "tst_test_level.moc"
