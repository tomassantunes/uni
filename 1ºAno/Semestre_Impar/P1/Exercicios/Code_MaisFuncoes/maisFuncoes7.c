#include <stdio.h>

int perfeito(int num){

    int i, conta ;

    i = 1;
    conta = 0;

    while(i < num) {

        if(num % i == 0) {

            conta = conta + i;

        }
        i++;

    }

    if(conta == num) {

        printf("O número é perfeito. \n");

    } else {

        printf("Não é perfeito. \n");

    }


    return 0;
}



int main(){
    
    int num,n;

    printf("Insira um numero: ");
    scanf("%d", &num);

    n=perfeito(num);
    printf("%d",n);

    return 0;
}