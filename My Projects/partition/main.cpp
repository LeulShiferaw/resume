/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Number of ways to partition a number 
 *
 *        Version:  1.0
 *        Created:  13.01.2017 08:23:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int n = 0 ;
int **soln;

void initialize()
{
	for(int i = 0; i<=n; ++i)
		for(int j = 0; j<=n; ++j)
			soln[i][j] = -1;
}

//Return number of ways to add x with at most d terms
int f(const int &x, const int &d, const int &s)
{
	if(soln[x][d] != -1)
		return soln[x][d];

	if(x < s)
	{
		printf("%d\n", x);
		return 1;
	}
	else if(x == s)
	{
		printf("%d\n", x);
		return 1;
	}

	if(d==1)
	{
		printf("%d\n", x);
		return 1;
	}

	int r = 0;
	for(int i = s; i<=x; ++i)
	{
		printf("%d ", i);
		r += f(x-i, d-1, s);	
	}
	soln[n][d] = r;
	return r;
}

int main()
{
	//Create array
	int d = 0; //Number of terms
	int s = 0; //Starting from
	
	//Read n and d
	printf("n, d, s: ");
	scanf("%d%d%d", &n, &d, &s);

	soln = new int*[n+1];
	for(int i = 0; i<=n; ++i)
		soln[i] = new int[n+1];

	for(int i = 0; i<=n; ++i)
		for(int j=0; j<=n; ++j)
			soln[i][j] = -1;

	printf("Ans: %d\n", f(n, d, s));

	//Delete Array
	for(int i = 0; i<=n; ++i)
	{
		delete []soln[i];
		soln[i] = NULL;
	}
	delete soln;
	soln = NULL;

	return 0;
}
