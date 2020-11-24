#include <stdio.h>
#include <math.h>


int quadrado(int num) {

	return pow(num + 1, 2);

}

int main() {

	int num, n;

	printf("numero: ");
	scanf("%d", &num);

	n = quadrado(num);
	printf("%d \n", n);


	return 0;
}


