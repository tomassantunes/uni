#include <stdio.h>

int fibonacci(int n){
	
	int f;
	
	if (n < 2){

		return 1;

	} else {

		f = fibonacci(n - 1) + fibonacci(n - 2);
		return f;

	}
	
}

int main() {

	int n, f;
	
	printf("número: ");
	scanf("%d",&n);

	f=fibonacci(n);
	printf("o resultado fibonacci de %d é %d \n", n, f);

	return 0;
}

