#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "pacman.h"
#include "Pilula.h"

const int upM = 1;
const int downM = 2;
const int leftM = 3;
const int rightM = 4;

using namespace std;

Pacman::Pacman(const int x, const int y, const int life, const int scr, const bool w) : Entity(x,y)
{
    lives = life;
    score = scr;
    win = w;
}

Pacman::~Pacman()
{

}

void Pacman::pacEat()
{
    score += 100;
}

int Pacman::getScore()
{
    return score;
}

int Pacman::getLives()
{
    return lives;
}

void Pacman::die()
{
    lives--;
    setX(11);
    setY(11);
}

void Pacman::pacMove(int intent, int board[20][20])
{
    if(intent == upM && board[getY() - 1][getX()] != 1)
    {
        moveUp();
    }

    else if(intent == downM && board[getY() + 1][getX()] != 1)
    {
        moveDown();
    }

    else if(intent == leftM && board[getY()][getX() - 1] != 1)
    {
        moveLeft();
    }

    else if(intent == rightM && board[getY()][getX() + 1] != 1)
    {
        moveRight();
    }

}

void Pacman::setWin(bool state)
{
    win = state;
}

int Pacman::getWin()
{
    return win;
}


