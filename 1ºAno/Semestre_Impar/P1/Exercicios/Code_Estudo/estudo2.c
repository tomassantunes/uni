#include <stdio.h>

int logint(int n, int b){

    if(n == 1){

        return 0;

    } else if (n <= b){

        return 1;

    } else {

        return logint(n / b, b) + 1;

    }

}

int main() {

    int f;

    f = logint(20, 2);
    printf("%d \n", f);

    return 0;

}