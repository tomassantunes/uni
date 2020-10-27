#include <stdio.h>

int main() {

	float num, soma;

	soma = 0;

	while ( num != 0 ) {

		printf("Digite o número: ");
		scanf("%f", &num);
		soma = soma + num;

	};

	printf("%.1lf", soma);

	return 0;
}
