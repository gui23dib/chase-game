#include <stdio.h>
#include <string.h>
#include <time.h>
#define ARRAYSIZE 10
#define SUCCES 0
#define FAIL 1

int display(int *points);
int pconflict(int e , int p, int *points);
int gameover(int *points);


int main(){
    int points = 0;

    display( &points );

    return SUCCES;
}

int display(int *points){

    printf("\n");
    srand(time(NULL));

    char tab[ARRAYSIZE][ARRAYSIZE];
    int i, j;

    for(i = 0 ; i < ARRAYSIZE ; i++){
        for(j = 0 ; j < ARRAYSIZE ; j++){
             tab[i][j] = '|';
        }
    }

    int pposition = rand()%10;
    int eposition = rand()%10;

    tab[eposition][eposition] = 'O';
    tab[pposition][pposition] = 'X';

    for(i = 0 ; i < ARRAYSIZE ; i++){
        for(j = 0 ; j < ARRAYSIZE ; j++){
            printf(" %c ", tab[i][j]);
        }
        printf("\n");

    }

    pconflict(pposition, eposition, *points);

 return SUCCES;
}

int pconflict(int p, int e, int *points){

    if(e == p){
        gameover(&points);
    }



 return SUCCES;
}

int gameover(int *points){

    printf("\n\n==============================\n");
    printf("\t  GAME OVER\n");
    printf("\t  %i POINTS\n", *points);
    printf("==============================\n");

 return SUCCES;
}
