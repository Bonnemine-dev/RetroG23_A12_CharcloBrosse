#include <QApplication>
#include <vector>
#include "hmi.h"

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
    quitToMainButton2 = new QPushButton("Leave the game");

    // Initialisation des widgets pour le gaming
    gameLayout = new QVBoxLayout;

    // Initialisation des widgets pour le rules menu
    rulesLayout = new QVBoxLayout;
    rulesText = new QLabel("Charclo Brosse est un jeu super cool #EmojiLunettesDeSoleil");
    goBackButton = new QPushButton("Go back");

    //-------------------------
    // Ajout des widgets au layout main menu
    mainLayout->addWidget(highscoreList);
    highscoreList->setFocusPolicy(Qt::NoFocus);
    mainLayout->addWidget(startGameButton);
    mainLayout->addWidget(rulesButton);
    mainLayout->addWidget(quitGameButton);

    // Ajout des widgets au layout pause menu
    pauseLayout->addWidget(resumeButton);
    pauseLayout->addWidget(quitToMainButton);

    // Ajout des widgets au layout game over
    gameOverLayout->addWidget(quitToMainButton2);

    // Ajout des widgets au layout gaming

    // Ajout des widgets au layout rules
    rulesLayout->addWidget(rulesText);
    rulesLayout->addWidget(goBackButton);

    // Création des widgets
    mainMenuWidget = new QWidget;
    pauseMenuWidget = new QWidget;
    gameMenuWidget = new QWidget;
    gameOverMenuWidget = new QWidget;
    rulesMenuWidget = new QWidget;

    // Ajout des layouts aux widgets correspondants
    mainMenuWidget->setLayout(mainLayout);
    pauseMenuWidget->setLayout(pauseLayout);
    gameMenuWidget->setLayout(gameLayout);
    gameOverMenuWidget->setLayout(gameOverLayout);
    rulesMenuWidget->setLayout(rulesLayout);

    // Création du stackedWidget et ajout des différents widgets
    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(mainMenuWidget);
    stackedWidget->addWidget(pauseMenuWidget);
    stackedWidget->addWidget(gameMenuWidget);
    stackedWidget->addWidget(gameOverMenuWidget);
    stackedWidget->addWidget(rulesMenuWidget);

    // Define the layout of the parent widget to contain the stackedWidget
    QVBoxLayout *mainWindowLayout = new QVBoxLayout(this);
    mainWindowLayout->addWidget(stackedWidget);

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
                                "font-size: 16px;"
                                "margin: 4px 2px;"
                                "border-radius: 1px;"           // l'arondi
                                "}";

    resumeButton->setStyleSheet(buttonStyle);
    resumeButton->setFixedWidth(300);
    quitToMainButton->setStyleSheet(buttonStyle);
    quitToMainButton->setFixedWidth(300);

    // ajustement de la taille de la fenetre
    setFixedSize(20*32*2, 11*32*2);

    //-------------------------
    // Connecter les signaux des boutons aux emplacements appropriés pour le main menu
    connect(startGameButton, &QPushButton::clicked, this, &HMI::startGame);
    connect(rulesButton, &QPushButton::clicked, this, &HMI::displayRules);
    connect(quitGameButton, &QPushButton::clicked, this, &QWidget::close);

    // Connecter les signaux des boutons aux emplacements appropriés pour le pause menu
    connect(resumeButton, &QPushButton::clicked, this, &HMI::resume);
    connect(quitToMainButton, &QPushButton::clicked, this, &HMI::leave);

    // Connecter les signaux des boutons aux emplacements appropriés pour le rules menu
    connect(goBackButton, &QPushButton::clicked, this, &HMI::leave);

    // Définir la politique de focus pour permettre la navigation entre les boutons
    startGameButton->setFocusPolicy(Qt::StrongFocus);
    rulesButton->setFocusPolicy(Qt::StrongFocus);
    quitGameButton->setFocusPolicy(Qt::StrongFocus);

    // Définir le bouton par défaut pour activer avec la touche Entrée
    startGameButton->setDefault(true);

    displayMainMenu(highs);
}

HMI::~HMI()
{
}

void HMI::keyPressEvent(QKeyEvent *event)
{
    //j'envoie un signal quand une touche est appuyée (c'est pour la classe game)
    if (event->key() == Qt::Key_Left && state == GAME)
    {
        emit leftKeyPressed();
    }
    if (event->key() == Qt::Key_Right && state == GAME)
    {
        emit rightKeyPressed();
    }
    if (event->key() == Qt::Key_Up && state == GAME)
    {
        emit upKeyPressed();
    }
    if (event->key() == Qt::Key_Escape && state == GAME)
    {
        displayPauseMenu();
    }
    if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_Right || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) && state != GAME)
        {
            QWidget::keyPressEvent(event); // Laisser le traitement des touches fléchées par défaut
        }
        else if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) && state != GAME)
        {
            // Récupérer le widget qui a le focus actuel
            QWidget *focusedWidget = QApplication::focusWidget();

            // Vérifier si c'est un QPushButton et l'activer
            QPushButton *button = qobject_cast<QPushButton*>(focusedWidget);
            if (button != nullptr)
            {
                button->click(); // Simuler le clic sur le bouton
            }
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
    if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_Right || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) && state != GAME)
    {
        QWidget::keyReleaseEvent(event); // Laisser le traitement des touches fléchées par défaut
    }
}

void HMI::displayMainMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{
    state = MAINMENU;
    this->setStyleSheet("background-color: white;");
    stackedWidget->setCurrentWidget(mainMenuWidget);
    highscoreList->clear();

    for (const auto &score : highscores) {
        QString scoreText = QString::fromStdString(score.first) + ": " + QString::number(score.second);
        highscoreList->addItem(scoreText);
    }
}

void HMI::displayPauseMenu()
{
    emit gamePaused();
    state = PAUSEMENU;
    stackedWidget->setCurrentWidget(pauseMenuWidget);
}

void HMI::displayGameOverMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{
    state = GAMEOVER;
    stackedWidget->setCurrentWidget(gameOverMenuWidget);
    highscoreList->clear();

    for (const auto &score : highscores) {
        QString scoreText = QString::fromStdString(score.first) + ": " + QString::number(score.second);
        highscoreList->addItem(scoreText);
    }
}

void HMI::displayGame()
{
    state = GAME;
    stackedWidget->setCurrentWidget(gameMenuWidget);
}

void HMI::displayRules()
{
    stackedWidget->setCurrentWidget(rulesMenuWidget);
}


void HMI::startGame()
{
    displayGame();
}


void HMI::close()
{

}

void HMI::resume()
{
    displayGame();
}

void HMI::leave()
{
    stackedWidget->setCurrentWidget(mainMenuWidget);
}


void HMI::refreshAll(Level *level, Player *player)
{
    QPainter * painter = new QPainter(this);
    level->display(painter);
    player->display(painter);
    painter->end();
}
