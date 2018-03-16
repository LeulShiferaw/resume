#include <set>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

bool dest(const string &str)
{
	int size=str.size();
	for(int i=0; i<size; ++i)
		if(str[i]!='-')
			return false;
	return true;
}

bool fits(const string &str1,const string &str2)
{
	for(unsigned int i=0; i<str1.size(); ++i)
	{
		if(str2[i]=='0')
			continue;
		else if(str2[i]=='-'&&str1[i]!='-')
			return false;
		else if(str2[i]=='+'&&str1[i]!='-')
			return false;
	}
	return true;
}

string transform(const string &str1, const string &str2)
{
	string res="";
	for(unsigned int i=0; i<str1.size(); ++i)
	{
		if(str2[i]=='-')
			res+='-';
		else if(str2[i]=='+')
			res+='+';
		else res+=str1[i];
	}
	return res;
}

bool fastest_fix(const vector<pair<int,pair<string,string>>> &edges, deque<pair<string,int>> &nodes, set<string> &explored, int &smallest)
{
	if(nodes.size()==0)
		return false;
	pair<string,int> curr_node=nodes.front();
	nodes.pop_front();
	if(explored.find(curr_node.first)!=explored.end())
		return false;
	else if(dest(curr_node.first))
	{
		if(curr_node.second<smallest || smallest==-1)
			smallest=curr_node.second;
		return true;
	}

	explored.insert(curr_node.first);
	for(unsigned int i=0; i<edges.size(); ++i)
	{
		if(fits(curr_node.first,edges[i].second.first))
		{
			nodes.push_back(pair<string,int>(transform(curr_node.first,edges[i].second.second),curr_node.second+edges[i].first));
		}
		fastest_fix(edges,nodes,explored,smallest);
	}
	explored.erase(curr_node.first);
}

int main()
{
	int n,m;
	cin >> n >> m;
	while(n!=0 && m!=0)
	{
		string start="";
		for(int i=0; i<n; ++i)
			start+='+';
		deque<pair<string,int>> nodes;
		nodes.push_back(pair<string,int>(start,0));

		int temp;
		string str_temp,str_temp1;
		vector<pair<int,pair<string,string>>> edges;
		for(int i=0; i<m; ++i)
		{
			cin >> temp >> str_temp >> str_temp1;
			edges.push_back(pair<int,pair<string,string>>(temp,pair<string,string>(str_temp,str_temp1)));
		}	

		int smallest=-1;
		set<string> explored;
		fastest_fix(edges,nodes,explored,smallest);

		if(smallest==-1)
			cout << "Bugs cannot be fixed.\n";
		else cout << "Fastest sequence takes " << smallest << " seconds.\n";
		cin >> n >> m;
	}
	
	return 0;
}
