#include <queue>
#include <iostream>

using namespace std;

int main()
{
	//Create min-heap
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hp;

	int n;
	cin >> n;
	int temp,key=0;
	for(int i=0; i<n; ++i)
	{
		cin >> temp;
		hp.push(pair<int,int>(key,temp));//Every element has key which increases. So the next element is more improtant
		++key;
	}

	for(int i=0; i<n; ++i)
	{
		cout << hp.top().second << " ";//It is sorted based on the key so the one with the lowest will emerge first
		hp.pop();
	}
	cout << endl;

	cin >> n;
	key=0;
	for(int i=0; i<n; ++i)
	{
		cin >> temp;
		hp.push(pair<int,int>(key,temp));//Samething but the key decreases
		--key;
	}

	for(int i=0; i<n; ++i)
	{
		cout << hp.top().second << " ";//The one with the lowest key is the last element entered
		hp.pop();
	}
	cout << endl;
	return 0;
}
