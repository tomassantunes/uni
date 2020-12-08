#include <stdio.h>

int acumulado(int vec[], int sz, int index) {

	int soma = 0;

	for(index; index >= 0; index--){

		soma += vec[index];

	}

	return soma;

}

int main() {

	int f;
	
	int array[] = {1, 2, 3};

	f = acumulado(array, 3, 1);
	printf("O acumulado até ao índice %d é: %d \n", 1, f);

	return 0;
}

