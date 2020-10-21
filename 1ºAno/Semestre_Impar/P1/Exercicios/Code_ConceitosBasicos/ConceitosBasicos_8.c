#include <stdio.h>

int main(){

    int num, first, second, third;

    printf("digite um numero de 3 digitos: ");
    scanf("%d", &num);

    first = num / 100;
    printf("%d \n", first);

    second = (num / 10) % 10;
    printf("%d \n", second);

    third = (num % 10) % 10;
    printf("%d \n", third);

    return 0;
}