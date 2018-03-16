/*
	JTSK-320111
	a5_p6.c
	Leul Shfieraw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

double maxdiff(double arr[], int n)
{
	int i;
	double g_val = arr[0], s_val = arr[0];
	for(i = 1; i<n; ++i)
	{
		if(arr[i]<s_val)
			s_val = arr[i];
		if(arr[i]>g_val)
			g_val = arr[i];
	}

	return g_val-s_val;
}

int main()
{
	int n;
	
	printf("Enter n: ");
	scanf("%d", &n);
	getchar();

	double *a = (double*)malloc(sizeof(double)*n);

	int i;
	for(i = 0; i<n; ++i)
	{
		printf("Enter %dth value: ", i+1);
		scanf("%lf", a+i);
		getchar();
	}

	printf("\nMaximum difference: %lf\n", maxdiff(a, n));

	free(a);
	return 0;
}