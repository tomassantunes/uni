#include <stdio.h>
#include <math.h>

int main(){

    float xOne, yOne, xTwo, yTwo, d;

    printf("coordenadas ponto 1 (x, y): ");
    scanf("%f %f", &xOne, &yOne);

    printf("coordenadas ponto 2 (x, y): ");
    scanf("%f %f", &xTwo, &yTwo);

    d = sqrt( pow(xTwo - xOne, 2) + pow(yTwo - yOne, 2) );
    printf("a distância entre os dois pontos é de: %f", d);

    return 0;
}