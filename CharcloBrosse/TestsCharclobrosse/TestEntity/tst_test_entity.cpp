#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../../CharcloBrosse/entity.h"

class test_Entity : public QObject
{
    Q_OBJECT
    Entity * entity;

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
    void test_setX();
    void test_setY();

};

test_Entity::test_Entity()
{

}

test_Entity::~test_Entity()
{

}

void test_Entity::initTestCase()
{

}

void test_Entity::cleanupTestCase()
{

}

void test_Entity::init()
{
    entity = new Entity(50, 60, 200, 300);
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
}

void test_Entity::test_setX()
{
    entity->setX(100);
    QCOMPARE(entity->getItsX(), (unsigned short)100);
    QCOMPARE(entity->getItsHeight(), (unsigned short)200);
    QCOMPARE(entity->getItsWidth(), (unsigned short)300);
}

void test_Entity::test_setY()
{
    entity->setY(100);
    QCOMPARE(entity->getItsY(), (unsigned short)100);
    QCOMPARE(entity->getItsHeight(), (unsigned short)200);
    QCOMPARE(entity->getItsWidth(), (unsigned short)300);
}

QTEST_MAIN(test_Entity)

#include "tst_test_entity.moc"
