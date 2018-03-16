#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int *A, int s, int e, const int &v)
{
    if(s==e-1)
        return s;
        
    int m=(s+e)/2;
    if(A[m]==v)
        return m;
    else if(v<A[m])
        return binary_search(A, s, m, v);
    return binary_search(A, m+1, e, v);
}

int main()
{
    int n,nq;
    cin >> n;
    int *A=new int[n];
    for(int i=0; i<n; ++i)
    {
	    cin >> A[i];
    }

    sort(A, A+n);

    int q;
    cin >> nq;
    for(int i=0; i<nq; ++i)
    {
	cin >> q;
        cout << binary_search(A, 0, n, q)+1 << endl;
    }

    cin.get();
    delete[]A;
    return 0;
}

