/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Monge Arrays
 *
 *        Version:  1.0
 *        Created:  27.12.2016 03:33:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define INF 1000000000

//Compute leftmost minimum into array r
//A-Monge Array
//R-for storing result
//m-number of rows
//n-number of cols
//c-index of first row. But starts from 1 not 0
void comp_lmm(int **A, int *R, const int &m, const int &n, const int &c)
{
	//Base case
	//Calc smallest for that row
	if(2*c > m)
	{
		int cm1 = c-1;//c-1
		int smallest = INF;
		for(int i = 0; i<n; ++i)
			if(A[cm1][i] < smallest)
			{
				R[cm1] = i;
				smallest = A[cm1][i];
			}
		return;
	}

	//Even cases
	comp_lmm(A, R, m, n, 2*c);

	//Odd cases
	int s = 0, e = 0, small = INF;
	for(int i = c-1; i<m; i+=2*c)
	{
		if(i+c>=m) e = n;//If there is no even next
		else e = R[i+c]+1;//Last index to check is next even row's smallest index. +1 is for j<e in the next loop

		//Go from start(s) to end(e) and find smallest value
		small = INF;
		for(int j = s; j<e; ++j)
			if(A[i][j] < small) 
			{
				R[i] = j;
				small = A[i][j];
			}
		s = R[i];
	}
}

void display(int *A, const int &n)
{
	for(int i = 0; i<n; ++i)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int m = 0, n = 0;

	printf("m, n: ");
	scanf("%d %d", &m, &n);

	//Create Array
	int **A = new int*[m];

	for(int i = 0; i<m; ++i)
	{
		A[i] = new int[n];
		for(int j = 0; j<n; ++j)
			scanf("%d", A[i]+j);
	}

	int *R = new int[m];

	comp_lmm(A, R, m, n, 1);
	display(R, m);

	//Destroy array
	for(int i = 0; i<m; ++i)
	{
		delete[]A[i];
		A[i]=NULL;
	}
	delete[]A;
	delete[]R;
	A = NULL;
	R = NULL;
	return 0;
}
