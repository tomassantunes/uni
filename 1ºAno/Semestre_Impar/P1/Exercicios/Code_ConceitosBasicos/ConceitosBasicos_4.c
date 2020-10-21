#include <stdio.h>

int main(){

    float usd, eur;
    
    printf("valor em eur: ");
    scanf("%f", &eur);

    usd = eur / 0.85;

    printf("valor em usd: %.2lf", usd);    

    return 0;
}