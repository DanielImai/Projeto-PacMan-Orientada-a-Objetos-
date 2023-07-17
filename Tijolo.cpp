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
#include "Tijolo.h"

Tijolo::Tijolo()
{
    imageT = al_load_bitmap("tij.png");
}

Tijolo::~Tijolo()
{
    al_destroy_bitmap(imageT);
}

void Tijolo::makeTijolo(int x, int y)
{
    al_draw_bitmap(imageT,x*60,y*60,0); //Desenha a imagem
}
