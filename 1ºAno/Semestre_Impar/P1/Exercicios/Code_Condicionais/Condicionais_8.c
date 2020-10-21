#include <stdio.h>

int main(){

    int num, numTwo;

    printf("números: ");
    scanf("%d %d", &num, &numTwo);

    if ( num % numTwo == 0 ) {
        
        printf("%d é múltiplo de %d \n", num, numTwo);

    } else
    {
        printf("%d não é múltiplo de %d \n", num, numTwo);
    }
    
    
    return 0;
}