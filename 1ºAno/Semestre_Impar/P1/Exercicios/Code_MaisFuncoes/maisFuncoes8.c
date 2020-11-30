#include <stdio.h>
#include <math.h>

int somaCubos(int num) {

    int first, second, third, conta;

    first = num / 100;
    
    second = (num / 10) % 10;
   
    third = (num % 10) % 10;

    conta = pow(first, 3) + pow(second, 3) + pow(third, 3);

    if(num == conta) {

        printf("É igual. \n");
        return 1;
        
    } else {

        printf("Não é igual. \n");
        return 0;

    }

}

int main(){

    int num, n;
    
    printf("Insira o numero: ");
    scanf("%d",&num);

    n = somaCubos(num);

    return 0;
}