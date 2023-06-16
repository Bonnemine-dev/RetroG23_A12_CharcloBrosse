/**
 * @file hmi.h
 * @brief Header file for class HMI
 * @date 09/06/2023
 * @version 2.0
 */

#ifndef HMI_H
#define HMI_H

#include <QWidget>
#include <QKeyEvent>
#include <string>
#include <vector>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QLineEdit>
#include "level.h"
#include "player.h"
#include "typedef.h"
#include "db_score.h"


class Game;

/**
 * @class HMI
 * @brief Class representing a Human Machine Interface (HMI) for a game.
 * This class provides methods for handling user input and displaying game states,
 * including main menu, pause menu, game over screen, and game screen.
 * It also includes slots for displaying high scores and game rules.
 * @date June 2023
 */
class HMI : public QWidget
{
    Q_OBJECT
private:
    QPixmap *rulesImage; /** @brief  The key bind image. */

    DB_Score *DBSCORE; /** @brief  The object that we use for database methods. */

    MenuState state; /** @brief  Current state of the HMI. */


    QStackedWidget *stackedWidget; /** @brief  Widget for stacking different screens. */
    QWidget *mainMenuWidget; /** @brief  Widget for the main menu screen. */
    QWidget *pauseMenuWidget; /** @brief  Widget for the pause menu screen. */
    QWidget *gameMenuWidget; /** @brief  Widget for the game screen. */
    QWidget *gameOverMenuWidget; /** @brief  Widget for the game over screen. */
    QWidget *rulesMenuWidget; /** @brief  Widget for the game rules screen. */
    QWidget *gameOverTop10MenuWidget; /** @brief Widget for the game over screen with top 10 add score */

    void keyPressEvent(QKeyEvent* event); /** @brief  Handles key press events. */
    void keyReleaseEvent(QKeyEvent* event); /** @brief  Handles key release events. */

    QVBoxLayout *mainLayout; /** @brief  Main layout for the main menu. */
    QHBoxLayout *middleLayout; /** @brief  Layout for the middle section of the main menu. */
    QVBoxLayout *leftLayout; /** @brief  Layout for the left section of the main menu. */
    QVBoxLayout *rightLayout; /** @brief  Layout for the right section of the main menu. */
    QVBoxLayout *pauseLayout; /** @brief  Pause layout for the HMI. */
    QVBoxLayout *gameOverLayout; /** @brief  Gameover layout for the HMI. */
    QVBoxLayout *gameLayout; /** @brief  Game layout for the HMI. */
    QVBoxLayout *rulesLayout; /** @brief  Rules layout for the HMI. */
    QVBoxLayout *levelLayout; /** @brief  Layout for displaying level n°. */

    QLabel *gameTitleLabel; /** @brief  Label for displaying "Chaclo Brosse". */
    QLabel *rulesText; /** @brief  Label for displaying game rules. */
    QLabel *rulesImageLabel; /** @brief  Label for displaying game rules with the key bind image. */
    QVBoxLayout *gameOverTop10Layout; /** @brief Layout for displaying GameOver Layout with Top 10 submit */

    QLabel *congratulationsMessage; /** @brief Label for displaying the congratulation message */

    QLabel *scoresLabel; /** @brief  Label for displaying scores. */
    QLabel *scoreLabelGameOver; /** @brief  Label for displaying scores in the game over screen. */
    QLabel *gameOverLabel; /** @brief  Label for displaying "Game Over" text. */

    QPushButton *startGameButton; /** @brief  Button for starting the game. */
    QPushButton *rulesButton; /** @brief  Button for displaying game rules. */
    QPushButton *quitGameButton; /** @brief  Button for quitting the game. */
    QPushButton *resumeButton; /** @brief  Button for resuming the game. */
    QPushButton *quitToMainButton; /** @brief  Button for going to the main menu. */
    QPushButton *quitToMainButton2; /** @brief  Button for going to the main menu from the game over menu. */
    QPushButton *goBackButton; /** @brief  Button for going back to the previous screen (main menu). */
    QPushButton *submitScoreButton; /** @brief Button to submit our score */
    QLineEdit *nameInput;/** @brief text entry to submit our name */

    /**
     * @brief itsLevelNumberText the text to display the the current level before launch it
     */
    QLabel *itsLevelNumberText;

    Level *itsLevel = nullptr; /** @brief  Pointer to the current level object. */
    Player *itsPlayer; /** @brief  Pointer to the player object. */
    Game *itsGame; /** @brief  Pointer to the game object. */
    QTimer *itsTimer; /** @brief  Timer for game updates. */
    /**
     * @brief itsStartLevelTimer the timer to display the level number only during 1 seconds
     */
    QTimer *itsStartLevelTimer;
    /**
     * @brief itsLevelTimer the timer for the maximum time to do a level
     */
    QTimer *itsLevelTimer;



    /**
     * @brief Redefinition of the paintEvent method to perform custom drawings.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent* event);

    /**
     * @brief Clears previously drawn items.
     */
    void clearPaintings();

    bool shouldDraw = true; /** @brief  Boolean indicating whether drawing should be performed or not. */

    /**
     * @brief timeRemaining the time reamaining to do the level (only use to pause game)
     */
    long long timeRemaining;
public:
    /**
     * @brief Constructor of the HMI class.
     * @param parent The parent widget.
     */
    HMI(Player *itsPlayer, Game * game, QWidget *parent = nullptr);

    /**
     * @brief Destructor of the HMI class.
     */
    virtual ~HMI();

    void setLevel(Level * level);

    /**
     * @brief displayLevelNumber display th current level number at the screen
     * Display the current number of the level during one seconds
     */
    void displayLevelNumber();

    /**
     * @brief getTimerRemainingTime get the remaining time of the current level timer
     * @return the time remaining in secondes
     */
    int getTimerRemainingTime();
private slots:
    /**
     * @brief Displays the main menu.
     * @param highscores List of high scores to be displayed.
     */
    void displayMainMenu(std::vector <std::pair <std::string , unsigned int >> highscores);

    /**
     * @brief Displays the pause menu.
     */
    void displayPauseMenu();

    /**
     * @brief Displays the game over menu.
     * @param highscores List of high scores to be displayed.
     */
    void displayGameOverMenu();

    void displayGameOverMenuTOP10();
    /**
         * @brief Displays the game screen.
     */
    void displayGame();

    /**
     * @brief Starts the game.
     */
    void startGame();

    /**
     * @brief Displays the game rules.
     */
    void displayRules();

    /**
     * @brief Closes the HMI.
     */
    void close();

    /**
     * @brief Resumes the game.
     */
    void resume();

    /**
     * @brief Leaves the game.
     */
    void leave();

    /**
     * @brief startLevel display the level number before the level;
     */
    void startLevel();

    /**
     * @brief levelTimeout terminate the level when the time is ellapsed
     */
    void levelTimeout();


public slots:
    /**
         * @brief Refreshes all components of the HMI.
     */
    void refreshAll();

    /**
     * @brief The main game loop for handling game updates.
     */
    void gameLoop();

    /**
     * @brief Stops the game and performs necessary cleanup.
     */
    void stopGame();

    /**
     * @brief Submits the score after clicking on the submit button.
     */
    void submitScore();

};


#endif // HMI_H

