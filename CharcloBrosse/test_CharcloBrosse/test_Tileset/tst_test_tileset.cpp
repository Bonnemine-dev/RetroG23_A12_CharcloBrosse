#include <QtTest>

#include "../../CharcloBrosse/tileset.h"
// add necessary includes here

class test_Tileset : public QObject
{
    Q_OBJECT
private:
    TileSet* itsTileSet;
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

void init()
{
    itsTileset = new TileSet;
}
void cleanup()
{
    delete itsTileset;
}


void test_Tileset::test_constructor()
{

}

QTEST_APPLESS_MAIN(test_Tileset)

#include "tst_test_tileset.moc"
