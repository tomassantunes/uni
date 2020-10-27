#include <stdio.h>

int main() {

	float num, soma, media, i;

	soma = 0;
	i = 0;

	while ( num != 0 ) {

		printf("Digite o número: ");
		scanf("%f", &num);
		
		soma = soma + num;
		
		if ( num != 0 ) { i = i + 1; };

	};

	media = soma / i;

	printf("%.1lf \n", soma);
	printf("%.1lf \n", media);


	return 0;
}
