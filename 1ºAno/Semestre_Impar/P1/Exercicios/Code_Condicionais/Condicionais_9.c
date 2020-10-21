#include <stdio.h>

int main(){

    int num, first, last;

    printf("numero 3 digitos: ");
    scanf("%d", &num);

    first = num / 100;

    last = (num % 10) % 10;

    if ( first == last ) {

        printf("%d é capícua. \n", num);

    } else {
        
        printf("%d não é capícua. \n", num);

    }
    

    return 0;
}