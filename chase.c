#include <stdio.h>
#include <string.h>
#include <time.h>
#define ARRAYSIZE 10
#define SUCCES 0
#define FAIL 1

#define UP 57
#define LEFT 61
#define RIGHT 63
#define DOWN 62
#define ESC 27

int display(int *points, int px, int py, int ex, int ey);
int positionlimit(int pchange); /*UPDATE IDEA*/
int enemymovementx(int *points, int px, int py, int ex, int ey);
int enemymovementy(int *points, int px, int py, int ex, int ey);

int main(){
    int *points = 0, playerx = 2, playery = 2, enemyx = 0, enemyy = 0;

    display( points, playerx, playery, enemyx, enemyy );

    return SUCCES;
}

int display(int *points, int px, int py, int ex, int ey){

    system("cls");

    printf("\t POINTS = %i\n\n", points);

    printf("\t px %i  py %i  ex %i  ey %i\n\n", px, py, ex, ey);

    char tab[ARRAYSIZE][ARRAYSIZE];
    int i, j;

    for(i = 0 ; i < ARRAYSIZE ; i++){
        for(j = 0 ; j < ARRAYSIZE ; j++){
             tab[i][j] = '|';
        }
    }

    tab[py][px] = 'O'; /*PLAYER DEFINITIVE POSITION*/
    tab[ey][ex] = 'X'; /*ENEMY DEFINITIVE POSITION*/

    for(i = 0 ; i < ARRAYSIZE ; i++){
        for(j = 0 ; j < ARRAYSIZE ; j++){
            printf(" %c ", tab[i][j]);
        }
        printf("\n");
    }

    int keymov;

    printf("\n  1  \n");
    printf("3 0 4");
    printf("\n  2  \n");

    scanf("%i", &keymov);

    if(keymov == 1){
        py--;
        ey = enemymovementy( points, px, py, ex, ey );
        ex = enemymovementx( points, px, py, ex, ey );
        display( points, px, py, ex, ey );
    } else if(keymov == 2){
        py++;
        display( points, px, py, ex, ey );
    }else if(keymov == 3){
        ey = enemymovementy( points, px, py, ex, ey );
        ex = enemymovementx( points, px, py, ex, ey );
        px--;
        display( points, px, py, ex, ey );
    }else if(keymov == 4){
        ey = enemymovementy( points, px, py, ex, ey );
        ex = enemymovementx( points, px, py, ex, ey );
        px++;
        display( points, px, py, ex, ey );
    } else if(keymov == 0){
        ey = enemymovementy( points, px, py, ex, ey );
        ex = enemymovementx( points, px, py, ex, ey );
        display( points, px, py, ex, ey );
    }

 return SUCCES;
}

positionlimit(int pchange){

    if(pchange >= 4){
        pchange = 4;
    }

 return pchange;
}

enemymovementy(int *points, int px, int py, int ex, int ey){
    int i;
    int xacum = 0, yacum = 0;

    for(i = ex ; i <= px ; i++){
        xacum++;
    }
    for(i = ey ; i <= py ; i++){
        yacum++;
    }

    if(yacum > xacum || yacum == xacum){
        ey++;
    }

 return ey;
}

enemymovementx(int *points, int px, int py, int ex, int ey){
    int i;
    int xacum = 0, yacum = 0;

    if(ex == px){
        return 0;
    } else if (ex > px){
        for(i = ex ; i <= px ; i++){
            xacum++;
        }
        for(i = ey ; i <= py ; i++){
            yacum++;
        }

        if(xacum > yacum || yacum == xacum){
            ex++;
        }
    } else if (ex < px){
        for(i = ex ; i <= px ; i++){
            xacum++;
        }
        for(i = ey ; i <= py ; i++){
            yacum++;
        }

        if(xacum > yacum || yacum == xacum){
            ex++;
        }
    }

 return ex;
}



