#include "hmi.h"

HMI::HMI(QWidget *parent) : QWidget(parent)
{
    // Initialisation des widgets
    mainLayout = new QVBoxLayout;
    highscoreList = new QListWidget;
    startGameButton = new QPushButton("Start Game");
    rulesButton = new QPushButton("Rules");
    quitGameButton = new QPushButton("Quit Game");

    // Ajout des widgets au layout
    mainLayout->addWidget(highscoreList);
    mainLayout->addWidget(startGameButton);
    mainLayout->addWidget(rulesButton);
    mainLayout->addWidget(quitGameButton);

    // Set layout size

    setFixedSize(40*32, 22*32);

    // Connect button signals to appropriate slots

    connect(startGameButton, &QPushButton::clicked, this, &HMI::startGame);
    connect(rulesButton, &QPushButton::clicked, this, &HMI::displayRules);
    connect(quitGameButton, &QPushButton::clicked, this, &QWidget::close);
}


HMI::~HMI()
{
}


void HMI::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        emit leftKeyPressed();
    }
    if (event->key() == Qt::Key_Right) {
        emit rightKeyPressed();
    }
    if (event->key() == Qt::Key_Up) {
        emit upKeyPressed();
    }
}


void HMI::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        emit leftKeyReleased();
    }
    if (event->key() == Qt::Key_Right) {
        emit rightKeyReleased();
    }
}


void HMI::displayMainMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{
    setLayout(mainLayout);
}

void HMI::displayPauseMenu()
{

}

void HMI::displayGameOverMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{

}

void HMI::refreshAll()
{

}

void HMI::startGame()
{

}

void HMI::displayRules()
{

}

void HMI::close()
{

}
