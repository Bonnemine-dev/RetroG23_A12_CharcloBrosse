#include <QApplication>
#include <iostream>
#include <vector>
#include "hmi.h"
#include "game.h"

std::vector<std::pair<std::string, unsigned int>> highs = {
    {"Player1", 100},
    {"Player2", 200},
    {"Player3", 150}
};

HMI::HMI(Level * level, Player * player, Game * game, QWidget *parent) : QWidget(parent), itsLevel(level), itsPlayer(player), itsGame(game)
{

    // Initialisation des widgets pour le main menu
    mainLayout = new QVBoxLayout;
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
    gameOverLabel = new QLabel("GAME OVER", this);
    gameOverLabel->setAlignment(Qt::AlignCenter);  // Centre le texte dans le QLabel
    QFont gameOverFont = gameOverLabel->font();
    gameOverFont.setPointSize(48); // ajustez la taille de la police comme vous le souhaitez
    gameOverLabel->setFont(gameOverFont);

    gameOverLayout->addWidget(gameOverLabel, 0, Qt::AlignCenter);

    // Initialisation des widgets pour le gaming
    gameLayout = new QVBoxLayout;

    // Initialisation des widgets pour le rules menu
    rulesLayout = new QVBoxLayout;
    rulesText = new QLabel("Charclo Brosse est un jeu super cool #EmojiLunettesDeSoleil");
    goBackButton = new QPushButton("Go back");

    // Initialisation du QLabel pour le highscoreList du main
    scoresLabel = new QLabel(this);
    scoresLabel->setAlignment(Qt::AlignCenter);  // Centre le texte dans le QLabel
    mainLayout->addWidget(scoresLabel, 0, Qt::AlignCenter);
    QFont font = scoresLabel->font();
    font.setPointSize(18); // ajustez la taille de la police comme vous le souhaitez
    scoresLabel->setFont(font);

    // Initialisation du QLabel pour le highscoreList du main
    scoresLabelGameOver = new QLabel(this);


    //-------------------------
    // Ajout des widgets au layout main menu
    mainLayout->addStretch();
    mainLayout->addWidget(startGameButton, 0, Qt::AlignCenter);
    mainLayout->addWidget(rulesButton, 0, Qt::AlignCenter);
    mainLayout->addWidget(quitGameButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    // Ajout des widgets au layout pause menu
    pauseLayout->addStretch();
    pauseLayout->addWidget(resumeButton, 0, Qt::AlignCenter);
    pauseLayout->addWidget(quitToMainButton, 0, Qt::AlignCenter);
    pauseLayout->addStretch();

    // Ajout des widgets au layout game over
    gameOverLayout->addWidget(quitToMainButton2, 0, Qt::AlignCenter);

    font.setPointSize(18); // ajustez la taille de la police comme vous le souhaitez
    scoresLabelGameOver->setFont(font);

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
    // Style des boutons
    QString buttonStyle = "QPushButton {"
                          "background: transparent;"
                          "color: black;"
                          "padding: 15px 32px;"
                          "text-align: center;"
                          "text-decoration: none;"
                          "font-size: 32px;"
                          "margin: 4px 2px;"
                          "}";

    QString buttonFocusedStyle = "QPushButton:focus {"
                                 "color: red;"
                                 "}";

    QString buttonHoverStyle = "QPushButton:hover {"
                               "color: rgba(255, 0, 0, 0.5);"
                               "}";

    resumeButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    resumeButton->setFixedWidth(300);
    quitToMainButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    quitToMainButton->setFixedWidth(300);
    startGameButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    startGameButton->setFixedWidth(300);
    rulesButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    rulesButton->setFixedWidth(300);
    quitGameButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    quitGameButton->setFixedWidth(300);
    quitToMainButton2->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    quitToMainButton2->setFixedWidth(300);

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

    // Connecter les signaux des boutons aux emplacements appropriés pour le game over menu
    connect(quitToMainButton2, &QPushButton::clicked, this, &HMI::leave);

    // Définir la politique de focus pour permettre la navigation entre les boutons
    startGameButton->setFocusPolicy(Qt::StrongFocus);
    rulesButton->setFocusPolicy(Qt::StrongFocus);
    quitGameButton->setFocusPolicy(Qt::StrongFocus);

    itsTimer = new QTimer(this);
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));

    displayMainMenu(highs);
}

HMI::~HMI()
{
}

void HMI::keyPressEvent(QKeyEvent *event)
{
    //j'envoie un signal quand une touche est appuyée (c'est pour la classe game)
    //    if (event->key() == Qt::Key_E && state == GAME)
    //    {
    //        itsGame->gameLoop();
    //    }

    if (event->key() == Qt::Key_Left && state == GAME)
    {
        itsGame->onLeftKeyPressed();
    }
    if (event->key() == Qt::Key_Right && state == GAME)
    {
        itsGame->onRightKeyPressed();
    }
    if (event->key() == Qt::Key_Up && state == GAME){
        itsGame->onUpKeyPressed();
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
        itsGame->onLeftKeyReleased();
    }
    if (event->key() == Qt::Key_Right)
    {
        itsGame->onRightKeyReleased();
    }
    if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_Right || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) && state != GAME)
    {
        QWidget::keyReleaseEvent(event); // Laisser le traitement des touches fléchées par défaut
    }
}

void HMI::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if (itsLevel->isActive() && shouldDraw){
        unsigned int score = itsGame->getItsScore();
        short lives = itsGame->getItsPlayer()->getItsLivesNb();
        QPainter * painter = new QPainter(this);
        painter->drawText(10, 20, QString("Score: %1").arg(score)); // Le texte apparaîtra à 10 pixels du bord gauche et à 20 pixels du haut de l'écran
        painter->drawText(10, 40, QString("Lives: %1").arg(lives)); // Le texte apparaîtra à 10 pixels du bord gauche et à 40 pixels du haut de l'écran
        itsLevel->display(painter);
        itsPlayer->display(painter);
        painter->end();
    }
}
void HMI::clearPaintings() {
    shouldDraw = false;
    update();
}

void HMI::displayMainMenu(std::vector<std::pair<std::string, unsigned int>> highscores)
{
    state = MAINMENU;
    startGameButton->setDefault(true);
    stackedWidget->setCurrentWidget(mainMenuWidget);

    QString scoresText;
    for (const auto &score : highscores) {
        scoresText += QString::fromStdString(score.first) + ": " + QString::number(score.second) + "\n";
    }

    scoresLabel->setText(scoresText);
}

void HMI::displayPauseMenu()
{
    itsGame->onGamePaused();
    state = PAUSEMENU;
    resumeButton->setDefault(true);
    clearPaintings();
    stackedWidget->setCurrentWidget(pauseMenuWidget);
}

void HMI::displayGameOverMenu()
{
    clearPaintings();
    state = GAMEOVER;
    stackedWidget->setCurrentWidget(gameOverMenuWidget);
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
    shouldDraw = true;
    displayGame();
    itsGame->onGameStart();
    itsTimer->start(1);//33
}


void HMI::close()
{

}

void HMI::resume()
{
    shouldDraw = true;
    displayGame();
    itsGame->onGameResumed();
}

void HMI::leave()
{
    stackedWidget->setCurrentWidget(mainMenuWidget);
}


void HMI::refreshAll()
{
    update();
}

void HMI::gameLoop(){
    itsGame->gameLoop();
}

void HMI::stopGame()
{
//    itsTimer->stop();
    displayGameOverMenu();
}
