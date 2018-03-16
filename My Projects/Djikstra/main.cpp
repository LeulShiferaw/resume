#include <iostream>
#include <string>

using namespace std;

const int n = 6;
const int infinity=2000000000;

void djikstras(int curr_node, int destination, bool finished[], int nodes[], int edges[][n])
{
	if(curr_node>=n||curr_node==destination||finished[curr_node])
		return;

	//Calculate distance for all branches of current node
	int new_distance=0;
	for(int i=0; i<n; ++i)
	{
		new_distance=nodes[curr_node];	
		if(nodes[curr_node]==infinity)
			new_distance=0;
		if(edges[curr_node][i]!=-1)
		{
			new_distance+=edges[curr_node][i];
			if(new_distance<nodes[i])
				nodes[i]=new_distance;	
		}
	}

	finished[curr_node]=true;//Done for the current node
	//Recurse for the rest	
	for(int i=0; i<n; ++i)
	{
		if(edges[curr_node][i]!=-1)
			djikstras(i, destination, finished, nodes, edges);
	}
}

void path_way(const int &s, int curr_ind, int curr_dis, int nodes[], int edges[][n], string &path)
{
	if(curr_dis==0 || curr_ind==s)
	{
		path+='0'+curr_ind;
		return;
	}
	for(int i=0; i<n; ++i)
	{
		if(edges[curr_ind][i]!=-1)
		{
			if(edges[curr_ind][i]+nodes[i]==nodes[curr_ind])
			{
				path+='0'+curr_ind;
				path_way(s, i, curr_dis-edges[curr_ind][i], nodes, edges, path);
			}
		}
	}	
}

int main()
{
	int s=0, d=4;
	int nodes[n];
	int edges[n][n]={{-1, 7, 9, -1, -1, 14}, 
			 {7, -1, 10, 15, -1, -1},
			 {9, 10, -1, 11, -1, 200},
			 {-1, 15, 11, -1, 6, -1},
			 {-1, -1, -1, 6, -1, 900},
			 {14, -1, 200, -1, 900, -1}};
	bool finished[n];
	string path="";

	for(int i = 0; i<n; ++i)
	{
		nodes[i]=infinity;
		finished[i]=false;	
	}

	djikstras(s, d, finished, nodes, edges);

	nodes[s]=0;//For calculating path_way
	path_way(s, d, nodes[d], nodes, edges, path);
	cout << nodes[d] << " " << path << endl;
		
	for(int i=0; i<n; ++i)
		cout << nodes[i] << endl;
	return 0;
}
