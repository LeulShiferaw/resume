/*
 * CodeJam Round 1A 2016
 */

#include <string>
#include <iostream>

using namespace std;

char first_diff(const string &str)
{
	char res=str[0];
	for(unsigned int i=1; i<str.size(); ++i)
		if(str[i]!=res)
		{
			res=str[i];
			break;
		}
	return res;
}
string organize(const string &str)
{
	string result="";

	for(unsigned int i=0; i<str.size(); ++i)
	{
		if(result=="")
			result+=str[i];
		else if(str[i]<result[0])
			result+=str[i];
		else if(str[i]>result[0])
			result=str[i]+result;
		else if(str[i]<first_diff(result))
			result+=str[i];
		else 
			result=str[i]+result;
	}

	return result;
}

int main()
{
	int t; 
	cin >> t;
	
	string str;
	for(int i=0; i<t; ++i)
	{
		cin >> str;
		cout << "Case #" << i+1 << ": " << organize(str) << endl;
	}
	return 0;
}
