#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int sum_pos_diff(int *A, const int &n)
{
	int res=0;
	int size=n-1;
	for(int i=0; i<size; ++i)
	{
		if(A[i+1]<A[i])
			res+=A[i]-A[i+1];
	}
	return res;
}

int min_rate(int *A, const int &n)
{
	int res=0;
	int size=n-1;
	for(int i=0; i<size; ++i)
	{
		if(A[i+1]<A[i])
		{
			if(ceil((A[i]-A[i+1])/10.0)>res)
				res=ceil((A[i]-A[i+1])/10.0);
		}
	}
	return res;
}

int main()
{
	int t;
	cin >> t;

	int n;
	int *A;
	int met1,met2,temp,temp2;
	float tempf;
	for(int i=0; i<t; ++i)
	{
		cin >> n;
		A=new int[n];
		
		for(int j=0; j<n; ++j)
			cin >> A[j];
		met1=sum_pos_diff(A,n);
		temp=min_rate(A,n);	
		met2=0;
		for(int j=0; j<n-1; ++j)
		{
			tempf=(float)A[j]/temp;
			temp2=ceil(tempf);
			temp2=min(10,temp2);
			temp2*=temp;
			temp2=min(temp2,A[j]);
			met2+=temp2;
		}

		cout << "Case #" << i+1 << ": " << met1 << " " << met2 << endl;
		delete[]A;
	}
	return 0;
}
