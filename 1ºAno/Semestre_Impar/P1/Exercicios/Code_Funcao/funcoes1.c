#include <stdio.h>


int sucessor( int num ) {

	return num + 1;

}

int main() {

	int num, n;

	printf("numero: ");
	scanf("%d", &num);

	n = sucessor(num);
	printf("%d \n", n);

	return 0;
}