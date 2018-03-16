/*
 * JTSK-320112
 * a2_p1.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 0; 
	float arr[n];
	for(; i<n; ++i)
		scanf("%f", arr+i);

	int r = 0;//result
	float *ptr = arr;
	while(*ptr>0)
	{
		++r;
		ptr = ptr+1;
	}
	printf("Before the first negative value: %d elements\n", r);

	return 0;
}
