/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef Pacman_h
#define Pacman_h

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Entity.h"

using namespace std;

class Pacman : public Entity
{
public:
    Pacman(const int, const int, const int, const int, const bool);
    ~Pacman();
    void setWin(bool);
    int getWin();
    void pacMove(int intent, int board[20][20]);
    void pacEat();
    int getScore();
    int getLives();
    void die();
private:
    int lives;
    int score;
    bool win;
};

#endif // Pacman_h
