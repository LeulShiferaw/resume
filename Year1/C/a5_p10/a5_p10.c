/*
	JTSK-320111
	a5_p10.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>

void sumdiffproddiv(double a, double b, double *sum, double *diff, double *prod, double *div)
{
	*sum = a+b;
	*diff = a-b;
	*prod = a*b;
	*div = a/b;
}

int main()
{
	double a, b;

	printf("Enter a: ");
	scanf("%lf", &a);
	getchar();

	printf("Enter b: ");
	scanf("%lf", &b);
	getchar();

	double sum, diff, prod, div;
	sumdiffproddiv(a, b, &sum, &diff, &prod, &div);
	
	printf("Sum: %lf\nDifference: %lf\nProduct: %lf\nQuotient: %lf\n", sum, diff, prod, div);
	return 0;
}