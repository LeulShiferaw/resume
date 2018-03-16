/*
 * JTSK-320112
 * a2_p3.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

//Read the values of Matrix A: nxm
void read(int **A, const int n, const int m)
{
	int i=0, j=0;
	for(i = 0; i<n; ++i)
		for(j = 0; j<m; ++j)
			scanf("%d", A[i]+j);
}

//Multiply Matrix A and B and store it in C.
//Matrix A: n x m
//Matrix B: m x p
//Matrix C: n x p
void multiply(int **A, int **B, int **C, const int n, const int m, const int p)
{
	int i=0, j=0, k=0;
	for(i=0; i<n; ++i)
		for(j=0; j<p; ++j)
			for(k=0; k<m; ++k)
				C[i][j]+=A[i][k]*B[k][j];
}

//Print Matrix A: n x m
void print(int **A, const int n, const int m)
{
	int i, j;
	for(i=0; i<n; ++i)
	{
		for(j=0; j<m; ++j)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}
int main()
{
	int n=0, m=0, p=0;//Dimensions
	scanf("%d%d%d", &n, &m, &p);

	//Create first and third Matrix of dimensions n
	int **M1 = (int**)malloc(sizeof(int*)*n);
	if(M1 == NULL)
	{
		printf("Error allocating!");
		return 0;
	}
	
	int **M3 = (int**)malloc(sizeof(int*)*n);
	if(M3==NULL)
	{
		printf("Error allocating!");
		return 0;
	}

	//Make first and third matrix 'n x m' and 'n x p' respectively
	int i=0;
	for(; i<n; ++i)
	{
		M1[i] = (int*)malloc(sizeof(int)*m);
		M3[i] = (int*)malloc(sizeof(int)*p);
		if(M1[i]==NULL||M3[i]==NULL)
		{
			printf("Error allocating!");
			return 0;
		}
	}

	//Create Matrix 2: m x p
	int **M2 = (int**)malloc(sizeof(int*)*m);
	if(M2 == NULL)
	{
		printf("Error allocating!");
		return 0;
	}

	for(i=0; i<m; ++i)
	{
		M2[i] = (int*)malloc(sizeof(int)*p);
		if(M2[i]==NULL)
		{
			printf("Error allocating!");
			return 0;
		}
	}

	//Read matrices, multiply and store in M3
	read(M1, n, m);
	read(M2, m, p);
	multiply(M1, M2, M3, n, m, p);

	//Display Matrices
	printf("Matrix A:\n");
	print(M1, n, m);
	printf("Matrix B:\n");
	print(M2, m, p);
	printf("The multiplication result AxB:\n");
	print(M3, n, p);

	//Free memory
	for(i=0; i<n; ++i)
	{
		free(M1[i]);
		free(M3[i]);
	}
	for(i=0; i<m; ++i)
		free(M2[i]);
	free(M1);
	free(M2);
	free(M3);	
	return 0;
}
