#include <stdio.h>

// versão iterativa
int fatorial(int n){

	int conta = 1;

	while(n > 0) {

		conta *= n;
		n--;

	}

	return conta;

}

// versão recursiva
int main() {

	int n, f;

	printf("número: ");
	scanf("%d",&n);

	if(n == 1 || n == 0) {

		f = 1;

	} else {

		f = fatorial(n);

	}

	printf("O fatorial de %d é %d \n", n, f);

	return 0;
}

