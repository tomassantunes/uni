#include <stdio.h>

float horaChegada(float hp, float mp, float d, float vm) {

	float minutos, tempo, hc, mc;
	int i;

	tempo = (d / vm) * 60;
	minutos = (hp * 60) + mp + tempo;

	i = 0;

	while ( minutos >= 60 ) {

		minutos -= 60;
		i++;

	} 

	hc = i;
	mc = minutos;

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

	if ( troco == 1 ) { 
		d = 2; 
		vm = 7.5; 
	} else if ( troco == 2 ) { 
		d = 6; 
		vm = 10.9; 
	} else if ( troco == 3 ) { 
		d = 2; 
		vm = 7.5; 
	};

	n = horaChegada(hp, mp, d, vm);
	printf("%f \n", n);

	return 0;
}

