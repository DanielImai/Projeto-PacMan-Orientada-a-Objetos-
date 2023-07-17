/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu -
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef Tijolo_h
#define Tijolo_h

#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>

using namespace std;

class Tijolo
{
public:
    Tijolo();
    void makeTijolo(int x, int y);
    ~Tijolo();
private:
    ALLEGRO_BITMAP  *imageT;
};

#endif
