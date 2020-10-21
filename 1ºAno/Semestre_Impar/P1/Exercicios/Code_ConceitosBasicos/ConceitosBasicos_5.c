#include <stdio.h>

int main(){

    int num, secNum, soma, dif, pro, div, resto;

    printf("primeiro num: ");
    scanf("%d", &num);

    printf("segundo num: ");
    scanf("%d", &secNum);

    soma = num + secNum;
    printf("soma: %d \n", soma);

    dif = num - secNum;
    printf("diferença: %d \n", dif);

    pro = num * secNum;
    printf("produto: %d \n", pro);

    div = num / secNum;
    printf("divisão: %d \n", div);

    resto = num % secNum;
    printf("resto: %d \n", resto);

    return 0;
}