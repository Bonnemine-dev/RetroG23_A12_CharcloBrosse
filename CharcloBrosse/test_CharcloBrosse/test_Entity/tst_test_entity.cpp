#include <QtTest>
#include <QPainter>
// add necessary includes here
#include "../../CharcloBrosse/entity.h"

class test_Entity : public QObject
{
    Q_OBJECT

    Entity * entity;
    QPixmap * sprite;

public:
    test_Entity();
    ~test_Entity();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_constructor();
    void test_coordinates();
    void test_moveTo();
};

test_Entity::test_Entity()
{

}

test_Entity::~test_Entity()
{

}

void test_Entity::initTestCase()
{
    sprite = new QPixmap();
}

void test_Entity::cleanupTestCase()
{
    delete sprite;
}

void test_Entity::init()
{
    entity = new Entity(50, 60, 200, 300, sprite);
}

void test_Entity::cleanup()
{
    delete entity;
}

void test_Entity::test_constructor()
{
    QVERIFY(entity != nullptr);
}

void test_Entity::test_coordinates()
{
    QCOMPARE(entity->getItsX(), (unsigned short)50);
    QCOMPARE(entity->getItsY(), (unsigned short)60);
    QCOMPARE(entity->getItsHeight(), (unsigned short)200);
    QCOMPARE(entity->getItsWidth(), (unsigned short)300);

    entity->setX(100);
    entity->setY(200);
    QCOMPARE(entity->getItsX(), (unsigned short)100);
    QCOMPARE(entity->getItsY(), (unsigned short)200);
}

void test_Entity::test_moveTo()
{
    entity->setX(100);
    entity->setY(200);
    entity->moveTo();

    QCOMPARE(entity->getItsX(), (unsigned short)100);
    QCOMPARE(entity->getItsY(), (unsigned short)200);
}

QTEST_MAIN(test_Entity)

#include "tst_test_entity.moc"
