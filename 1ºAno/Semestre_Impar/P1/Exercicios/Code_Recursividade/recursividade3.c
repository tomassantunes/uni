#include <stdio.h>

int soma(int n) {
	
	int conta = 0;
	
	while (n > 0){
		
		conta += n;
		n--;
	}
	
	return conta;
}

int main() {

	int n, f;

	printf("número: ");
	scanf("%d",&n);

	if(n == 1) {

		f = 1;

	} else {

		f = n + soma(n - 1);

	}

	printf("o resultado da soma dos %d primeiros termos é %d \n", n, f);

	return 0;
}

