#include <stdio.h>

int main(){

    float tc, tk, tf;

    printf("valor em celsius: ");
    scanf("%f", &tc);

    tk = tc + 273.15;
    printf("kelvin: %.2lf \n", tk);

    tf = tc * 9 / 5 + 32;
    printf("fahrenheit: %.2lf F \n", tf);

    return 0;
}