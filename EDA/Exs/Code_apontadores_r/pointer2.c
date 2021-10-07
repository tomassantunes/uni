#include <stdio.h>

int main(){
	int i, j, *p1, *p2, **pp1, **pp2;
	i = 4;
	j = 5;
	p1 = &i;
	p2 = &j;
	pp1 = &p2;
	pp2 = &p1;
	printf("p1 -> %d, p2 -> %d, pp1 -> %d, pp2 -> %d\n", p1, p2, pp1, pp2);
	printf("i -> %d, *p2 -> %d, &i -> %d, &p2 -> %d, *pp1 -> %d, &(*p1) -> %d, j -> %d, *p1 -> %d, *(&p1) -> %d", i, *p2, &i, &p2, *pp1, *pp2, &(*p1), j, *p1, *(&p1));
}
