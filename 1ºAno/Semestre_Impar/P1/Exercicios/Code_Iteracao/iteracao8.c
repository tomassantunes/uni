#include <stdio.h>

int main() {

	int num, i, fatorial;

	printf("numero: ");
	scanf("%d",&num);

	if ( num >= 0 ) {

		i = num - 1;

		fatorial = num;

		if ( num == 0 ) { fatorial = 1; };

		while ( i >= 1 ) {

			fatorial = fatorial * i;
			i = i - 1;
			printf("%d %d \n", i, fatorial);

		};

	} else { printf("numero negativo"); };

	printf("fatorial de %d é %d \n", num, fatorial);

	return 0;
}
