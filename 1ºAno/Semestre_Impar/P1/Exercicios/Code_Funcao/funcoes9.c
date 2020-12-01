#include <stdio.h>

int eTriangulo(float l1, float l2, float l3) {

	if (l1 != 0 && l2 != 0 && l3!= 0) {

		if ( l1 + l2 > l3) { 

			printf("é triângulo\n"); 

		} else if ( l2 + l3 > l1) { 

			printf("é triângulo\n");

		} else if ( l1 + l3 > l2 ) {

			printf("é triângulo\n");	
		}

	} else {

		printf("não é triângulo\n");

	};

	return 0;

}

int main() {

	float l1, l2, l3, n;

	printf("primeiro lado: ");
	scanf("%f", &l1);

	printf("segundo lado: ");
	scanf("%f", &l2);

	printf("terceiro lado: ");
	scanf("%f", &l3);

	n = eTriangulo(l1, l2, l3);
	printf("%f\n", n);

	return 0;
}

