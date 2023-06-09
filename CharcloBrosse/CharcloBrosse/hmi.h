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
#include "level.h"
#include "player.h"
#include "typedef.h"


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
    MenuState state; ///< Current state of the HMI.

    QStackedWidget *stackedWidget; ///< Widget for stacking different screens.
    QWidget *mainMenuWidget; ///< Widget for the main menu screen.
    QWidget *pauseMenuWidget; ///< Widget for the pause menu screen.
    QWidget *gameMenuWidget; ///< Widget for the game screen.
    QWidget *gameOverMenuWidget; ///< Widget for the game over screen.
    QWidget *rulesMenuWidget; ///< Widget for the game rules screen.

    void keyPressEvent(QKeyEvent* event); ///< Handles key press events.
    void keyReleaseEvent(QKeyEvent* event); ///< Handles key release events.

    QVBoxLayout *mainLayout; ///< Main layout for the HMI.
    QVBoxLayout *pauseLayout; ///< Pause layout for the HMI.
    QVBoxLayout *gameOverLayout; ///< Gameover layout for the HMI.
    QVBoxLayout *gameLayout; ///< Game layout for the HMI.
    QVBoxLayout *rulesLayout; ///< Rules layout for the HMI.

    QLabel *rulesText; ///< Label for displaying game rules.

    QLabel *scoresLabel;
    QLabel *scoresLabelGameOver;
    QLabel *gameOverLabel;

    QPushButton *startGameButton; ///< Button for starting the game.
    QPushButton *rulesButton; ///< Button for displaying game rules.
    QPushButton *quitGameButton; ///< Button for quitting the game.
    QPushButton *resumeButton; ///< Button for resuming the game.
    QPushButton *quitToMainButton; ///< Button for going to the main menu.
    QPushButton *quitToMainButton2; ///< Button for going to the main menu from the game over menu.
    QPushButton *goBackButton; ///< Button for going back to the previous screen (main menu).

    Level *itsLevel;
    Player *itsPlayer;
    Game * itsGame;
    QTimer * itsTimer;
    void paintEvent(QPaintEvent* event);
public:
    /**
     * @brief Constructor of the HMI class.
     * @param parent The parent widget.
     */
    HMI(Level *itsLevel, Player *itsPlayer, Game * game, QWidget *parent = nullptr);

    /**
     * @brief Destructor of the HMI class.
     */
    virtual ~HMI();
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

public slots:
    /**
         * @brief Refreshes all components of the HMI.
     */
    void refreshAll();

    void gameLoop();
};


#endif // HMI_H
