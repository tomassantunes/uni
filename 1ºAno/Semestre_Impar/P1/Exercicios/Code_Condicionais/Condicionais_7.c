#include <stdio.h>

int main() {

    float altura;

    printf( "altura: " );
    scanf( "%f", &altura );

    if ( altura < 1.3 ) {

        printf( "baixíssima! \n" );

    } else if ( altura >= 1.3 && altura < 1.6 ) {
        
        printf( "baixa! \n" );

    } else if ( altura >= 1.6 && altura < 1.75 ){
        
        printf( "mediana! \n" );

    } else if ( altura >= 1.75 && altura < 1.9 )
    {
        
        printf( "alta! \n" );

    } else if ( altura >= 1.9 ) {
        
        printf( "altíssima! \n" );

    } else {
        
        printf("pessoa inexistente!");

    }
    

    return 0;
}