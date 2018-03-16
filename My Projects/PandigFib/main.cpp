#include <iostream>
#include <string>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

bool is_pandig(const string &str)
{	
	if(str.size()<9)
		return false;
	int j;
	bool dig[10];	
	for(j=0; j<10; ++j)
		dig[j]=false;

	for(j=0; j<9; ++j)
	{
		if(str[j]=='0')//It is 1-9 pandigital
			return false;
		else if(dig[str[j]-'0'])//If it exists twice. B/c size is 9 it can't 
			return false;
		else dig[str[j]-'0']=true;
	}
	
	for(j=1; j<10; ++j)//Check 1-9
		if(!dig[j])//If there is one missing 
			return false;
	return true;
}

int main()
{
	int i=1; 
	cpp_int temp;
	cpp_int f1=0;
	cpp_int fn=1;
	stringstream ss;	
	while(1)
	{
		//Last 10 digits
		temp=fn%1000000000;
		ss.str(string());
		ss.clear();
		ss << temp;
		if(is_pandig(ss.str()))
		{
			//First 10 digits
			ss.str(string());
			ss.clear();
			ss << fn;
			if(is_pandig(ss.str()))
			{
				printf("I:%d\n", i);
				return 0;
			}
		}	
		++i;
		fn+=f1;
		f1=fn-f1;
	}	
	return 0;
}
