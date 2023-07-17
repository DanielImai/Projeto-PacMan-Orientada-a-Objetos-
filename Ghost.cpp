/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Ghost.h"


using namespace std;

Ghost::Ghost(const int x, const int y, const bool kill) : Entity(x, y)
{
    setKill(kill);
}

Ghost::~Ghost()
{

}

void Ghost::setKill(bool kill)
{
    killPacman = kill;
}

bool Ghost::checkIfKill(int x, int y)
{
    if(getX() == x && getY() == y)
        return true;
    else
        return false;
    //verifica a posicao do x e y para ver se coincidem com a posicao do pacman
}

void Ghost::randomMovement(int board[20][20])
{
    int direcaoBackup;
    direcaoBackup = getDirecao();
    //pega a direcao que o fanstama possuia ao começar

    if(getDirecao() == 0 && board[getY() - 1][getX()] != 1)
    {
        moveUp();
        if(board[getY() - 1][getX()] == 1 || board[getY()][getX()] == 3)//verifica se vai bater em um tijolo ou se está numa encruzilhada
        {
            bool change = true;
            while(change == true)
            {

            setDirecao(rand() % 4);
            if(getDirecao() == 0 && board[getY() - 1][getX()] != 1 && direcaoBackup != 1) change = false;
            else if(getDirecao() == 1 && board[getY() + 1][getX()] != 1 && direcaoBackup != 0) change = false;
            else if(getDirecao() == 2 && board[getY()][getX() - 1] != 1 && direcaoBackup != 3) change = false;
            else if(getDirecao() == 3 && board[getY()][getX() + 1] != 1 && direcaoBackup != 2) change = false;
            //movimento aleatorio, continua no loop até pegar um movimento bom
            }

        }
    }
    else if(getDirecao() == 1 && board[getY() + 1][getX()] != 1)
    {
        moveDown();
        if(board[getY() + 1][getX()] == 1 || board[getY()][getX()] == 3)//verifica se vai bater em um tijolo ou se está numa encruzilhada
        {
            bool change = true;
            while(change == true)
            {
            setDirecao(rand() % 4);
            if(getDirecao() == 0 && board[getY() - 1][getX()] != 1 && direcaoBackup != 1) change = false;
            else if(getDirecao() == 1 && board[getY() + 1][getX()] != 1 && direcaoBackup != 0) change = false;
            else if(getDirecao() == 2 && board[getY()][getX() - 1] != 1 && direcaoBackup != 3) change = false;
            else if(getDirecao() == 3 && board[getY()][getX() + 1] != 1 && direcaoBackup != 2) change = false;
            //movimento aleatorio, continua no loop até pegar um movimento bom
            }

        }
    }
    else if(getDirecao() == 2 && board[getY()][getX() - 1] != 1)
    {
        moveLeft();
        if(board[getY()][getX() - 1] == 1 || board[getY()][getX()] == 3)//verifica se vai bater em um tijolo ou se está numa encruzilhada
        {
            bool change = true;
            while(change == true)
            {
            setDirecao(rand() % 4);
            if(getDirecao() == 0 && board[getY() - 1][getX()] != 1 && direcaoBackup != 1) change = false;
            else if(getDirecao() == 1 && board[getY() + 1][getX()] != 1 && direcaoBackup != 0) change = false;
            else if(getDirecao() == 2 && board[getY()][getX() - 1] != 1 && direcaoBackup != 3) change = false;
            else if(getDirecao() == 3 && board[getY()][getX() + 1] != 1 && direcaoBackup != 2) change = false;
            //movimento aleatorio, continua no loop até pegar um movimento bom
            }

        }
    }
    else if(getDirecao() == 3 && board[getY()][getX() + 1] != 1)
    {
        moveRight();
        if(board[getY()][getX() + 1] == 1 || board[getY()][getX()] == 3)//verifica se vai bater em um tijolo ou se está numa encruzilhada
        {
            bool change = true;
            while(change == true)
            {
            setDirecao(rand() % 4);
            if(getDirecao() == 0 && board[getY() - 1][getX()] != 1 && direcaoBackup != 1) change = false;
            else if(getDirecao() == 1 && board[getY() + 1][getX()] != 1 && direcaoBackup != 0) change = false;
            else if(getDirecao() == 2 && board[getY()][getX() - 1] != 1 && direcaoBackup != 3) change = false;
            else if(getDirecao() == 3 && board[getY()][getX() + 1] != 1 && direcaoBackup != 2) change = false;
            //movimento aleatorio, continua no loop até pegar um movimento bom
            }

        }
    }
}
