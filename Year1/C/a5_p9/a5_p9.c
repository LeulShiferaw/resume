/*
	JTSK-320111
	a5_p9.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>

void display_matrix(int matrix[][50], int n)
{
	int i, j;
	for(i = 0; i<n; ++i)
	{
		for(j = 0; j<n; ++j)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

void display_s_diagonal(int matrix[][50], int n)
{
	int i;
	for(i = 0; i<n; ++i)
		printf("%d ", matrix[i][n-1-i]);
	printf("\n"); 
}

int main()
{
	int n;
	int matrix[50][50];
	
	printf("n: ");
	scanf("%d", &n);
	getchar();

	int i, j;
	for(i = 0; i<n; ++i)
		for(j = 0; j<n; ++j)
		{
			scanf("%d", matrix[i]+j);
			getchar();
		}	

	printf("\nMatrix: \n");
	display_matrix(matrix, n);
	printf("\n");
	printf("Secondary diagonal: ");
	display_s_diagonal(matrix, n);
	return 0;
}