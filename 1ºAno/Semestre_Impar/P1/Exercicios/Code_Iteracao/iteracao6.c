#include <stdio.h>

int main() {

	float a, x, y, epsilon;

	printf("numero: ");
	scanf("%f", &a);

	printf("estimativa inicial: ");
	scanf("%f", &x);

	epsilon = 0.0001;
	 
	y = ( x + a / x ) / 2;

	while ( ( y - x ) * ( y - x ) >= epsilon * epsilon ) {

		x = y;

		y = ( x + a / x ) / 2;

	};

	printf("A raiz quadrada é %f \n", y);

	return 0;
}
