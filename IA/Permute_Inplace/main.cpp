#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_range(int l, int h)
{
	return rand()%(h-l+1) + l;
}

void swap(int &i, int &j)
{
	int temp=i;
	i=j;
	j=temp;
}

void randomize_inplace(int *A, const int &n)
{
	for(int i=0; i<n; ++i)
		swap(A[i], A[random_range(i, n-1)]);
}

void display(int *A, const int &n)
{
	for(int i=0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(0));

	int n;
	cin >> n;
	cin.get();

	int *A=new int[n];

	for(int i=0; i<n; ++i)
	{
		cin >> A[i];
		cin.get();
	}

	while(1)
	{
		randomize_inplace(A, n);
		display(A, n);
		cin.get();
	}

	delete A;
	A=NULL;
	return 0;
}
