#include <stdio.h>

float primeiro(float v[], int sz){

	int valor;

	for(int i = 0; i < sz; i++){

		for(int x = 0; x < sz; x++){

			if(v[i] <= v[x]){

				valor = v[i];
				printf("panuquisses \n");

			} else {

				valor = 0;
				break;

			}

		}

		if(valor == v[i]) {return valor;}

	}

}

float segundo(float v[], int sz){

	int valor;


}

float terceiro(float v[], int sz){

	int valor;


}


int main() {

	int numTempos;
	float  prim, seg, ter;

	int j = 0;

	printf("Quantos tempos pretende inserir: ");
	scanf("%d", &numTempos);

	float tempos[numTempos];

	for(int i = 1; i <= numTempos; i++){

		printf("Tempo do atleta %d: ", i);
		scanf("%f", &tempos[j]);

		j++;

	}

	prim = primeiro(tempos, numTempos);
	printf("Primeiro: %.1lf \n", prim);

	return 0;
}

