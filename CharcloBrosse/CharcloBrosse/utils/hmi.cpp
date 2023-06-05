#include <vector>
#include "hmi.h"

//pour tester :
std::vector<std::pair<std::string, unsigned int>> highs = {
    {"Player1", 100},
    {"Player2", 200},
    {"Player3", 150}
};

HMI::HMI(QWidget *parent) : QWidget(parent)
{
    // Initialisation des widgets pour le main menu
    mainLayout = new QVBoxLayout;
    highscoreList = new QListWidget;
    startGameButton = new QPushButton("Start Game");
    rulesButton = new QPushButton("Rules");
    quitGameButton = new QPushButton("Quit Game");


    // Initialisation des widgets pour le pause menu
    pauseLayout = new QVBoxLayout;
    resumeButton = new QPushButton("Resume");
    quitToMainButton = new QPushButton("Leave the game");


    // Initialisation des widgets pour le game over
    gameOverLayout = new QVBoxLayout;


    // Initialisation des widgets pour le gaming
    gameLayout = new QVBoxLayout;


    //-------------------------
    // Ajout des widgets au layout main menu
    mainLayout->addWidget(highscoreList);
    mainLayout->addWidget(startGameButton);
    mainLayout->addWidget(rulesButton);
    mainLayout->addWidget(quitGameButton);


    // Ajout des widgets au layout pause menu
    pauseLayout->addWidget(resumeButton);
    pauseLayout->addWidget(quitToMainButton);


    // Ajout des widgets au layout game over
    gameOverLayout->addWidget(quitToMainButton);


    // Ajout des widgets au layout gaming


    //-------------------------
    // Définit la couleur d'arrière-plan sur les boutons noirs et de style
    this->setStyleSheet("background-color: black;");

    // Style des boutons
    QString buttonStyle =   "QPushButton {"
                            "background-color: #0000FF;"    // BLEU
                            "border: none;"
                            "color: white;"
                            "padding: 15px 32px;"            // La taille c'est ici
                            "text-align: center;"
                            "text-decoration: none;"
                            "display: inline-block;"
                            "font-size: 16px;"
                            "margin: 4px 2px;"
                            "cursor: pointer;"
                            "border-radius: 1px;"           // l'arondi
                            "}";

    resumeButton->setStyleSheet(buttonStyle);
    resumeButton->setFixedWidth(300);
    quitToMainButton->setStyleSheet(buttonStyle);
    quitToMainButton->setFixedWidth(300);

    // ajustement de la taille de la fenetre
    setFixedSize(20*32, 11*32);


    //-------------------------
    // Connecter les signaux des boutons aux emplacements appropriés pour le main menu
    connect(startGameButton, &QPushButton::clicked, this, &HMI::startGame);
    connect(rulesButton, &QPushButton::clicked, this, &HMI::displayRules);
    connect(quitGameButton, &QPushButton::clicked, this, &QWidget::close);

    // Connecter les signaux des boutons aux emplacements appropriés pour le pause menu
    connect(resumeButton, &QPushButton::clicked, this, &HMI::resume);
    connect(quitToMainButton, &QPushButton::clicked, this, &HMI::leave);



    displayMainMenu(highs);
}


HMI::~HMI()
{
}


void HMI::keyPressEvent(QKeyEvent *event)
{
    //j'envoie un signal quand un touche est appuyé (c'est pour la classe game)
    if (event->key() == Qt::Key_Left)
    {
        emit leftKeyPressed();
    }
    if (event->key() == Qt::Key_Right)
    {
        emit rightKeyPressed();
    }
    if (event->key() == Qt::Key_Up)
    {
        emit upKeyPressed();
    }
    if (event->key() == Qt::Key_Escape && currentLayout == gameLayout)
    {
        displayPauseMenu();
    }
}


void HMI::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        emit leftKeyReleased();
    }
    if (event->key() == Qt::Key_Right)
    {
        emit rightKeyReleased();
    }
}


void HMI::displayMainMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{
    currentLayout = mainLayout;
    this->setStyleSheet("background-color: white;");
    setLayout(mainLayout);
    highscoreList->clear(); // Clear the list before adding new items

        for (const auto &score : highscores) {
            QString scoreText = QString::fromStdString(score.first) + ": " + QString::number(score.second);
            highscoreList->addItem(scoreText);
        }
}

void HMI::displayPauseMenu()
{
    currentLayout = pauseLayout;
    //this->setStyleSheet("background-color: black;");
    setLayout(pauseLayout);
}

void HMI::displayGameOverMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{

}

void HMI::displayGame()
{
    setLayout(pauseLayout);
    currentLayout = gameLayout;
}

void HMI::refreshAll()
{

}

void HMI::startGame()
{
    // tous les autres trucs a mettre
    displayGame();
}

void HMI::displayRules()
{

}

void HMI::close()
{

}

void HMI::resume()
{

}

void HMI::leave()
{
    setLayout(mainLayout);
}

