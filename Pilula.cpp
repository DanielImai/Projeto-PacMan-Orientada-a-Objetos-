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
#include "Pilula.h"

Pilula::Pilula()
{
    imageP = al_load_bitmap("onigiri.png");
}

Pilula::~Pilula()
{
    X = 0;
    Y = 0;
    al_destroy_bitmap(imageP);
    cout<<"Destruidor de Pilula"<<endl;
}

void Pilula::makePilula(int x, int y,int sprite)
{
    al_draw_bitmap_region(imageP, 0, sprite*60, 60, 60, x*60, y*60, 0);
}

int Pilula::getX()
{
    return X;
}

int Pilula::getY()
{
    return Y;
}


