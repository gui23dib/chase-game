#include <stdio.h>
#include <string.h>
#include <time.h>
#define ARRAYSIZE 10

int main(){

    printf("\n");
    srand(time(NULL));

    int tab[ARRAYSIZE][ARRAYSIZE];
    int i, j;

    for(i = 0 ; i < ARRAYSIZE ; i++){
        for(j = 0 ; j < ARRAYSIZE ; j++){
             tab[i][j] = 0;
        }
    }

    tab[rand()%10][rand()%10] = 1;
    tab[rand()%10][rand()%10] = 2;

    for(i = 0 ; i < ARRAYSIZE ; i++){
        for(j = 0 ; j < ARRAYSIZE ; j++){
            printf(" %i ", tab[i][j]);
        }
        printf("\n");

    }

    return 0;
}
