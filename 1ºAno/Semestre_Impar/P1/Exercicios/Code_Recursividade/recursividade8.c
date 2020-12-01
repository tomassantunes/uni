#include <stdio.h>

int fatorial(int n){
	
	int conta = 1;

	while(n > 0){

		conta *= n;
		n--;
		
	}
	
	return conta;
}

int pascal(int n, int s) {

	int parteCima, parteBaixo;

	parteCima = fatorial(n);
	
	parteBaixo = fatorial(s) * fatorial(n - s);
	
	return parteCima / parteBaixo;

} 

int trianguloPascal(int n){

	int i = 0, j = 0, comb; 

	while(j <= n - 1) { // cria as linhas, começa na linha 0 (j) e acaba na linha n - 1

		while(i <= j){ // completa as linhas com as combinações de j em i.

			comb = pascal(j, i); // corre a função pascal e devolve 
								 // o resultado da combinação
								 // de j em i.

			printf("%d ", comb); // faz printf dos resultados das combinações
								 // completando as linhas.

			i++; // incrementa 1 ao i, até chegar ao valor de j

		}

		j++; // incrementa 1 ao j, até chegar ao valor de n - 1

		printf("\n"); // passa à próxim linha para não ficarem os valores todos na mesma linha

		i = 0; // dá reset ao valor de i para voltar a entrar no loop de completar as linhas
	}

	return 0;

}

int main() {

	int n;

	printf("número: ");
	scanf("%d", &n);

	trianguloPascal(n);

	return 0;
}

