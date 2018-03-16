#include <vector>
#include <iostream>

using namespace std;

int knapsack(const vector<pair<int,int>> &info, int n, int i)
{
	if(i==-1)
		return 0;
	if(n<info[i].first)
		return 0;
	int temp=knapsack(info,n,i-1);
	int temp1=knapsack(info,n-info[i].first,i-1)+info[i].second;

	if(temp>temp1)
		return temp;
	return temp1;
}

int main()
{
	int n,k;
	cin >> n >> k;

	vector<pair<int,int>> info(k);
	for(int i=0; i<k; ++i)
		cin >> info[i].first >> info[i].second;

	cout << knapsack(info,n,k-1) << endl;
	return 0;
}
