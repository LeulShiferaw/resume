#include <iostream>

using namespace std;

int range(const int *A, const int &n, const int &k, const int &s, const int &e)
{
	int *C=new int[k+1];
	for(int i=0; i<=k; ++i)
		C[i]=0;
	for(int i=0; i<n; ++i)
		++C[A[i]];
	for(int i=1; i<=k; ++i)
		C[i]+=C[i-1];

	int val;
	if(s==0)
		val=0;
	else val=C[s-1];

	delete[]C;
	
	return C[e]-val;
}

int main()
{
	int n,k;
	cin >> n >> k;
	
	int *A=new int[n];
	for(int i=0; i<n; ++i) cin >> A[i];
			
	int s,e;
	cin >> s >> e;
	cout << "Range (" << s << ", " << e << "): " << range(A,n,k,s,e) << endl;

	delete[]A;
	A=NULL;	

	return 0;
}
