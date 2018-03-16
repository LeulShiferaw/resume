#include <map>
#include <set>
#include <iostream>

using namespace std;

int main()
{
	int t;	
	cin >> t;

	int n,temp;
	set<int> res;
	map<int,int> grid_freq;
	for(int i=0; i<t; ++i)
	{
		cin >> n;
		//Create grid
		grid_freq.clear();
		for(int j=0; j<(2*n-1); ++j)
		{
			for(int k=0; k<n; ++k)
			{
				cin >> temp;
				if(grid_freq.find(temp)!=grid_freq.end())
					++grid_freq[temp];
				else grid_freq[temp]=1;
			}
		}

		res.clear();
		for(auto it=grid_freq.begin(); it!=grid_freq.end(); ++it)
		{
			if(it->second%2==1)
				res.insert(it->first);
		}

		cout << "Case #" << i+1 << ": ";
		for(auto it=res.begin(); it!=res.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	return 0;
}
