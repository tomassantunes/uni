#include <stdio.h>

int main(){

    float d, v;

    printf("velocidade: ");
    scanf("%f", &v);

    d = ((v / 10) * (v / 10)) / 2;
    printf("distancia de travagem: %.3lf \n", d);

    return 0;
}