#include <stdio.h>

int main(){

    float real;
    char caracter;
    int inteiro;

    printf("valor real: ");
    scanf("%f", &real);

    printf("\n caracter: ");
    scanf(" %c", &caracter);

    printf("\n inteiro: ");
    scanf("%d", &inteiro);

    printf("%d %c %.2lf \n", inteiro, caracter, real);

    return 0;
}