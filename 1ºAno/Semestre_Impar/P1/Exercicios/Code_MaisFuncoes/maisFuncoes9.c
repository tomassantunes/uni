#include <stdio.h>
#include <math.h>

int conta(float x) {

    float somaPrim;

    if(x % 3 == 1){

        somaPrim = x;

    } else if(x % 3 == 2){

        somaPrim = x - ( (1 / x + 2) * pow(x, x + 2) );

    } else if(x % 3 == 3){

        somaPrim = (x - ( (1 / x + 2) * pow(x, x + 2) ) + (( (1 / x + 4) * pow(x, x + 4) )));

    }

    

    return somaPrim;

}

float serie(int x){
    
    float contaFeita;
    int i;

    x = x / 3;

    while(i <= x){

        contaFeita = conta(x);
        x--;
        i++;

    }

    return contaFeita;

}

int main() {

    int x;
    float n;

    printf("valor de x: ");
    scanf("%d", &x);

    n = serie(x);
    printf("resultado: %f \n", n);

    return 0;
}