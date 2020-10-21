#include <stdio.h>
#include <math.h>

int main(){

    float num;

    printf("numero: ");
    scanf("%f", &num);

    if ( num > 0 ){

        printf("raiz: %f \n", sqrt(num));
        
    } else {

        printf("o número inserido é negativo.");

    };
    
    return 0;
}