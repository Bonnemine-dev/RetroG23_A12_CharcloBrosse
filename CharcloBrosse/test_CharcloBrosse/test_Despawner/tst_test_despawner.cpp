#include <QtTest>

// add necessary includes here

class test_Despawner : public QObject
{
    Q_OBJECT

public:
    test_Despawner();
    ~test_Despawner();

private slots:
    void test_case1();

};

test_Despawner::test_Despawner()
{

}

test_Despawner::~test_Despawner()
{

}

void test_Despawner::test_case1()
{

}

QTEST_APPLESS_MAIN(test_Despawner)

#include "tst_test_despawner.moc"
