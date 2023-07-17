/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef GhostInt_h
#define GhostInt_h

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Entity.h"

using namespace std;

class GhostInt : public Entity
{
public:
    GhostInt(const int, const int, const bool);
    ~GhostInt();
    void intelligentMovement(int board[20][20], int pacX, int pacY);
    bool checkIfKill(int,int);
    void setKill(bool);
private:
    bool killPacman;
};

#endif

