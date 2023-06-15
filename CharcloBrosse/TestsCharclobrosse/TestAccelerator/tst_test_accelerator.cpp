#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_Accelerator : public QObject
{
    Q_OBJECT

public:
    test_Accelerator();
    ~test_Accelerator();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_Accelerator::test_Accelerator()
{

}

test_Accelerator::~test_Accelerator()
{

}

void test_Accelerator::initTestCase()
{

}

void test_Accelerator::cleanupTestCase()
{

}

void test_Accelerator::test_case1()
{

}

QTEST_MAIN(test_Accelerator)

#include "tst_test_accelerator.moc"
