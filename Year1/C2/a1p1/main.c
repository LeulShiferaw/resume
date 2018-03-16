/*
 * JTSK-320112
 * a1_p1.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>

#define SWAP(A, B, C) {C temp = A; A=B; B = temp;}//C is the type

int main()
{
	int a, b;
	double c, d;
	scanf("%d%d%lf%lf", &a, &b, &c, &d);

	SWAP(a, b, int);
	SWAP(c, d, double);
	printf("After swapping:\n");
	printf("%d\n%d\n%.6lf\n%.6lf\n", a, b, c, d);
	return 0;
}
