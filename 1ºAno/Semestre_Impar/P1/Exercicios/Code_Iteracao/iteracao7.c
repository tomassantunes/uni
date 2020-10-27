#include <stdio.h>

int main() {

	float gasolina95, gasoleo, gasolina98, quantidade, comb, dia, custo;

	gasoleo = 1.149;
	gasolina95 = 1.364;
	gasolina98 = 1.414;

	printf("quantos litros: ");
	scanf("%f", &quantidade);

	printf("tipo (1:gasoleo, 2:gasolina95, 3:gasolina98): ");
	scanf("%f", &comb);

	printf("dia do abastecimento: ");
	scanf("%f", &dia);

	if ( dia < 15 ) {

		if ( comb == 1 ) { custo = gasoleo * quantidade; }
		else if ( comb == 2 ) { custo = gasolina95 * quantidade; }
		else if ( comb == 3 ) { custo = gasolina98 * quantidade; }
		
	} else if ( dia >= 15 && dia <= 31 ) {
		
		gasoleo = gasoleo - 0.023;
		gasolina95 = gasolina95 - 0.021;

		if ( comb == 1 ) { custo = gasoleo * quantidade; }
		else if ( comb == 2 ) { custo = gasolina95 * quantidade; }
		else if ( comb == 3 ) { custo = gasolina98 * quantidade; }

	} else { printf("hmmm... secalhar era melhor repensares esse dia... \n"); };

	printf("o abastecimento vai custar: %.3lf EUR \n", custo);

	return 0;
}
