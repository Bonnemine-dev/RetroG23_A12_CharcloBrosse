#include <QtTest>
#include "../../CharcloBrosse/tileset.h"
// add necessary includes here

class test_Tileset : public QObject
{
    Q_OBJECT
private:
    TileSet* itsTileset;
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

void test_Tileset::init()
{
    itsTileset = new TileSet("../../CharcloBrosse/ressources/tileset0.png");
}
void test_Tileset::cleanup()
{
    delete itsTileset;
}


void test_Tileset::test_constructor()
{

}

QTEST_APPLESS_MAIN(test_Tileset)

#include "tst_test_tileset.moc"
