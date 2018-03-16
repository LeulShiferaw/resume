/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Merge Sort 
 *
 *        Version:  1.0
 *        Created:  20.12.2016 06:01:45
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define cii const int
#define F(s, e) for(int i = s; i < e; ++i)

void merge(int *A, const int &p, const int &q, const int &r)
{
	int l1 = q-p, l2 = r-q;
	int *L = new int[l1];
	int *R = new int[l2];

	F(0, l1){
		L[i] = A[p+i];
	}
	F(0, l2){
		R[i] = A[q+i];
	}

	int j = p;
	int l = 0;//Index for Left side
	int w = 0;//Index for right side

	while(true){
		if(l >= l1){
			F(w, l2){
				A[j] = R[i];
				++j;
			}
			break;
		}else if(w >= l1){
			F(l, l2){
				A[j] = L[i];
				++j;
			}
			break;
		}

		if(L[l] < R[w]){
			A[j] = L[l];
			++l;
		}else{
			A[j] = R[w];
			++w;
		}
		++j;
	}

	delete[]L;
	delete[]R;
	L = R = NULL;
}

void display(int *A, const int &n)
{
	F(0, n){
		printf("%d ", A[i]);
	}
	printf("\n");

}
int main()
{
	int n = 10;
	int *A = new int[n];

	A[0] = 0;
	A[1] = 2;
	A[2] = 3;
	A[3] = -1;
	A[4] = 1;
	A[5] = 2;
	A[6] = 3;
	A[7] = -6;
	A[8] = -7;
	A[9] = -38;

	display(A, 10);
	merge(A, 0, 3, 6);
	display(A, 10);

	delete[]A;
	A = NULL;
	return 0;
}
