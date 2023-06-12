#ifndef DB_SCORE_H
#define DB_SCORE_H
#include <vector>
#include <string>

/**
 * @class BD_Score
 * @brief Class representing a database for storing scores.
 * This class provides methods for loading and saving scores to a file.
 */
class DB_Score
{
public:
    /**
     * @brief Default constructor for the BD_Score class.
     */
    DB_Score();

    /**
     * @brief Loads the scores from the database.
     * @return A vector of pairs representing the loaded scores.
     *         Each pair contains a name and a score.
     */
    std::vector<std::pair<std::string, unsigned int>> loadScores();


    /**
     * @brief Saves a new score to the database if the score is in the top 10.
     * @param theName The name associated with the score.
     * @param theScore The score to be saved.
     */
    void saveScore(std::string theName, unsigned int theScore);

    /**
     * @brief Checks whether a score is within the top 10.
     * @param theScore The score to check.
     * @return true if the score is within the top 10, false otherwise.
     */
    bool isInTop10(unsigned int theScore);
};

#endif // DB_SCORE_H
