#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//Partition'
pair<int,int> partition(int *A, const int &p, const int &r)
{
	int j=p-1;
	for(int i=p; i<r-1; ++i)
	{
		if(A[i]<A[r-1])
		{
			++j;
			swap(A[i],A[j]);
		}
	}
	++j;
	int t=j-1;
	swap(A[j],A[r-1]);
	for(int i=j; i<r-1; ++i)
	{
		if(A[i]==A[j])
		{
			++t;
			swap(A[i],A[t]);
		}
	}
	t=max(j,t);
	return pair<int,int>(j,t);
}

int randnum(const int &l, const int &h)
{
	return rand()%(h-l+1)+l;
}

//Random Partitiion'
pair<int,int> randomized_partition(int *A, const int &p, const int &r)
{
	int piv=randnum(p,r-1);
	swap(A[piv],A[r-1]);

	int j=p-1;
	for(int i=p; i<r-1; ++i)
	{
		if(A[i]<A[r-1])
		{
			++j;
			swap(A[i],A[j]);
		}
	}
	++j;
	int t=j-1;
	swap(A[j],A[r-1]);
	for(int i=j; i<r-1; ++i)
	{
		if(A[i]==A[j])
		{
			++t;
			swap(A[i],A[t]);
		}
	}
	t=max(j,t);
	return pair<int,int>(j,t);
}

int hoare_partition(int *A, const int p, const int r)
{
	int x=A[p];
	int i=p-1,j=r+1;
	while(1)
	{
		do
		{
			--j;
		}while(A[j]>x);
		do
		{
			++i;
		}while(A[i]<x);
		if(i<j)	swap(A[i],A[j]);
		else return j;
	}
}

void quickSort(int *A, const int &p, const int &r)
{
	if(p<r)
	{
		pair<int,int> piv=randomized_partition(A,p,r);
		quickSort(A,p,piv.first);
		quickSort(A,piv.second+1,r);
	}
}

void quickSort_(int *A, const int &p, const int &r)
{
	if(p<r)
	{
		int piv=hoare_partition(A,p,r);
		quickSort_(A,p,piv);
		quickSort_(A,piv+1,r);
	}
}

int main()
{
	srand(time(0));

	int n;
	cin >> n;
	int *A=new int[n];
	for(int i=0; i<n; ++i)
		cin >> A[i];

	quickSort(A,0,n);
	cout << "A: ";
	for(int i=0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
