#include <stdio.h>

void ordena(int *a, int *b, int *c){
	int number[] = {*a, *b, *c};
	int temp, j, k;
	for(j = 0; j < 3; ++j){
		for(k = j+1; k < 3; ++k){
			if(number[j] > number[k]){
				temp = number[j];
				number[j] = number[k];
				number[k] = temp;
			}
		}
	}
	
	for(int i=0; i<3; i++){
		printf("%d ", number[i]);
	}

}

int main(){

	int a,b,c;
	printf("n�meros: ");
	scanf("%d %d %d", &a, &b, &c);
	
	ordena(&a, &b, &c);
}