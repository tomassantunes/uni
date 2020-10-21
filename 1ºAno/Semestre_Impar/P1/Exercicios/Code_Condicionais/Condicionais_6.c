#include <stdio.h>

int main(){

    float num;

    printf("numero: ");
    scanf("%f", &num);

    if ( num < -10 || ( num >= 5 && num < 45 ) || ( num > 120 && num <= 245 ) ){

        printf("o número encontra-se num dos intervalos. \n");

    } else {

        printf("o número não se encontra nos intervalos. \n");

    };

    return 0;
}