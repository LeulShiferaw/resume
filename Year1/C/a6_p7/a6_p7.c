/*
	JTSK-320111
	a6_p7.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>

int gcd(int a, int b)
{
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int main()
{
	int a, b;

	printf("a: ");
	scanf("%d", &a);
	getchar();

	printf("b: ");
	scanf("%d", &b);
	getchar();

	if(a>b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	int _gcd;
	if(!a%b)
		_gcd = b;
	else if(!b%a)
		_gcd = a;
	else
		_gcd = gcd(a, b);

	printf("GCD: %d\n", _gcd);
	return 0;
}