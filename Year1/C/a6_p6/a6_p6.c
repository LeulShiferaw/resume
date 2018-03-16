/*
	JTSK-320111
	a6_p6.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>

int sum(int m, int n)
{
	if(m==n)
		return n;
	return m+sum(m+1, n);
}

int main()
{
	int n, m;

	printf("n: ");
	scanf("%d", &n);
	getchar();

	printf("m: ");
	scanf("%d", &m);
	getchar();

	if(m>n)
	{
		int temp = m;
		m = n;
		n = temp;
	}

	printf("Sum: %d\n", sum(m, n));
	return 0;
}