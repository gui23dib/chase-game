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
int gameover(int *points, int px, int py, int ex, int ey);

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

    ey = enemymovementy( points, px, py, ex, ey );
    ex = enemymovementx( points, px, py, ex, ey );

    if(keymov == 1){
        py--;
    } else if(keymov == 2){
        py++;
    }else if(keymov == 3){
        px--;
    }else if(keymov == 4){
        px++;
    } else if(keymov == 0){

    }

    points ++;
    gameover( points, px, py, ex, ey );
    display( points, px, py, ex, ey );


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

    if(ey == py){

        return ey;

    } else if (ey > py){

        for(i = py ; i <= ey ; i++){
            yacum++;
        }
        for(i = px ; i <= ey ; i++){
            xacum++;
        }

        if(yacum > xacum || yacum == xacum){
            ey--;
        }

    } else if (ey < py){

        for(i = ey ; i <= py ; i++){
            yacum++;
        }
        for(i = ex ; i <= px ; i++){
            xacum++;
        }

        if(yacum > xacum || yacum == xacum){
            ey++;
        }

    }

 return ey;
}

enemymovementx(int *points, int px, int py, int ex, int ey){
    int i;
    int xacum = 0, yacum = 0;

    if(ex == px){

        return ex;

    } else if (ex > px){

        for(i = px ; i <= ex ; i++){
            xacum++;
        }
        for(i = py ; i <= ey ; i++){
            yacum++;
        }

        if(xacum > yacum || yacum == xacum){
            ex--;
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

gameover(int *points, int px, int py, int ex, int ey){
    int i, j;

    if(px == ex && py == ey){
        printf("GAME OVER\n");
        printf("POINTS: %i\n", points);
        exit(1);
    }

 return SUCCES;
}