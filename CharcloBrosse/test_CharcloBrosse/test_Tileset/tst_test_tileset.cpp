#include <QtTest>

// add necessary includes here

class test_Tileset : public QObject
{
    Q_OBJECT

public:
    test_Tileset();
    ~test_Tileset();

private slots:
    void init();
    void cleanup();

    void test_constructor();

};

test_Tileset::test_Tileset()
{

}

test_Tileset::~test_Tileset()
{

}

void test_Tileset::test_case1()
{

}

QTEST_APPLESS_MAIN(test_Tileset)

#include "tst_test_tileset.moc"
