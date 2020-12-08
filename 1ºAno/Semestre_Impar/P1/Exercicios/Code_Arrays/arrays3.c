#include <stdio.h>
#include <stdlib.h>

int matrizIdentidade(int matriz[][10], int n) {

	int t = 0;

	for (int i = 0; i < n; i++){

		if(matriz[i][i] == 1){

			t++;

		}

	}

	if(t == n) { return 1; } else { return 0; } 

}

int main() {

	int f;

	int k[][10] = { 

		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}

	};
		
	f = matrizIdentidade(k, 10);
	if(f == 1) {

		printf("É matriz identidade. \n");

	} else {

		printf("Não é matriz identidade. \n");

	}

	return 0;
}

