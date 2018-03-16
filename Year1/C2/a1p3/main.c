/*
 * JTSK-320112
 * a1_p2.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>

#define MIN(A, B, C) (A < B ? (A < C ? A : C) : (B < C ? B : C))
#define MAX(A, B, C) (A > B ? (A > C ? A : C) : (B > C ? B : C))
#define MID(A, B, C) (MIN(A, B, C) + MAX(A, B, C))/2.0

int main()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);
	printf("The mid-range is: %.6f\n", MID(a, b, c));
	return 0;
}
