#include <stdio.h>
int main(){
	int var1=5;
	char var2='a';
	int *ptr1= &var1;
	char *ptr2 = &var2;
	*ptr2='b';
	printf("var1 tem o endere¸co %p e o valor %d\n", ptr1, var1 );
	printf("var2 tem o endere¸co %p e o valor %c\n", ptr2, *ptr2 );
	printf("tamanho char: %d\n", sizeof(char));
	printf("tamanho char *: %d\n", sizeof(char *));
	printf("tamanho int: %d\n", sizeof(int));
	printf("tamanho int *: %d\n", sizeof(int *));
	printf("ptr1 + 1: %d\n", *ptr1+1);
	printf("ptr2 + 1: %c\n", *ptr2+1);
	printf("simbolo da mulher: %c", ptr2+1);
}
