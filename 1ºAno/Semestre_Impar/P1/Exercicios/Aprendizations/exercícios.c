#include <stdio.h>
// #include <math.h>

int main() {

	int resultado;

	// resultado = 5 + 3 / 2 - 1;
	// printf("%d \n", resultado);

	// int i, j, k;

	// i = 5;
	// j = 10;

	// k = i / 2;
	// i = i + k;
	// j = i - 2 + k;

	// printf("k:%d i:%d j:%d \n", k, i, j);

	int x, i=0, c=0;

    printf("Introduza um valor: ");
    scanf("%d", &x);

    while (i <= x / 2) {
        i = i + 1;
        if (x % i == 0) {
            c = c + 1;
        }
    }

	printf("x:%d i:%d c:%d \n", x, i, c);

    return 0;

}