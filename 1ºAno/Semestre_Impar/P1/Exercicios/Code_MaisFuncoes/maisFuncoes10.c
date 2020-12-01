#include <stdio.h>

int fatorial(int n){

    int i, conta = 1;

    i = n;

    while(i >= 1) {

        conta *= i;
        i--;

    }

    return conta;

}

int main(){

    int n, f;
    printf("número = ");
    scanf("%d", &n);

    f = fatorial(n);
    printf("fatorial de %d é %d \n", n, f);

    return 0;

}