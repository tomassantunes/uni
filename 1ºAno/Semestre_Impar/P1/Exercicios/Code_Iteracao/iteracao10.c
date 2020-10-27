#include <stdio.h>

int main() {

	int a, b, i = 1, multiploA, multiploB;

	printf("a: ");
	scanf("%d",&a);

	printf("b: ");
	scanf("%d",&b);

	while( i <= 50 ) {

		multiploA = i % a;
		multiploB = i % b;

		if( multiploA == 0 && multiploB == 0 ) { printf("%d: %d %d \n", i, a, b); }
		else if ( multiploA == 0 && multiploB != 0 ) { printf("%d: %d \n", i, a); }
		else if ( multiploA != 0 && multiploB == 0 ) { printf("%d: %d \n", i, b); };

		i = i + 1;

	} 

	return 0;
}
