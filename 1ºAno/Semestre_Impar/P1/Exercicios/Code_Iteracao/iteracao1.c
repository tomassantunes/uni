#include <stdio.h>

int main() {

	int x, y;

	printf("primeiro numero: ");
	scanf("%d", &x);

	printf("segundo numero: ");
	scanf("%d", &y);

	if ( x > y ) {

		printf("1 \n");

	} else if ( x == y ) {

		printf("0 \n");

	} else if ( x < y ) {

		printf("-1 \n");
	
	} else {

		printf("seu sacana! \n");

	}


	return 0;
}
