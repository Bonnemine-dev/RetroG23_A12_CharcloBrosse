#include <QtTest>
#include <QCoreApplication>
#include "../../CharcloBrosse/db_score.h"


class test_DB_Score : public QObject
{
    Q_OBJECT

public:
    test_DB_Score();
    ~test_DB_Score();

private slots:
    void test_saveScore();
    void test_isInTop10();
};

test_DB_Score::test_DB_Score() {}

test_DB_Score::~test_DB_Score() {}

void test_DB_Score::test_saveScore()
{
    DB_Score db;
    unsigned int testScore = 100;

    db.saveScore("TestPlayer", testScore);

    // Vérifier si le score a bien été sauvegardé
    std::vector<std::pair<std::string, unsigned int>> scores = db.loadScores();
    QVERIFY(std::find_if(scores.begin(), scores.end(), [&testScore](const std::pair<std::string, unsigned int>& pair){
        return pair.second == testScore;
    }) != scores.end());
}

void test_DB_Score::test_isInTop10()
{
    DB_Score db;
    unsigned int testScore = 200;

    db.saveScore("TestPlayer", testScore);

    // Vérifier si le score est dans le top 10
    QVERIFY(db.isInTop10(testScore));

    // Vérifier si un score plus bas n'est pas dans le top 10
    QVERIFY(!db.isInTop10(testScore - 1));
}


QTEST_MAIN(test_DB_Score)

#include "tst_test_db_score.moc"
