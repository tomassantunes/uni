#include <stdio.h>

int elementoExiste(int x, int vec[], int sz) {

	for(int i = 0; i < sz; i++) { 

		if(vec[i] == x){ 

			return 1;

		}

	}

	return 0;

}

int contaElementos(int v1[], int v2[], int sz1, int sz2) {

	int f;
	int numerosIguais = 0;

	for(int j = 0; j < sz2; j++) { 

		f = elementoExiste(v2[j], v1, sz1);

		if( f == 1 ) {

			numerosIguais++;

		}

	
	}

	return numerosIguais;

}

int main() {

	int f; 

	int a[3] = {1, 2, 2};
	int b[5] = {1, 2, 3, 4, 5};
	int c[2] = {2, 4};
	int d[2] = {7, 8};
	
	f = contaElementos(b, c, 5, 2);

	printf("Número de números iguais: %d \n", f);

	return 0;
}

