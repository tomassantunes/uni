#include <stdio.h>

int main(){

    float x, y;

    printf("coordenadas x y: ");
    scanf("%f %f", &x, &y);

    if ( x > 0 && y > 0 ) {

        printf("quadrante 1 \n");

    } else if ( x < 0 && y > 0 ) {

        printf("quadrante 2 \n");


    } else if ( x < 0 && y < 0 ) {

        printf("quadrante 3 \n");


    } else if ( x > 0 && y < 0 ) {

        printf("quadrante 4 \n");

    } else {

        printf("não sei como conseguem... NÂO EXISTE CARA***");

    }
  
    return 0;
}