/*
 * JTSK-320112
 * a4_p3.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

//Return 1 if greater
int ascend(const void *arg1, const void *arg2)
{
	if(*(int*)arg1 > *(int*)arg2)
		return 1;
	else if(*(int*)arg1 < *(int*)arg2)
		return -1;
	else return 0;
}

//Return 1 if less
int descend(const void *arg1, const void *arg2)
{
	if(*(int*)arg1 > *(int*)arg2)
		return -1;
	else if(*(int*)arg1 < *(int*)arg2)
		return 1;
	else return 0;
}

void print(int arr[], int n)
{
	int i;
	for(i=0; i<n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();

	int i;
	int arr[n];
	for(i=0; i<n; ++i)
	{
		scanf("%d", arr+i);
		getchar();
	}	

	int(*fun[2])(const void*, const void*)={ascend, descend};
	char c;
	while(1)
	{
		scanf("%c", &c);
		getchar();

		if(c=='a')
		{
			qsort(arr, n, sizeof(int), fun[0]);
			print(arr, n);
		}
		else if(c=='d')
		{
			qsort(arr, n, sizeof(int), fun[1]);
			print(arr, n);
		}
		else return 0;
	}

	return 0;
}
