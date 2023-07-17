/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu -
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/

#include "bbt.h"
#include "Pilula.h"
#include "Tijolo.h"

using namespace std;

void makeBoard(int board[20][20], Pilula *P[204], Tijolo *T[196])
{
    int numPil;

    int numTij;

    numPil = 0;
    numTij = 0;

        for(int i = 0; i < 20; i++)
    {
        for(int ii = 0; ii < 20; ii++)
        {
            if(board[i][ii] == 0)
            {
                P[numPil]->makePilula(ii,i);
                numPil++;
            }
            else if(board[i][ii] == 1)
            {
                T[numTij]->makeTijolo(ii,i);
                numTij++;
            }
        }
    }

}

void makeBackground()
{
    ALLEGRO_BITMAP  *background = NULL; //Imagem
    background = al_load_bitmap("back.png");
    al_draw_bitmap(background,200,200,0); //Desenha a imagem
}

void checkDirection(int direcao, int sprite, int fator)
{
           switch(direcao)
           {
           case 1:
                sprite = sprite + fator;
                if(sprite == 1) fator = 1;
                if(sprite == 3) fator = -1;
           case 2:
                sprite = sprite + fator;
                if(sprite == 4) fator = 1;
                if(sprite == 6) fator = -1;
           case 3:
                sprite = sprite + fator;
                if(sprite == 7) fator = 1;
                if(sprite == 9) fator = -1;
           case 4:
                sprite = sprite + fator;
                if(sprite == 10) fator = 1;
                if(sprite == 12) fator = -1;
           }

}









