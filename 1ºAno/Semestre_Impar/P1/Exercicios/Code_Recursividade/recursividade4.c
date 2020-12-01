#include <stdio.h>

int multiplo(int n, int i){

	int conta;
	
	conta = n * i;
	
	return conta;

}

int main() {

	int n, i, f;

	printf("número: ");
	scanf("%d",&n);

	printf("i: ");
	scanf("%d",&i);

	if(n == 0 || i == 0){

		f = 0;

	} else if(n == 1 && i == 1) {

		f = 1;

	} else {

		f = multiplo(n, i);

	}

	printf("O %d-nésimo múltiplo de %d é %d \n", i, n, f);

	return 0;
}

