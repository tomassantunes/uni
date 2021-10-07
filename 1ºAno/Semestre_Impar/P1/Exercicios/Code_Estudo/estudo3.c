#include <stdio.h>
#include <stdlib.h>

int hello(int n) {

    if(n == 0){

        exit(0);

    } else {

        printf("hello \n");
        hello(n - 1);

    }

}

int main(){

    printf("%d \n", hello(4));

    return 0;

}