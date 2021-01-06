#include <stdio.h>
int main() {
	FILE *f = fopen("antigo.txt", "r"); 
	FILE *fNew = fopen("novo.txt", "w");
	int c = getc(f);
	while (c != EOF) {
		putchar(c);
		fputc(c, fNew);
		c = getc(f);
		
	}

	if (feof(f))
		printf("\n Reached to the end of file.");
	else
		printf("\n Failure.");
	fclose(f);
	return 0;
}
