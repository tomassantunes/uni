#include <stdio.h>

float horaChegada(float hp, float mp, float d, float vm) {

	float hora, tempo, hc, mc;
	int i;

	tempo = d / vm;
	hora = (hp * 60 * 60) + (mp * 60) + tempo;
	hora = hora / 60;

	i = 0;

	while ( hora >= 60 ) {

		hora -= 60;
		i++;

	}

	hc = i;
	mc = hora;

	printf("%.0lf h %.0lf min\n", hc, mc);

	return 0;
}

int main() {

	float hp, mp, d, vm, n;
	int troco;

	printf("hora de partida: ");
	scanf("%f", &hp);

	printf("minutos de partida: ");
	scanf("%f", &mp);

	printf("numero do troço (1-3): ");
	scanf("%d", &troco);

	if ( troco == 1 ) { d = 2; vm = 7.5; };
	if ( troco == 2 ) { d = 6; vm = 10.9; };
	if ( troco == 3 ) { d = 2; vm = 7.5; };

	n = horaChegada(hp, mp, d, vm);
	printf("%f \n", n);

	return 0;
}

