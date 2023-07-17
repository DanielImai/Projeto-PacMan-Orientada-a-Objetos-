/*Projeto PacMan feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef Ghost_h
#define Ghost_h

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Entity.h"

using namespace std;

class Ghost : public Entity
{
public:
    Ghost(const int, const int, const bool);
    ~Ghost();
    void randomMovement(int board[20][20]);
    bool checkIfKill(int,int);
    void setKill(bool);
private:
    bool killPacman;

};

#endif
