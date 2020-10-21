#include <stdio.h>

int main(){

    int first, second, third;

    printf("primeiro: ");
    scanf("%d", &first);

    printf("segundo: ");
    scanf("%d", &second);

    printf("terceiro: ");
    scanf("%d", &third);

    if ( first < second < third ){

        printf("é o número: %d \n", second);

    } else if  ( second < third < first ){

        printf("é o número: %d \n", third);

    } else if  ( third < first < second ){

        printf("é o número: %d \n", second);

    } else {

        printf("algo está errado :)");

    }

    return 0;
}