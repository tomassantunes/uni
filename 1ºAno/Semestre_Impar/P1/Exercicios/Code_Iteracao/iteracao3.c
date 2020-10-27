#include <stdio.h>

int main() {

	int num, i;

	printf("num: ");
	scanf("%d", &num);

	i = 1;

	while ( i <= num ) {

		printf("%d \n", i);
		i = i +  1;

	}

	i = num - 1;

	while ( i >= 0 ) {

		printf("%d \n", i);
		i = i - 1;
	
	}

	return 0;
}
