/*
 * Leul Shiferaw
 * Problem 658, UVa
 */

#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

typedef pair<string,string> pss;
typedef vector<pair<pair<string,string>,int>> T;

//Check if the transformation is possible from str using transform(pair of strings)
bool is_poss(const string &str, const pss& transform, string &res)
{
	res="";
	for(unsigned int i=0; i<str.size(); ++i)//Go through all the chars
	{
		if(transform.first[i]=='0')
		{
			if(transform.second[i]=='0')
				res+=str[i];
			else if(transform.second[i]=='+')
				res+="+";
			else res+="-";	
			continue;
		}
		else if(transform.first[i]!=str[i]) return false;
		else if(transform.second[i]=='+') res+='+';
		else if(transform.second[i]=='-') res+='-';
		else res+=str[i];
	}	
	return true;
}

//Min time to reach end from initial curr
//curr-current software
//trans-all the possible transformations
//time-is the current time
//d_result-desired result "----..."
int min_time(string curr, const T& trans, int time, const string &d_result, set<string> &traversed)
{
	//Base case
	if(curr==d_result)
		return time;

	//Mark as traversed here so that children node don't go into cycle
	traversed.insert(curr);

	//Go through all its children nodes
	int int_temp=0;          //For next recursion
	string temp="";          //For the transformation
	int smallest_time=-1;    //Smallest time so far currently it is -1 for identifying initial value
	for(unsigned int i=0; i<trans.size(); ++i)
	{
		//Check if transform is possible
		//If transform is not possible continue
		if(!is_poss(curr,trans[i].first,temp))
			continue;	
		else    //Else if possible
		{
			//Check if it has been traversed before
			if(traversed.find(temp)!=traversed.end())//If it has continue
				continue;

			//Else calculate max_time of transformed value with the amount of time spent being the tranformation time
			int_temp=min_time(temp,trans,trans[i].second,d_result,traversed) + time;

			if(smallest_time==-1)			//Inital value
				smallest_time=int_temp;
			else if(int_temp<smallest_time)		//If it is smaller
				smallest_time=int_temp;
		}
	}
	return smallest_time;
}

int main()
{
	int n,m;                       //n-number of bugs, m-number of patches
	string input="";               //The initial bugs
	string d_result="";            //The final bug free code
	set<string> traversed;         //All the traversed strings
	pair<pss,int> temp;            //For reading the transformations
	T transformations;             //All the transformations where the int is the cost
	
	//ifstream file("input.txt");    //For reading the input
	//assert(file.is_open());

	//file >> n >> m;
	cin >> n >> m;
	while(n!=0 && m!=0)
	{
		//Set up the initial bugs and the desired software
		for(int i=0; i<n; ++i)
		{
			input+="+";
			d_result+="-";
		}
	
		//Read the transfomations(patches)
		for(int i=0; i<m; ++i)
		{
			//file >> temp.second >> temp.first.first >> temp.first.second;
			cin >> temp.second >> temp.first.first >> temp.first.second;
			transformations.push_back(temp);
		}	
		
		int res=min_time(input,transformations,0,d_result,traversed);
		if(res<0)
			cout << "Bugs cannot be fixed." << endl;
		else cout << "Fastest sequence takes " << res << " seconds." << endl;
		
		//Reset the values for the next input
		input="";
		d_result="";
		traversed.clear();
		transformations.clear();
		
		//Read the next input
		//file >> n >> m;
		cin >> n >> m;
	}	
	//file.close();
	return 0;
}
