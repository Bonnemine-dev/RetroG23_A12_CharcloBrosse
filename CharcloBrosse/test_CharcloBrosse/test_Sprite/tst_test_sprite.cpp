#include <QtTest>
#include <QPixmap>
#include <QPainter>
#include "../../CharcloBrosse/sprite.h"

class test_Sprite : public QObject
{
    Q_OBJECT

    Sprite * sprite;
    QPixmap * image;

public:
    test_Sprite();
    ~test_Sprite();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_constructor();
    void test_moveTo();
    // Display test would require a more complex setup and is not included here
};

test_Sprite::test_Sprite()
{

}

test_Sprite::~test_Sprite()
{

}

void test_Sprite::initTestCase()
{
    image = new QPixmap();
}

void test_Sprite::cleanupTestCase()
{
    delete image;
}

void test_Sprite::init()
{
    sprite = new Sprite(image);
}

void test_Sprite::cleanup()
{
    delete sprite;
}

void test_Sprite::test_constructor()
{
    QVERIFY(sprite != nullptr);
}

void test_Sprite::test_moveTo()
{
    sprite->moveTo(10, 20);
    // Verify the new position. This assumes that you have getters for itsX and itsY
    QCOMPARE(sprite->getItsX(), (unsigned short)10);
    QCOMPARE(sprite->getItsY(), (unsigned short)20);
}

QTEST_MAIN(test_Sprite)

#include "tst_test_sprite.moc"
