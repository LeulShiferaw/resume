/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Testing probability of Monopoly
 *
 *        Version:  1.0
 *        Created:  11.12.2016 21:29:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

#define GO 0
#define CC1 2
#define CC2 17
#define CC3 33
#define CH1 7
#define CH2 22
#define CH3 36
#define JAIL 10
#define C1 11 
#define E3 24
#define H1 37
#define H2 39
#define R1 5
#define R2 15
#define R3 25
#define R4 35
#define U1 12
#define U2 28
#define G2J 30
#define FOR(s, e) for(int i = s; i<e; ++i)

using namespace std;

int rand_range(const int &l, const int &h)
{
	return rand()%(h-l+1)+l;
}

void swap(int *A, const int &a, const int &b)
{
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

void shuffle(int *A, const int &n)
{
	FOR(0, n)
		swap(A, i, rand_range(i, n-1));
}
/*SHUFFLE CARDS!!!!!!!!!!!!!!!!! */
int main()
{
	srand(time(0));
	int total = 0;
	int pos = 0;
	int squares[40];
	
	FOR(0, 40)
		squares[i] = 0;

	int *CC = new int[16];
	int *CH = new int[16];

	FOR(0, 16)
	{
		CC[i] = i;
		CH[i] = i;
	}

	shuffle(CC, 16);
	shuffle(CH, 16);

	int n = 40000000;
	int chance_command = 0;
	int cc_command = 0;//true - Advance to Go, false - Go to Jail
	int rand1, rand2, doubles = 0;
	FOR(0, n)	
	{
		rand1 = rand_range(1, 4);
		rand2 = rand_range(1, 4);

		pos += rand1 + rand2;
		pos %= 40;
		
		
		if(rand1==rand2)
			++doubles;
		else doubles = 0;
		if(doubles==3)
		{
			doubles = 0;
			pos = JAIL;
		}
		if(pos == G2J)
			pos = JAIL;
		
		switch(pos)
		{
			//Community Chest
			case CC1:case CC2:case CC3:
				cc_command%=16;
				if(CC[cc_command]==0)
					pos = GO;
				else if(CC[cc_command]==1)
					pos = JAIL;
				++cc_command;
				break;
			//Chance
			case CH1:case CH2:case CH3:
				chance_command %= 16;
				switch(CH[chance_command])
				{
					case 0: 
						pos = GO;
						break;
					case 1:
						pos = JAIL;
						break;
					case 2:
						pos = C1;
						break;
					case 3:
						pos = E3;
						break;
					case 4:
						pos = H2;
						break;
					case 5:
						pos = R1;
						break;
					case 6:case 7:
						if(pos >= R4)
							pos = R1;
						else if(pos >= R3)
							pos = R4;
						else if(pos >= R2)
							pos = R3;
						else if(pos >= R1)
							pos = R2;
						else pos = R1;
						break;
					case 8:
						if(pos >= U2)
							pos = U1;
						else if(pos >= U1)
							pos = U2;
						else pos = U1;
						break;
					case 9:
						if(pos<3)
							pos = 39-(2-pos);
						else pos-=3;
						break;
				}
				++chance_command;
				break;
				
		}
		++squares[pos%40];
		++total;
	}

	FOR(0, 40)
		cout << i << ": " << (double)squares[i]/total*100 << "%" << endl;
	
	delete[]CC;
	delete[]CH;
	CC = NULL;
	CH = NULL;
	return 0;
}
