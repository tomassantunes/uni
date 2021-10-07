#include <stdio.h>

int verifica_ordem(int vec[], int sz){


	for(int i = 0; i < sz; i++){

		if (vec[i] < vec[i + 1]){

		} else {

			return 0;

		}

	}

	return 1;

}

int main() {

	int f, sz;

	int a[3] = {1, 2, 2};
	int b[5] = {1, 2, 3, 4, 5};
	int c[2] = {2, 4};
	int d[2] = {7, 8};

	f = verifica_ordem(b, 5);
	printf("%d \n", f);

	return 0;
}

