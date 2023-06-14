#include <QApplication>
#include <iostream>
#include <vector>
#include <QDir>
#include <QBuffer>
#include "hmi.h"
#include "game.h"


HMI::HMI(Player * player, Game * game, QWidget *parent) : QWidget(parent), itsPlayer(player), itsGame(game)
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

    // les timers
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
    buttonFont.setPointSize(25);
    scoresLabel->setFont(buttonFont);
    buttonFont.setPointSize(40);

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


    // Pour l'ajout des scores pas dans un Qinputdialog super cool
    // Ajout dans la liste des déclarations dans votre constructeur HMI
    gameOverTop10MenuWidget = new QWidget;

    // Ajout dans votre fonction d'initialisation
    gameOverTop10Layout = new QVBoxLayout;
    nameInput = new QLineEdit;
    submitScoreButton = new QPushButton("Submit Score");
    congratulationsMessage = new QLabel;

    gameOverTop10Layout->addWidget(congratulationsMessage, 0, Qt::AlignCenter);
    gameOverTop10Layout->addWidget(nameInput, 0, Qt::AlignCenter);
    gameOverTop10Layout->addWidget(submitScoreButton, 0, Qt::AlignCenter);

    gameOverTop10MenuWidget->setLayout(gameOverTop10Layout);
    stackedWidget->addWidget(gameOverTop10MenuWidget);

    // style
    congratulationsMessage->setText("Congratulations, you have reached the top 10!");
    congratulationsMessage->setStyleSheet("QLabel { color : blue; }");
    congratulationsMessage->setFont(buttonFont);
    congratulationsMessage->setAlignment(Qt::AlignCenter);

    submitScoreButton->setStyleSheet(buttonStyle + buttonFocusedStyle + buttonHoverStyle);
    submitScoreButton->setFont(buttonFont);
    submitScoreButton->setFixedWidth(400);

    submitScoreButton->setFocusPolicy(Qt::StrongFocus);

    gameOverTop10MenuWidget->setStyleSheet("background-color: black;");

    nameInput->setFont(buttonFont);
    nameInput->setFixedWidth(400);
    nameInput->setStyleSheet("QLineEdit { color: white; }");
    nameInput->setText(QDir::home().dirName());
    nameInput->setMaxLength(5);

    // Connecter le signal du bouton à l'emplacement approprié
    connect(submitScoreButton, &QPushButton::clicked, this, &HMI::submitScore);

    // Assurez-vous que votre bouton de soumission et votre champ de saisie ont une politique de focus pour permettre la navigation.
    nameInput->setFocusPolicy(Qt::StrongFocus);
    submitScoreButton->setFocusPolicy(Qt::StrongFocus);
}

HMI::~HMI()
{
    delete startGameButton;
    delete rulesButton;
    delete quitGameButton;
    delete gameTitleLabel;

    delete resumeButton;
    delete quitToMainButton;

    delete quitToMainButton2;
    delete gameOverLabel;

    delete itsLevelNumberText;
    delete scoresLabel;
    delete scoreLabelGameOver;

    delete rulesText;
    delete goBackButton;

    delete mainLayout;
    delete middleLayout;
    delete leftLayout;
    delete rightLayout;
    delete pauseLayout;
    delete gameOverLayout;
    delete gameLayout;
    delete rulesLayout;

    delete mainMenuWidget;
    delete pauseMenuWidget;
    delete gameMenuWidget;
    delete gameOverMenuWidget;
    delete rulesMenuWidget;

    delete stackedWidget;

    delete itsStartLevelTimer;
    delete itsLevelTimer;
    delete itsTimer;

    delete DBSCORE;
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
        QPainter * painter = new QPainter(this);

        // Dessin du background
        QString cheminBG = itsGame->getCheminBG();
        qDebug() << "Chemin du background: " << cheminBG;
        if (QFile::exists(cheminBG)) {
            QPixmap bg(cheminBG);
            if (!bg.isNull()) {
                painter->setOpacity(0.8);
                painter->drawPixmap(this->rect(), bg);
                painter->setOpacity(1.0);
            } else {
                qDebug() << "Erreur lors de la lecture de l'image";
            }
        } else {
            qDebug() << "Le fichier n'existe pas";
        }

        // Dessin du reste du jeu
        painter->setFont(QFont("VT323", 18));
        painter->drawText(10, 20, QString("Score: %1").arg(itsGame->getItsScore())); // Le texte apparaîtra à 10 pixels du bord gauche et à 20 pixels du haut de l'écran
        painter->drawText(10, 40, QString("Multiplier: %1").arg(itsGame->getCurrentTier()));
        painter->drawText(10, 60, QString("Lives: %1").arg(itsGame->getItsPlayer()->getItsLivesNb()));
        painter->drawText(10, 80, QString("Wallet: %1").arg(itsGame->getItsMoney()));
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

        delete painter;
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

void HMI::displayGameOverMenuTOP10()
{
    clearPaintings();
    scoreLabelGameOver->setText(QString("Score: %1").arg(itsGame->getItsScore()));
    state = GAMEOVER_TOP10;
    stackedWidget->setCurrentWidget(gameOverTop10MenuWidget);
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
        displayGameOverMenuTOP10();
    }
    else
    {
        displayGameOverMenu();
    }
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

int HMI::getTimerRemainingTime()
{
    return itsLevelTimer->remainingTime()/1000;
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

void HMI::submitScore()
{
    std::string name = nameInput->text().toStdString();
    DBSCORE->saveScore(name, itsGame->getItsScore());

    // Clear le champ de saisie pour une utilisation future
    nameInput->clear();

    // Affichez ensuite le menu Game Over classique
    displayGameOverMenu();
}
