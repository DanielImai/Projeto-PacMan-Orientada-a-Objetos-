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
#include "GhostInt.h"
#include <bits/stdc++.h>

using namespace std;

float distance(int x1, int y1, int x2, int y2)
{
    // https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

bool sortbyth(const tuple<int, int, int>& a,
              const tuple<int, int, int>& b)
{
    // https://www.geeksforgeeks.org/sorting-vector-tuple-c-ascending-order/
    return (get<2>(a) < get<2>(b));
}

GhostInt::GhostInt(const int x, const int y, const bool kill) : Entity(x, y)
{
    setKill(kill);
}

GhostInt::~GhostInt()
{

}

void GhostInt::setKill(bool kill)
{
    killPacman = kill;
}

bool GhostInt::checkIfKill(int x, int y)
{
    if(getX() == x && getY() == y)
        return true;
    else
        return false;
    //verifica a posicao do x e y para ver se coincidem com a posicao do pacman
}

void GhostInt::intelligentMovement(int board[20][20], int pacX, int pacY)
{
    vector<tuple<int,int,float>> posicoes;
    //pego um tuple que é guardar dois ints em um elemento, nesse caso a estrutura de dados tuple
    //(x,y,distancia entre o ghost e o pacman)

    if(board[getY()+ 1][getX()] != 1)
    {
        posicoes.push_back(make_tuple(getX(),getY()+1,0));//guardo se poder ir para baixo
    }
    if(board[getY()-1][getX()] != 1)
    {
        posicoes.push_back(make_tuple(getX(),getY()-1,0));//guardo se poder ir para cima
    }
    if(board[getY()][getX()-1] != 1)
    {
        posicoes.push_back(make_tuple(getX()-1,getY(),0));//guardo se poder ir para esquerda
    }
    if(board[getY()][getX()+1] != 1)
    {
        posicoes.push_back(make_tuple(getX()+1,getY(),0));//guardo se poder ir para direita
    }

    for(int i=0;i < posicoes.size(); i++)//pego quantas posicoes eu peguei e coloco no for
    {
        int ghostX;//pego a posicao X
        int ghostY;//pego a posicao Y
        ghostX = get<0>(posicoes[i]);//pego o X do tuple e coloco no ghostX
        ghostY = get<1>(posicoes[i]);//pego o Y do tuple e coloco no ghostY
        get<2>(posicoes[i]) = distance(ghostX, ghostY, pacX, pacY);//uso a funcao para calcular a distancia
    }

    sort(posicoes.begin(), posicoes.end(), sortbyth);//coloca em ordem crescente o terceiro elemento (a distancia)

    setX(get<0>(posicoes[0]));
    setY(get<1>(posicoes[0]));

}
