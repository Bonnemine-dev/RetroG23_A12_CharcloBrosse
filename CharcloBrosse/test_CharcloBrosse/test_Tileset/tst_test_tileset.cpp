#include <QtTest>
#include <QGuiApplication>
#include <QPixmap>
#include "../../CharcloBrosse/tileset.h"
// add necessary includes here

class test_Tileset : public QObject
{
    Q_OBJECT
private:
    //    std::string itsTilesetFilePath = "../../../CharcloBrosse/CharcloBrosse/ressources/tileset0.png";
    std::string itsTilesetFileUnreadablePath = "../../../CharcloBrosse/CharcloBrosse/ressources/notexist.png";
    TileSet* itsTileset;
public:
    test_Tileset();
    ~test_Tileset();

private slots:
    void init();
    void cleanup();

    //    void test_Constructor_UnreadableFile_Exception();
    void test_Constructor_Generals();
};

test_Tileset::test_Tileset()
{

}

test_Tileset::~test_Tileset()
{

}

void test_Tileset::init()
{
    try
    {
        itsTileset = new TileSet("../../CharcloBrosse/ressources/tileset_test.png");
        delete itsTileset;
    }
    catch(const std::string exceptionMessage)
    {
        if(exceptionMessage == "File unfound (Tileset::Tileset(const std:string aFilePath)")
        {
            QFAIL("File not found");
        }
    }
}

void test_Tileset::cleanup()
{
    delete itsTileset;
}

//void test_Tileset::test_Constructor_UnreadableFile_Exception()
//{
//    // Définir le chemin d'accès à un fichier inexistant
//    std::string filePath = "chemin/vers/fichier/inexistant.png";

//    // Vérifier si l'exception est lancée
//    QVERIFY_EXCEPTION_THROWN(TileSet tileSet(filePath),std::string);
//}

void test_Tileset::test_Constructor_Generals()
{
    QPixmap* BLOCK_TEST = new QPixmap(32,32);
    QColor* COLOR_BLOCK_TEST = new QColor(255,0,0,255);
    BLOCK_TEST->fill(*COLOR_BLOCK_TEST);
    delete COLOR_BLOCK_TEST;
    QCOMPARE(itsTileset->getItsBlockTile(),BLOCK_TEST);
    delete BLOCK_TEST;
}

QTEST_MAIN(test_Tileset)

#include "tst_test_tileset.moc"
