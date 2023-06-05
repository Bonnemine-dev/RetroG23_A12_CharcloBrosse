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
#include "../Entity/entity.h"

enum MenuState {
    MAINMENU,
    PAUSEMENU,
    GAMEOVER,
    GAME
};




class HMI : public QWidget

{
    Q_OBJECT
private:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    QVBoxLayout *mainLayout;
    QListWidget *highscoreList;
    QPushButton *startGameButton;
    QPushButton *rulesButton;
    QPushButton *quitGameButton;
public:
    HMI(QWidget *parent = nullptr);
    ~HMI();
private slots:
    void displayMainMenu(std::vector <std::pair <std::string , unsigned int >> highscores);
    void displayPauseMenu();
    void displayGameOverMenu(std::vector <std::pair <std::string , unsigned int >> highscores);
    void refreshAll();
};

#endif // HMI_H
