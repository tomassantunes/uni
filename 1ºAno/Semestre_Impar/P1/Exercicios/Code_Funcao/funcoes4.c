#include <stdio.h>

int posicao(float pInicial, float vInicial, float tempo, float aceleracao) {

	return pInicial + (vInicial * tempo) + (0.5 * aceleracao * (tempo * tempo)); 

}

int main() {

	float pInicial, vInicial, tempo, aceleracao, n;

	pInicial = 0;
	vInicial = 5;
	aceleracao = 3;

	printf("tempo: ");
	scanf("%f", &tempo);

	n = posicao(pInicial, vInicial, tempo, aceleracao);
	printf("%.2lf", n);

	return 0;
}

