#include <stdio.h>

int *vmaior(int *v1, int *v2){
	if(*v1 > *v2){
		printf("endereco = %p, valor = %d", v1, *v1);
	} 
	else { 
		printf("endereco = %p, valor = %d", v2, *v2);
	}
}

int main(){
	int a, b;
	printf("numeros: ");
	scanf("%d %d", &a, &b);
	vmaior(&a, &b);
}
