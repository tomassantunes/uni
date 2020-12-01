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

int main() {
	int c, l, f;
	
	printf("l = ");
	scanf("%d", &l);

	printf("c = ");
	scanf("%d" , &c);
	
	if (c == 0 || c == l){
		
		f = 1;

	}else {

		f = pascal(l - 1, c - 1) + pascal(l - 1, c);
		
	}

	printf("O número pertencente à linha %d e à coluna %d é %d \n", l, c, f);
	
	return 0;
}

