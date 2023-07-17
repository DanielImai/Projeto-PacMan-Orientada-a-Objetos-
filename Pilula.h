/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef Pilula_h
#define Pilula_h

#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>

using namespace std;

class Pilula
{
public:
    Pilula();//const padrao
    void makePilula(int x, int y, int sprite);
    ~Pilula();//destrutor
    int getX();
    int getY();
private:
    ALLEGRO_BITMAP  *imageP;
    int X, Y;
};

#endif
