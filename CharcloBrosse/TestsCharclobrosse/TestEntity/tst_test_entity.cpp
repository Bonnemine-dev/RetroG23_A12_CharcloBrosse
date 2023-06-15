#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Entity : public QObject
{
    Q_OBJECT

public:
    test_Entity();
    ~test_Entity();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

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

void test_Entity::test_case1()
{

}

QTEST_MAIN(test_Entity)

#include "tst_test_entity.moc"
