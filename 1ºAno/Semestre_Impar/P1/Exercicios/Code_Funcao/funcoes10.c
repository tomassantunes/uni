#include <stdio.h>

int haTriangulo(float l1, float l2, float l3) {

	if ( l1 == 0 || l2 == 0 || l3 == 0 ) {

		return  -1;

	} else if ( l1 == l2 && l2 == l3 && ( l1 == 0 || l2 == 0 || l3 == 0 ) ) { 

		return 3; 

	} else if (( l1 == l2 && l2 == l3 && l1 != l3 ) || ( l1 == l2 && l2 != l3 && l1 == l3 ) || ( l1 != l2 && l2 == l3 && l1 == l3 ) && ( l1 == 0 || l2 == 0 || l3 == 0 )) {

		return 2;

	} else if ( l1 != l2 && l2 != l3 && l1 != l3 && ( l1 == 0 || l2 == 0 || l3 == 0 ) ) {

		return 1;

	};

}

int main() {

	float l1, l2, l3, n;

	printf("primeiro lado: ");
	scanf("%f", &l1);

	printf("segundo lado: ");
	scanf("%f", &l2);

	printf("terceiro lado: ");
	scanf("%f", &l3);

	n = haTriangulo(l1, l2, l3);
	printf("%f\n", n);

	return 0;
}
