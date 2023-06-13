#include <QApplication>
#include <iostream>
#include <vector>
#include <QInputDialog>
#include <QDir>
#include "hmi.h"
#include "game.h"


HMI::HMI(Level * level, Player * player, Game * game, QWidget *parent) : QWidget(parent), itsLevel(level), itsPlayer(player), itsGame(game)
{
    DBSCORE = nullptr;

    // Police Press Start 2P
    QFont arcadeFont;
    arcadeFont.setFamily("Press Start 2P");
    arcadeFont.setPointSize(48);

    //Police VT323
    QFont buttonFont;
    buttonFont.setFamily("VT323");
    buttonFont.setPointSize(40);

    // Initialisation des widgets pour le main menu
    mainLayout = new QVBoxLayout;
    middleLayout = new QHBoxLayout;  // New layout for leaderboard and buttons
    leftLayout = new QVBoxLayout;
    rightLayout = new QVBoxLayout;

    startGameButton = new QPushButton("Start Game");
    rulesButton = new QPushButton("Rules");
    quitGameButton = new QPushButton("Quit Game");
    gameTitleLabel = new QLabel("Charclo Brosse", this);
    gameTitleLabel->setAlignment(Qt::AlignCenter);
    gameTitleLabel->setFont(arcadeFont);
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
    gameOverFont.setPointSize(56);
    gameOverLabel->setFont(gameOverFont);

    gameOverLayout->addWidget(gameOverLabel, 0, Qt::AlignCenter);

    // Initialisation des widgets pour le gaming
    gameLayout = new QVBoxLayout;

    // Initialisation des widgets pour le rules menu
    rulesLayout = new QVBoxLayout;
    rulesText = new QLabel("In this game, the player controls the main character, Charclo, and must navigate through levels composed of platforms and blocks.\nThe objective is to defeat all the enemies, collect coins and bills to unlock score multipliers, and complete the levels as quickly as possible.\nTo control Charclo, the player uses the arrow keys to move left or right, and the up arrow key to jump.\nPressing the \"Escape\" key allows the player to pause the game.");
    goBackButton = new QPushButton("Go back");

    // Initialisation du QLabel pour le highscoreList du main
    scoresLabel = new QLabel(this);
    scoresLabel->setAlignment(Qt::AlignCenter);
    QFont font = scoresLabel->font();
    font.setPointSize(18);
    scoresLabel->setFont(font);
    rulesText->setAlignment(Qt::AlignCenter);
    rulesText->setFont(font);

    // initialisation du QLabel pour le numero de niveau
    itsLevelNumberText = new QLabel(this);
    itsLevelNumberText->setFont(arcadeFont);

    // Initialisation du QLabel pour le highscoreList du gameover
    scoreLabelGameOver = new QLabel(this);
    scoresLabel->setAlignment(Qt::AlignCenter);

    //-------------------------
    // Ajout du titre au layout principal
    mainLayout->addWidget(gameTitleLabel, 0, Qt::AlignCenter);

    // Ajout des widgets au layout left (leaderboard)
    leftLayout->addWidget(scoresLabel, 0, Qt::AlignCenter);

    // Ajout des widgets au layout right (buttons)
    rightLayout->addWidget(startGameButton, 0, Qt::AlignCenter);
    rightLayout->addWidget(rulesButton, 0, Qt::AlignCenter);
    rightLayout->addWidget(quitGameButton, 0, Qt::AlignCenter);

    // Ajout des layouts left et right au layout middle
    middleLayout->addLayout(leftLayout);
    middleLayout->addLayout(rightLayout);

    // Ajout du layout middle au layout principal
    mainLayout->addLayout(middleLayout);

    // Ajout des widgets au layout pause menu
    pauseLayout->addStretch();
    pauseLayout->addWidget(resumeButton, 0, Qt::AlignCenter);
    pauseLayout->addWidget(quitToMainButton, 0, Qt::AlignCenter);
    pauseLayout->addStretch();

    // Ajout des widgets au layout game over
    gameOverLayout->addWidget(scoreLabelGameOver, 0, Qt::AlignCenter);
    gameOverLayout->addWidget(quitToMainButton2, 0, Qt::AlignCenter);
    QFont fontGO = scoreLabelGameOver->font();
    fontGO.setPointSize(30);
    scoreLabelGameOver->setFont(fontGO);


    // Ajout des widgets au layout gaming
    gameLayout->addWidget(itsLevelNumberText);

    // Ajout des widgets au layout rules
    rulesLayout->addWidget(rulesText);
    rulesLayout->addWidget(goBackButton, 0, Qt::AlignCenter);


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
                          "color: white;"
                          "padding: 15px 32px;"
                          "text-align: center;"
                          "text-decoration: none;"
                          "font-size: 50px;"
                          "margin: 4px 2px;"
                          "outline: none;"
                          "}";

    QString buttonFocusedStyle = "QPushButton:focus {"
                                 "color: red;"
                                 "}";

    QString buttonHoverStyle = "QPushButton:hover {"
                               "color: rgba(255, 0, 0, 0.5);"
                               "}";

    itsStartLevelTimer = new QTimer(this);
    itsLevelTimer = new QTimer(this);

    resumeButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    resumeButton->setFont(buttonFont);
    resumeButton->setFixedWidth(300);
    quitToMainButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    quitToMainButton->setFont(buttonFont);
    quitToMainButton->setFixedWidth(350);
    startGameButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    startGameButton->setFont(buttonFont);
    startGameButton->setFixedWidth(300);
    rulesButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    rulesButton->setFont(buttonFont);
    rulesButton->setFixedWidth(300);
    quitGameButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    quitGameButton->setFont(buttonFont);
    quitGameButton->setFixedWidth(300);
    quitToMainButton2->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    quitToMainButton2->setFont(buttonFont);
    quitToMainButton2->setFixedWidth(400);
    goBackButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    goBackButton->setFont(buttonFont);
    goBackButton->setFixedWidth(400);

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

    connect(itsStartLevelTimer, &QTimer::timeout, this, &HMI::startLevel);
    connect(itsLevelTimer, &QTimer::timeout, this, &HMI::levelTimeout);

    // Définir la politique de focus pour permettre la navigation entre les boutons
    startGameButton->setFocusPolicy(Qt::StrongFocus);
    rulesButton->setFocusPolicy(Qt::StrongFocus);
    quitGameButton->setFocusPolicy(Qt::StrongFocus);

    itsTimer = new QTimer(this);
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));

    displayMainMenu(DBSCORE->loadScores());

    // couleur de fond et des labels
    mainMenuWidget->setStyleSheet("background-color: black;");
    pauseMenuWidget->setStyleSheet("background-color: black;");
    gameOverMenuWidget->setStyleSheet("background-color: black;");
    rulesMenuWidget->setStyleSheet("background-color: black;");
    for (QLabel* label: this->findChildren<QLabel*>()) {
        label->setStyleSheet("QLabel { color : white; }");
    }

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

    if (itsLevel != nullptr && itsLevel->isActive() && shouldDraw){
        unsigned int score = itsGame->getItsScore();
        short lives = itsGame->getItsPlayer()->getItsLivesNb();
        QPainter * painter = new QPainter(this);
        painter->setFont(QFont("VT323", 14));
        painter->drawText(10, 20, QString("Score: %1").arg(score)); // Le texte apparaîtra à 10 pixels du bord gauche et à 20 pixels du haut de l'écran
        painter->drawText(10, 40, QString("Lives: %1").arg(lives)); // Le texte apparaîtra à 10 pixels du bord gauche et à 40 pixels du haut de l'écran
        itsLevel->display(painter);
        itsPlayer->display(painter);
        painter->setFont(QFont("VT323", 28));
        if (itsLevelTimer->remainingTime()/1000 > 99){
            painter->drawText(1230, 30, QString("%1").arg(itsLevelTimer->remainingTime()/1000));
        }
        else if (itsLevelTimer->remainingTime()/1000 > 9){
            painter->drawText(1230, 30, QString("0%1").arg(itsLevelTimer->remainingTime()/1000));
        }
        else {
            painter->drawText(1230, 30, QString("00%1").arg(itsLevelTimer->remainingTime()/1000));
        }

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

    QString scoresText = "Leaderboard :\n\n";
    int rank = 1;
    for (const auto &score : highscores) {
        scoresText += QString::number(rank) + ". " + QString::fromStdString(score.first) + ": " + QString::number(score.second) + "\n";
        rank++;

    }

    scoresLabel->setText(scoresText);
}

