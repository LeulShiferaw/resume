/*
 * JTSK-320112
 * a2_p4.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Dimensions
	int x,y,z;
	scanf("%d%d%d", &x, &y, &z);

	//Allocate 3-d grid x then y then z
	int ***grid = (int***)malloc(sizeof(int**)*x);
	if(!grid)
	{
		printf("Error allocating!\n");
		return 0;
	}

	int i,j,k;
	for(i=0; i<x; ++i)
	{
		grid[i] = (int**)malloc(sizeof(int*)*y);
		if(!grid[i])
		{
			printf("Error allocating!\n");
			return 0;
		}
		
		//z-axis
		for(j=0; j<y; ++j)
		{
			grid[i][j] = (int*)malloc(sizeof(int)*z);
			if(!grid[i][j])
			{
				printf("Error allocating!\n");
				return 0;
			}
		}	
	}

	//Read values
	for(i=0; i<x; ++i)
		for(j=0; j<y; ++j)
			for(k=0; k<z; ++k)
				scanf("%d", grid[i][j]+k);
	
	//Print all values in the same z axis for each z
	for(i=0; i<z; ++i)
	{
		printf("Section %d:\n", i+1);
		for(j=0; j<x; ++j)
		{
			for(k=0; k<y; ++k)
				printf("%d ", grid[j][k][i]);
			printf("\n");
		}
	}

	//Free Memory
	for(i=0; i<x; ++i)
		for(j=0; j<y; ++j)
			free(grid[i][j]);
	for(i=0; i<x; ++i)
		free(grid[i]);
	free(grid);
	grid=NULL;
	return 0;
}
