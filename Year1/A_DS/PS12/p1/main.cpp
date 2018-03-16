#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *res=new int[n];
	vector<int> not_taken;
	bool *taken=new bool[n];
	pair<int, pair<int,int>> *A=new pair<int,pair<int,int>>[n];

	for(int i=0; i<n; ++i)
	{
		taken[i]=false;
		A[i].second.second=i+1;	
		cin >> A[i].first >> A[i].second.first;
	}
	sort(A,A+n);

	for(int i=0; i<n; ++i)
		res[i]=-1;
	for(int i=n-1; i>=0; --i)
	{
		if(!taken[A[i].second.first-1])
		{
			res[A[i].second.first-1]=A[i].second.second;
			taken[A[i].second.first-1]=true;
		}
		else
			not_taken.push_back(A[i].second.second);
	}
	
	int j=0;
	for(int i=0; i<n; ++i)
	{
		if(res[i]==-1)
		{
			res[i]=not_taken[j];
			++j;
		}
	}	

	for(int i=0; i<n; ++i)
		cout << res[i] << " ";
	cout << endl;	

	delete[]A;
	delete[]res;
	delete[]taken;

	A=NULL;
	res=NULL;
	taken=NULL;

	return 0;
}
