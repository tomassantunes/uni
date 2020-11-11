#include <stdio.h>

int custoEnvio(int numLivros, float custoPrimeira, float custoUnitario) {

	return custoPrimeira + ((numLivros - 1) * custoUnitario);

}

int main() {

	int numLivros;
	float custoPrimeira, custoUnitario, n;

	printf("numero de livros: ");
	scanf("%d", &numLivros);

	custoPrimeira = 10;
	custoUnitario = 8.5;

	n = custoEnvio(numLivros, custoPrimeira, custoUnitario);
	printf("%.2lf \n", n);

	return 0;
}