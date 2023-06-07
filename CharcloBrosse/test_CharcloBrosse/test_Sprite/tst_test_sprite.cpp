#include <QtTest>

// add necessary includes here

class test_Sprite : public QObject
{
    Q_OBJECT

public:
    test_Sprite();
    ~test_Sprite();

private slots:
    void test_case1();

};

test_Sprite::test_Sprite()
{

}

test_Sprite::~test_Sprite()
{

}

void test_Sprite::test_case1()
{

}

QTEST_APPLESS_MAIN(test_Sprite)

#include "tst_test_sprite.moc"
