/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu -
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef bbt_h
#define bbt_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "Pilula.h"
#include "Tijolo.h"

using namespace std;

void makeBoard(int board[20][20], Pilula **P[20][20], Tijolo *T[196]);

void destroyBoard();

void makeBackground();

void checkDirection(int direcao, int sprite, int fator);

void checkCollision(int board[20][20], int posicaoX, int posicaoY, int pacX, int pacY);




#endif
