/*Projeto PacMan feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#ifndef Entity_h
#define Entity_h

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

class Entity
{
public:
    Entity(const int, const int);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getX();
    int getY();
    int getDirecao();
    void setX(int);
    void setY(int);
    void setDirecao(int);
    void drawRegionPacman(int,int);
    void drawGhost(int);
    virtual ~Entity();
    void printCords();
private:
    int entityX;
    int entityY;
    int direcao;
    ALLEGRO_BITMAP  *image;
};

#endif
