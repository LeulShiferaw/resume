/*
	JTSK-320111
	a5_p7.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void two_s_vals(float *arr, int n)
{
	int i;
	float s_val, ss_val;
	if(arr[0]<arr[1])
	{
		s_val = arr[0];
		ss_val = arr[1];
	}
	else
	{
		s_val = arr[1];
		ss_val = arr[0];
	}
	for(i = 0; i<n; ++i)
	{
		if(arr[i]<=s_val)
		{
			ss_val = s_val;
			s_val = arr[i];
		}
		else if(arr[i]<ss_val)
			ss_val = arr[i];
	}

	printf("\nSmallest val: %f\nSecond smallest val: %f\n", s_val, ss_val);
}

int main()
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	getchar();

	float *a = (float*)malloc(sizeof(float)*n);

	int i;
	for(i = 0; i<n; ++i)
	{
		printf("Enter the %dthe value: ", i+1);
		scanf("%f", a+i);
		getchar();
	}

	two_s_vals(a, n);

	free(a);	
	return 0;
}
