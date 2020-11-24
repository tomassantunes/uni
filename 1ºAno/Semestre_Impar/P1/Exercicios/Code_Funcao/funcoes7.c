#include <stdio.h>

float tempoDecorrido(float d, float velocidade) {

	return d / velocidade;

}

int main() {

	float distancia, velocidade, n;

	printf("Distancia: ");
	scanf("%f", &distancia);

	velocidade = 10;

	n = tempoDecorrido(distancia, velocidade);
	printf("t = %.2lf s \n", n);

	return 0;
}

