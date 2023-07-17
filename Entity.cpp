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
#include "Entity.h"
#include "Pilula.h"

using namespace std;

Entity::Entity(const int x, const int y)
{
    entityX = x;
    entityY = y;
}

Entity::~Entity()
{
    al_destroy_bitmap(image);
}

void Entity::moveUp()
{
    entityY--;
}

void Entity::moveDown()
{
    entityY++;
}

void Entity::moveRight()
{
    entityX++;
}

void Entity::moveLeft()
{
    entityX--;
}

void Entity::printCords()
{
    cout<<"X: " << entityX << "Y: " << entityY<<"\n";
}

int Entity::getX()
{
    return entityX;
}

int Entity::getY()
{
    return entityY;
}

int Entity::getDirecao()
{
    return direcao;
}

void Entity::setDirecao(int newD)
{
    direcao = newD;
}

void Entity::setX(int newX)
{
    entityX = newX;
}

void Entity::setY(int newY)
{
    entityY = newY;
}

void Entity::drawRegionPacman(int sprite,int spriteE)
{
    image = al_load_bitmap("pacmantest.png");
    al_draw_bitmap_region(image, spriteE*60, sprite*60, 60, 60, entityX*60, entityY*60, 0);
}

void Entity::drawGhost(int ghostNumber)
{
    switch(ghostNumber)
    {
    case 0:
        image = al_load_bitmap("ghost.png");
        al_draw_bitmap(image,entityX*60,entityY*60,0);
        break;
    case 1:
        image = al_load_bitmap("ghost2.png");
        al_draw_bitmap(image,entityX*60,entityY*60,0);
        break;
    case 2:
        image = al_load_bitmap("ghost3.png");
        al_draw_bitmap(image,entityX*60,entityY*60,0);
        break;
    case 3:
        image = al_load_bitmap("ghost4.png");
        al_draw_bitmap(image,entityX*60,entityY*60,0);
    }
//verifica o numero dado e desenha o fantasma de acordo com esse numero
}

