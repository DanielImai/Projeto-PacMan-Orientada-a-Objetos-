/*Projeto PACMAN feito por
Daniel Imai - 7552
Otávio Massanobu - 5974
Nathan Monteiro - 6311
Programado em C++ usando ALLEGRO*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "Tijolo.h"
#include "Pilula.h"
#include "pacman.h"
#include "Ghost.h"
#include "GhostInt.h"


using namespace std;

const float FPS = 9;
const int SCREEN_W = 1600;
const int SCREEN_H = 1200;
const int upM = 1;
const int downM = 2;
const int leftM = 3;
const int rightM = 4;


int main()
{
    int board[20][20] = {           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1},
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                                    {1, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
                                    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 1, 3, 0, 3, 0, 0, 3, 0, 3, 1, 0, 1, 1, 1, 1},
                                    {1, 0, 0, 0, 3, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 3, 0, 0, 0, 1},
                                    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
                                    {1, 0, 3, 0, 3, 3, 0, 3, 0, 1, 1, 0, 3, 0, 3, 3, 0, 3, 0, 1},
                                    {1, 1, 0, 1, 1, 0, 1, 0, 3, 0, 0, 3, 0, 1, 0, 1, 1, 0, 1, 1},
                                    {1, 1, 3, 0, 0, 3, 3, 0, 1, 1, 1, 1, 0, 3, 3, 0, 0, 3, 1, 1},
                                    {1, 1, 0, 1, 1, 0, 1, 3, 0, 0, 0, 0, 3, 1, 0, 1, 1, 0, 1, 1},
                                    {1, 0, 3, 0, 0, 3, 1, 0, 1, 1, 1, 1, 0, 1, 3, 0, 0, 3, 0, 1},
                                    {1, 0, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 1, 1, 1, 0, 1},
                                    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                                    {1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1},
                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

    };

    //matriz do tabuleiro

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE *sample2 = NULL;
    ALLEGRO_SAMPLE *sample3 = NULL;
    al_init();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    sample = al_load_sample("theme.wav");
    sample2 = al_load_sample("victory.mp3");
    sample3 = al_load_sample("death.mp3");
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *font = al_load_font("SuperMario256.ttf", 50, 0);
    ALLEGRO_FONT *font2 = al_load_font("SuperMario256.ttf", 120, 0);


    ALLEGRO_DISPLAY *display = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    ALLEGRO_TIMER *timer = NULL;


    int score = 0;


    bool teclas[255] = {false};

    if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

    al_install_keyboard();
    al_init_image_addon();

    if(!al_init_image_addon())
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_image_addon!",
                                   NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        fprintf(stderr, "failed to create timer!\n");

        return -1;
    }


    display = al_create_display(SCREEN_W, SCREEN_H);

    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }

    Pacman pac(11,11,4,0,false);
    Ghost ghost[] = { Ghost(1,1,false), Ghost(18,18,false), Ghost(1,18,false) };
    ghost[0].setDirecao(3);
    ghost[1].setDirecao(2);
    ghost[2].setDirecao(0);
    GhostInt ghostInt(18,1,false);
    //ghostInt.setDirecao(2);
    //criacao dos ghosts e direcao de cada um

    ALLEGRO_BITMAP  *background = NULL;
    background = al_load_bitmap("backtest.png");
    if(!background)
    {
        fprintf(stderr,"failed to create background bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        fprintf(stderr, "failed to create event_queue!\n");
        pac.~Pacman();
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));//Evento da Tela

    al_register_event_source(event_queue, al_get_timer_event_source(timer));//Evento de tempo

    al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado

    al_play_sample(sample, 1.0, 0, 1, ALLEGRO_PLAYMODE_LOOP,NULL);

    al_start_timer(timer);

    bool re_desenha = true;
    bool termina = false;
    bool esc = false;

    int sprite = 0;

    Pilula * P = new Pilula[190];
    //P = new Pilula *[20];
    //for(int i = 0; i < 20; i++)
    //P[i] = new Pilula[20];
    Tijolo * T = new Tijolo[210];
    //criacao de uma matriz de pilulas e array de tijolos

    int numTij;
    int numPil;
    int intent;
    int contador;
    int delay = 0;
    int fator = 0;
    int spriteP = 0;
    int timerPellet = 0;
    int spriteE = 0;
    int fatorE = 0;

    ALLEGRO_BITMAP *telaInicio;
        telaInicio = al_load_bitmap("telaInicio.png");
        al_draw_bitmap(telaInicio,0,0,0);
        al_flip_display();

    while(!teclas[ALLEGRO_KEY_SPACE])
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada
        teclas[ev.keyboard.keycode] = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) { //Tecla X Liberada

            teclas[ev.keyboard.keycode] = false;
        }
    }

    while(!termina)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {

        if(teclas[ALLEGRO_KEY_UP] || teclas[ALLEGRO_KEY_W]){

            if(board[pac.getY() - 1][pac.getX()] != 1){

                intent = upM;
                sprite = 2;

            }
        }
        //reconhecer que a tecla UP foi apertada
        else if(teclas[ALLEGRO_KEY_DOWN] || teclas[ALLEGRO_KEY_S]){

            if(board[pac.getY() + 1][pac.getX()] != 1){

                intent = downM;
                sprite = 3;

            }

        }
    //reconhecer que a tecla DOWN foi apertada
        else if(teclas[ALLEGRO_KEY_LEFT] || teclas[ALLEGRO_KEY_A]){

            if(board[pac.getY()][pac.getX() - 1] != 1){

                intent = leftM;
                sprite = 1;

            }

        }
        //reconhecer que a tecla LEFT foi apertada
        else if(teclas[ALLEGRO_KEY_RIGHT] || teclas[ALLEGRO_KEY_D]){

            if(board[pac.getY()][pac.getX() + 1] != 1){

                intent = rightM;
                sprite = 0;

            }
        }
        else if(teclas[ALLEGRO_KEY_0])
        {

            termina = true;
            pac.setWin(true);

        }
        //reconhecer que a tecla RIGHT foi apertada

        pac.pacMove(intent, board);//mover pacman

        for(int i = 0;i < 3;i++){

            if(ghost[i].checkIfKill(pac.getX(), pac.getY()) == true)
            {
                pac.die();//checar se o pacman se moveu para algum fantasma
                ghost[0].setX(1);
                ghost[0].setY(1);
                ghost[1].setX(18);
                ghost[1].setY(18);
                ghost[2].setX(1);
                ghost[2].setY(18);
                ghost[0].setDirecao(3);
                ghost[1].setDirecao(2);
                ghost[2].setDirecao(0);
                ghostInt.setX(18);
                ghostInt.setY(1);
                ghostInt.printCords();
                al_draw_text(font2, al_map_rgb(255,255,255), 800, 480, ALLEGRO_ALIGN_CENTRE,"MORREU, APERTE ESPACO");
                al_flip_display();
                while(!teclas[ALLEGRO_KEY_SPACE])
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada
        teclas[ev.keyboard.keycode] = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) { //Tecla X Liberada

            teclas[ev.keyboard.keycode] = false;
        }
    }
                intent = 0;
                if(pac.getLives() == 0) termina = true;
            }
        }

        if(delay == 0){

            for(int i = 0;i < 3;i++){

                ghost[i].randomMovement(board);

                if(ghost[i].checkIfKill(pac.getX(), pac.getY()) == true)
                {
                    pac.die();//checar se o pacman se moveu para algum fantasma
                ghost[0].setX(1);
                ghost[0].setY(1);
                ghost[1].setX(18);
                ghost[1].setY(18);
                ghost[2].setX(1);
                ghost[2].setY(18);
                ghost[0].setDirecao(3);
                ghost[1].setDirecao(2);
                ghost[2].setDirecao(0);
                ghostInt.setX(18);
                ghostInt.setY(1);
                ghostInt.printCords();
                al_draw_text(font2, al_map_rgb(255,255,255), 800, 480, ALLEGRO_ALIGN_CENTRE,"MORREU, APERTE ESPACO");
                al_flip_display();
                while(!teclas[ALLEGRO_KEY_SPACE])
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada
        teclas[ev.keyboard.keycode] = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) { //Tecla X Liberada

            teclas[ev.keyboard.keycode] = false;
        }
    }
                intent = 0;
                    if(pac.getLives() == 0) termina = true;
                }
            }
            ghostInt.intelligentMovement(board, pac.getX(), pac.getY());

            if(ghostInt.checkIfKill(pac.getX(), pac.getY()) == true)
            {
                pac.die();//checar se o pacman se moveu para algum fantasma
                ghost[0].setX(1);
                ghost[0].setY(1);
                ghost[1].setX(18);
                ghost[1].setY(18);
                ghost[2].setX(1);
                ghost[2].setY(18);
                ghost[0].setDirecao(3);
                ghost[1].setDirecao(2);
                ghost[2].setDirecao(0);
                ghostInt.setX(18);
                ghostInt.setY(1);
                ghostInt.printCords();
                al_draw_text(font2, al_map_rgb(255,255,255), 800, 480, ALLEGRO_ALIGN_CENTRE,"MORREU, APERTE ESPACO");
                al_flip_display();
                while(!teclas[ALLEGRO_KEY_SPACE])
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada
        teclas[ev.keyboard.keycode] = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) { //Tecla X Liberada

            teclas[ev.keyboard.keycode] = false;
        }
    }
                intent = 0;
                if(pac.getLives() == 0) termina = true;
            }

        }
        ghostInt.printCords();
        if(delay == 1)delay = 0;

        else if(delay == 0)delay = 1;

        if(pac.getLives() == 0) termina = true;

        if(board[pac.getY()][pac.getX()] == 0 || board[pac.getY()][pac.getX()] == 3)
        {
            board[pac.getY()][pac.getX()] = 2;
            pac.pacEat();
            if(pac.getScore() == 19000)
            {
                termina = true;
                pac.setWin(true);
            }
        }
            //verificar se o pacman comeu alguma pilula e adicionar ao score

         re_desenha = true;

        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
             esc = true;
            break;

        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada

            teclas[ev.keyboard.keycode] = true;

        }

        else if(ev.type == ALLEGRO_EVENT_KEY_UP) { //Tecla X Liberada

            teclas[ev.keyboard.keycode] = false;

        if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                termina = true;
                esc = true;
        }

        }

        if(re_desenha && al_is_event_queue_empty(event_queue)) {//Redesenha se a fila de eventos esta vazia

            re_desenha = false;
         //Limpa a tela e Redesenha

        //al_draw_bitmap(background,0,0,0);
        al_clear_to_color(al_map_rgb(0,0,0));


        numTij = 0;
        numPil = 0;


        if(timerPellet == 0){

            if(spriteP > 1) spriteP = -1;
            spriteP = spriteP + 1;
            if(spriteP == 0) fator = 1;
            if(spriteP == 2) fator = -1;
            timerPellet = timerPellet + 1;

        }
        else if(timerPellet > 0)timerPellet--;

        al_draw_textf(font, al_map_rgb(255,255,255), 1200, 1000, 0,"SCORE: %d", pac.getScore());
        al_draw_textf(font, al_map_rgb(255,255,255), 1200, 800, 0,"HEARTS: %d", pac.getLives());

        for(int i = 0; i < 20; i++)
        {
            for(int ii = 0; ii < 20; ii++)
            {
                if(board[i][ii] == 0 || board[i][ii] == 3)
                {

                    P[numPil].makePilula(ii,i,spriteP);
                    numPil++;

                }
                else if(board[i][ii] == 1)
                {

                    T[numTij].makeTijolo(ii,i);
                    numTij++;

                }
            }
        }
        //cout<<"Tijolo: "<<numTij<<endl;
        //cout<<"Pilula: "<<numPil<<endl;



        spriteE = spriteE + fatorE; //0 1 2 3 2 1 0
        if(spriteE == 0) fatorE = 1;
        if(spriteE == 3) fatorE = -1;
        pac.drawRegionPacman(sprite,spriteE);
        //funcoes para desenhar o pacman e sprite

        ghost[0].drawGhost(0);
        ghost[1].drawGhost(1);
        ghost[2].drawGhost(2);
        ghostInt.drawGhost(3);
            //funcoes para desenhar os ghosts

        al_flip_display();

        }

    }

    al_destroy_timer(timer);
    al_destroy_sample(sample);

    if(!pac.getWin() && esc == false)
    {
       ALLEGRO_BITMAP *defeat;
       al_clear_to_color(al_map_rgb(0,0,0));
       defeat = al_load_bitmap("defeat.png");
       al_draw_bitmap(defeat,0,0,0);
       al_draw_text(font2, al_map_rgb(0,0,0), 800, 480, ALLEGRO_ALIGN_CENTRE,"GAME OVER");
       al_flip_display();
       al_play_sample(sample3, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL);

       while(!teclas[ALLEGRO_KEY_ESCAPE])
        {
            ALLEGRO_EVENT ev;
            al_wait_for_event(event_queue, &ev);
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada

            teclas[ev.keyboard.keycode] = true;

            }
        }
       al_destroy_bitmap(defeat);
    }
    else if(pac.getWin())
    {
       ALLEGRO_BITMAP *vitoria;
       al_clear_to_color(al_map_rgb(0,0,0));
       vitoria = al_load_bitmap("vitoria.png");
       al_draw_bitmap(vitoria,0,0,0);
       al_flip_display();
       al_play_sample(sample2, 1.0, 0, 1, ALLEGRO_PLAYMODE_LOOP,NULL);

       while(!teclas[ALLEGRO_KEY_ESCAPE])
        {
            ALLEGRO_EVENT ev;
            al_wait_for_event(event_queue, &ev);

            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {//Tecla X Apertada
                teclas[ev.keyboard.keycode] = true;
            }

        }
       al_destroy_bitmap(vitoria);
    }

    al_destroy_display(display);
    al_destroy_bitmap(background);
    al_destroy_font(font);
    al_destroy_event_queue(event_queue);
    al_uninstall_audio();
    al_destroy_sample(sample2);
    al_destroy_sample(sample3);
    //destruindo audio e display

    delete[] P;
    //for(int i = 0; i < 20; i++)
    //  delete[] P[i];
    delete[] T;
    //desalocando vetores para tijolo e pilulas

    return 0;

}
