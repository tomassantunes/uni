#include <stdio.h>

int velocidade ( float vInicial, float aceleracao, float tempo ) {

	return vInicial + (aceleracao * tempo);

}

int main() {

	float vInicial, aceleracao, tempo, n;

	aceleracao = 3;

	printf("velocidade inicial: ");
	scanf("%f", &vInicial);

	printf("tempo em segundos: ");
	scanf("%f", &tempo);

	n = velocidade(vInicial, aceleracao, tempo);
	printf("%.2lf", n);

	return 0;
}

