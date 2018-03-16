#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int k,l;//k-number of sorted lists, l-length of one sorted list
	cin >> k >> l;

	int *ind=new int[k];
	vector<vector<pair<int,int>>> lists;

	int temp;
	for(int i=0; i<k; ++i)
	{
		ind[i]=0;
		vector<pair<int,int>> list;
		for(int j=0; j<l; ++j)
		{
			cin >> temp;
			list.push_back(pair<int,int>(temp,i));
		}
		lists.push_back(list);
	}

	//Create min-heap
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hp;

	//Add the first element of every list to the min-heap
	for(int i=0; i<k; ++i)
	{
		hp.push(lists[i][0]);
	}

	pair<int,int> t;
	vector<int> merged;
	while(!hp.empty())//Go through the heap
	{
		t=hp.top();//Get the first element
		hp.pop();	

		if(ind[t.second]+1<l)//t.second is the index of the list it is in. ind[t.second] is the index it is in the list k. If there is another element in the list add it
		{
			hp.push(lists[t.second][ind[t.second]+1]);//Push the next element in list k
			++ind[t.second];//Increase the current index in that list
		}
		merged.push_back(t.first);
	}

	for(int x:merged)
		cout << x << " ";
	cout << endl;
	return 0;
}
