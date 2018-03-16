#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

const long long limit=1e18;

long long rand(const long long &l, const long long &h)
{
	return rand()%(h-l+1) + l;
}

int main()
{
	srand(time(0));	

	int n,k;
	cout << 100 << endl;
	for(int i=0; i<98; ++i)
	{
		n=rand(1,limit);
		k=rand(1,n);
		cout << n << " " << k << endl;
	}

	cout << limit << " " << limit << endl;
	cout << limit << " " << 1 << endl;
	return 0;
}
