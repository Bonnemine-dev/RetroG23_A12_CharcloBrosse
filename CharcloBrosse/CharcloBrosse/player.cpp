#include "player.h"
#include "QtCore/qdebug.h"
#include <iostream>

std::array<QPixmap*, 12>* Player::itsSpritesList = nullptr;

//Methode move
void Player::moveX()
{
    qInfo()<<"remaning walk = "<<itsRemaningWalkMove;
    //Si le mouvement actuel est différent du prochain mouvement et que le joueur est sur le sol alors égalise les deux valeurs
    if(itsCurrentMove != itsNextMove && isOnTheGround)itsCurrentMove = itsNextMove;
    if(itsCurrentMove != NONE)
    {
        if(*itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(int(float(-8.258)*float(itsRemaningWalkMove)+float(328.258)))) == 0)
        {
            itsX += itsCurrentMove;
            if(itsX == -1)itsX = 32*39;
            else if(itsX == (32*39)+1)itsX = 0;
            if(isOnTheGround)itsRemaningWalkMove -= (itsRemaningWalkMove != 0?1:0);
        }
    }
    else
    {
        if(itsRemaningJumpMove == 0 && itsRemaningFallMove == 0xFFFF)itsRemaningWalkMove = 0xFFFF;
    }
    itsRect.moveTo(itsX,itsY);
}

void Player::moveY()
{
    //Vrai si le joueur est dans un saut
    if(itsRemaningJumpMove != 0)
    {
        //Pour x égale le nombre de pixel que doit parcourir encore le joueur la fonction "2.492*x+97.509" donne la vitesse à la quelle doit se déplacer le joueur
        //Soit pour un nombre restant de 192 pixels à parcourir la vitesse est de 576 pixels par secondes
        //Et pour un nombre restant de 1 pixels à parcourir la vitesse est de 100 pixels par secondes
        if(*itsLoopCounter % (NUMBER_LOOP_PER_SECOND/int(float(100)+(float(90.537)*log(itsRemaningJumpMove)))) == 0)
//        if((*itsLoopCounter * 1000) % ((NUMBER_LOOP_PER_SECOND*1000)/(2701*itsRemaningJumpMove+57298)) == 0)
        {
            //enleve 1 à l'axe Y soit monte l'entité de 1 pixel sur l'écran
            itsY --;
            itsRemaningJumpMove -= (itsRemaningJumpMove != 0?1:0);
        }
    }
    //Vrai si le joueur est en pleine chute
    else if(itsRemaningFallMove != 0xFFFF)
    {
        //Pour x égale le nombre de pixel que doit parcourir encore le joueur la fonction "-5.010*x+9581.010" donne la vitesse à la quelle doit se déplacer le joueur sur l'axe y
        //Soit pour un nombre restant de 96 pixels à parcourir la vitesse est de 100 pixels par secondes
        //Et pour un nombre restant de 1 ou 0 pixels à parcourir la vitesse est et reste à de 576 pixels par secondes
        if(*itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(int(float(-5.010)*float(itsRemaningFallMove)+float(581.010)))) == 0)
        {
            //ajoute 1 à l'axe Y soit descend l'entité de 1 pixel sur l'écran
            itsY ++;
            itsRemaningFallMove -= (itsRemaningFallMove != 0xFFFF && itsRemaningFallMove != 0?1:0);
        }
    }

    itsRect.moveTo(itsX,itsY);
}

void Player::display(QPainter * painter)
{
    if(isOnTheGround){
        if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/PLAYERMAXSPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
        {
            if(itsCurrentMove == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0));
            else if(itsCurrentMove == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(6));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
        }
        else
        {
            if(itsCurrentMove == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
            else if(itsCurrentMove == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(7));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
        }
    }
    else
    {
        if(itsCurrentMove == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(2));
        else if(itsCurrentMove == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(8));
        else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(8));
    }
}
//Setter itsXSpeed
void Player::setItsXSpeed(short newItsXSpeed)
{
    itsXSpeed = newItsXSpeed;
}

//Setter itsYSpeed
void Player::setItsYSpeed(short newItsYSpeed)
{
    itsYSpeed = newItsYSpeed;
}

//Setter itsLivesNb
void Player::setItsLivesNb(unsigned short newItsLivesNb)
{
    itsLivesNb = newItsLivesNb;
}

//Getter itsLivesNb
unsigned short Player::getItsLivesNb() const
{
    return itsLivesNb;
}

//Getter itsXSpeed
short Player::getItsXSpeed() const
{
    return itsXSpeed;
}

//Getter itsYSpeed
short Player::getItsYSpeed() const
{
    return itsYSpeed;
}

//Setter isOnTheGround
void Player::setIsOnTheGround(bool newIsOnTheGround)
{
    isOnTheGround = newIsOnTheGround;
}

//Getter isOnTheGround
bool Player::getIsOnTheGround() const
{
    return isOnTheGround;
}

//Constructeur
unsigned short Player::getItsRemaningJumpMove() const
{
    return itsRemaningJumpMove;
}

void Player::setItsRemaningJumpMove(unsigned short newItsRemaningJumpMove)
{
    itsRemaningJumpMove = newItsRemaningJumpMove;
}

void Player::setItsCurrentMove(MoveX newItsCurrentMove)
{
    itsCurrentMove = newItsCurrentMove;
}

void Player::setItsNextMove(MoveX newItsNextMove)
{
    itsNextMove = newItsNextMove;
}


unsigned short Player::getItsRemaningComboTicks() const
{
    return itsRemaningComboTicks;
}

void Player::setItsRemaningComboTicks(unsigned short newItsRemaningComboTicks)
{
    itsRemaningComboTicks = newItsRemaningComboTicks;
}

unsigned short Player::getComboValue() const
{
    return comboValue;
}

void Player::setComboValue(unsigned short newComboValue)
{
    comboValue = newComboValue;
}

unsigned short Player::getItsRemaningFallMove() const
{
    return itsRemaningFallMove;
}

void Player::setItsRemaningFallMove(unsigned short newItsRemaningFallMove)
{
    itsRemaningFallMove = newItsRemaningFallMove;
}

void Player::setItsRemaningWalkMove(unsigned short newItsRemaningWalkMove)
{
    itsRemaningWalkMove = newItsRemaningWalkMove;
}

unsigned short Player::getItsRemaningWalkMove() const
{
    return itsRemaningWalkMove;
}

Player::Player(short x,  short y,  short height,  short width, std::array<QPixmap *, 12> *theSpritesList,unsigned short* theLoopCounter)
    : Entity(x, y, height, width)
{
    itsSpritesList = theSpritesList;
    itsLivesNb = MAX_LIFE;
    itsLoopCounter = theLoopCounter;
}

