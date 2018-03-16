/*
	JTSK-320111
	a6_p5.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void edge_cases(double *v, int n)
{
	int s_ind = 0, g_ind = 0;
	double s_val = v[0], g_val = v[0];

	int i;
	for(i = 0; i<n; ++i)
	{
		if(v[i]<s_val)
		{
			s_ind = i;
			s_val = v[i];
		}
		else if(v[i]>g_val)
		{
			g_ind = i;
			g_val = v[i];
		}
	}

	printf("\nSmallest's index: %d\nSmallest value: %lf\nGreatest's index: %d\nGreatest value: %lf\n", s_ind, s_val, g_ind, g_val);
}

double norm(double *v, int n)
{
	double result = 0;

	int i;
	for(i = 0; i<n; ++i)
		result+=v[i]*v[i];
	
	return sqrt(result);
}

int main()
{
	int i, n;

	printf("n: ");
	scanf("%d", &n);
	getchar();

	double *v = (double*)malloc(sizeof(double)*n);

	for(i = 0; i<n; ++i)
	{
		printf("Enter v[%d]: ", i);
		scanf("%lf", v+i);
		getchar();
	}

	printf("Norm: %lf", norm(v, n));
	
	edge_cases(v, n);
	
	free(v);
	return 0;
}