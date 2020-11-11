#include <stdio.h>

int custoEncomenda(int numLivros, float custoUnitario) {

	return numLivros * custoUnitario;

}

int main() {

	int numLivros;
	float custoUnitario, n;

	custoUnitario = 1553667;

	printf("numero de livros: ");
	scanf("%d", &numLivros);

	n = custoEncomenda(numLivros, custoUnitario);
	printf("%.2lf", n);

	return 0;
}

