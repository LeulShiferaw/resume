/*
	JTSK-320111
	a6_p4.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void display_array(int arr[], int n)
{
	int i;
	for(i = 0; i<n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void triple(int arr[], int size)
{
	int i;
	for(i = 0; i<size; ++i)
		arr[i]*=3;
}

int main()
{
	int n;

	printf("n: ");
	scanf("%d", &n);
	getchar();

	int *a = (int*)malloc(sizeof(int)*n);

	int i;
	for(i = 0; i<n; ++i)
	{
		printf("Enter the %dthe value: ", i+1);
		scanf("%d", a+i);
		getchar();
	}

	display_array(a, n);
	triple(a, n);
	display_array(a, n);

	free(a);
	return 0;
}