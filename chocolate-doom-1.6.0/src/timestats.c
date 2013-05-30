#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "doomstat.h"
#include "timestats.h"

float startFPS, endFPS, length, fps; //Variables pour mesurer le temps à chaque tour de boucle
char messFPS[2] ,messCPU[2],messAll[30];
clock_t start, end; //Variables pour récupérer le temps d'utilisation du processeur.
double cpu_time_used;


void timeBeginLoop()
{
    //The clock() function returns the implementation's best approximation to the processor time
    // used by the process since the beginning of an implementation-dependent time related only
    //to the process invocation.
    //clock_t clock(void)
    start = clock();
    // Gets the number of milliseconds since SDL library initialization.
    //Uint32 SDL_GetTicks(void)
    startFPS = SDL_GetTicks();
}

void timeEndLoop()
{
    endFPS = SDL_GetTicks();
    length = (endFPS - startFPS)/1000;
    fps = 1 / length;
    //printf("fps : %f , duree : %f , tempsFin : %f, tempsDebut : %f \n",fps,duree,tempsFin, tempsDebut);
    snprintf(messFPS,2,"%f",fps);
    end = clock();
    //CLOCKS_PER_SEC :  the number of clock ticks per second
    //used to convert the value returned by the clock() function into seconds.
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    snprintf(messCPU,5,"%f",cpu_time_used);
    messAll[0] = '\0';
    strcat(messAll,"FPS : ");
    strcat(messAll,messFPS);
    strcat(messAll," CPU : ");
    strcat(messAll,messCPU);
    players[consoleplayer].message = messAll; //TEST : On affiche le FPS et le CPU time sur l'interface du joueur en haut à gauche.
}