void HMI::displayPauseMenu()
{
    timeRemaining = itsLevelTimer->remainingTime();
    itsLevelTimer->stop();
    itsGame->onGamePaused();
    state = PAUSEMENU;
    resumeButton->setDefault(true);
    clearPaintings();
    stackedWidget->setCurrentWidget(pauseMenuWidget);
}

void HMI::displayGameOverMenu()
{
    clearPaintings();
    scoreLabelGameOver->setText(QString("Score: %1").arg(itsGame->getItsScore()));
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
    itsTimer->start(1);
}

void HMI::close()
{

}

void HMI::resume()
{
    shouldDraw = true;
    displayGame();
    itsGame->onGameResumed();
    itsLevelTimer->start(timeRemaining);
}

void HMI::leave()
{
    displayMainMenu(DBSCORE->loadScores());
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
    itsTimer->stop();
    itsLevelTimer->stop();

    if (DBSCORE->isInTop10(itsGame->getItsScore()))
    {
        QInputDialog dialog(this);
        dialog.setModal(true);
        dialog.setWindowTitle(tr("Score Input"));
        dialog.setLabelText(tr("You made it to the top 10! Enter your name:"));
        dialog.setInputMode(QInputDialog::TextInput);
        dialog.setTextValue(QDir::home().dirName());

        QLineEdit *lineEdit = dialog.findChild<QLineEdit *>();
        if (lineEdit) {
            lineEdit->setMaxLength(10);
        }

        if (dialog.exec() == QDialog::Accepted && !dialog.textValue().isEmpty()) {
            std::string name = dialog.textValue().toStdString();
            DBSCORE->saveScore(name, itsGame->getItsScore());
        }
    }

    displayGameOverMenu();
}


void HMI::setLevel(Level * level){
    itsLevel = level;
}


void HMI::displayLevelNumber(){
    QString text = QString::fromStdString("Level n°" + std::to_string(itsLevel->getItsId()));
    itsLevelNumberText->setStyleSheet("QLabel { color : black; }");
    itsLevelNumberText->setText(text);

    itsLevelNumberText->setAlignment(Qt::AlignCenter);

    itsStartLevelTimer->start(1000);
}

void HMI::startLevel(){
    itsStartLevelTimer->stop();
    itsLevelNumberText->setText("");
    itsLevel->activate();
    itsLevelTimer->start(itsLevel->getItsTimerTime()*1000);
    itsGame->spawnPlayer();
}

void HMI::levelTimeout()
{
    itsLevelTimer->stop();
    itsTimer->stop();
    itsGame->levelTimeout();
    stopGame();
}
