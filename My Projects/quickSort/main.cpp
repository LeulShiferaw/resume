#include <iostream>
#include <stdio.h>

using namespace std;

//GLOBAL VARIABLES
int n;

void swap(int &a, int &b)
{
	a+=b;
	b=a-b;
	a-=b;
}

void display(int A[], int n)
{
	int i=0; 
	for(;i<n;++i)
		printf("%d ", A[i]);
	printf("\n");
}

void quickSort(int A[], int s, int e)
{
	if(e-s<=1)
		return;
	int i,c=e-1;
	for(i=s;i<c;++i)
	{
		if(A[i]>A[c])
		{
			swap(A[c-1], A[c]);
			if(i!=c-1)
			{
				swap(A[i], A[c]);
				--i;
			}
			--c;
		}
		display(A, n);
	}
	quickSort(A, s, c);
	quickSort(A, c+1, e);
}



int main()
{
	scanf("%d", &n);
	getchar();

	int A[n], i;
	for(i=0; i<n; ++i)
		scanf("%d", A+i);

	quickSort(A, 0, n);
	display(A, n);
	return 0;
}
