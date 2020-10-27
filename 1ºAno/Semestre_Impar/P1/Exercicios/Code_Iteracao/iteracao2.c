#include <stdio.h>
#include <math.h>

int main() {

	float cateto, segundoCateto, hipotenusa;

	printf("primeiro cateto: ");
	scanf("%f", &cateto);

	printf("segundo cateto: ");
	scanf("%f", &segundoCateto);

	hipotenusa = sqrt( pow(cateto, 2) + pow(segundoCateto, 2) );
	printf("%.2lf \n", hipotenusa);

	return 0;
}
