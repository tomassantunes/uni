#include <stdio.h>

int main(){

    float usd, eur;
    
    printf("valor em usd: ");
    scanf("%f", &usd);

    eur = 0.85 * usd;

    printf("valor em eur: %.2lf", eur);

    return 0;
}