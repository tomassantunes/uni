#include <stdio.h>

int mdc(int m, int n){

	int d;

	if(m < n) { d = n; } else { d = m; }

	while(m % d != 0 || n % d != 0) {

		d--;
		
	}
	
	return d;

}

int main() {

	int m, n, f;

	printf("m = ");
	scanf("%d", &m);

	printf("n = ");
	scanf("%d", &n);

	if (n == m){
		
		f = m;
		
	}
	else if (m > n)
	{
		f = mdc(m - n, n);
	}
	else if (m<n)
	{
		f = mdc(m ,n - m);
	}

	printf("O máximo divisor comum entre %d e %d é %d \n", m, n, f);

	return 0;
}

