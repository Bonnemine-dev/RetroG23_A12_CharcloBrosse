#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_DB_Score : public QObject
{
    Q_OBJECT

public:
    test_DB_Score();
    ~test_DB_Score();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_DB_Score::test_DB_Score()
{

}

test_DB_Score::~test_DB_Score()
{

}

void test_DB_Score::initTestCase()
{

}

void test_DB_Score::cleanupTestCase()
{

}

void test_DB_Score::test_case1()
{

}

QTEST_MAIN(test_DB_Score)

#include "tst_test_db_score.moc"
