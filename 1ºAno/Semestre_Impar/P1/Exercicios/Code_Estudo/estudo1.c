#include <stdio.h>

int numalg(int n){

    if (n < 10) {

        return 1;

    } else {

        return numalg(n / 10) + 1;

    }
    
}

int main(){

    int f;

    f = numalg(123);
    printf("%d \n", f);

    return 0;

}