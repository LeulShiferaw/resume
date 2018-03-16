#include <iostream>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

bool csq(const string &str)
{
	if(str.size()!=19)
		return false;
	for(int i=0; i<18; i+=2)
		if(str[i]-'0'!=i/2+1)
			return false;
	return true;
}
int main()
{
	int n=0;
	cpp_int temp;
	stringstream ss;
	
	while(1)
	{
		ss.str(string());
		ss.clear();
		temp=n*n;
		ss << temp;

		if(csq(ss.str()))
		{
			cout << n << endl;
			return 0;
		}
		printf("%d\n", n);	
		n+=10;
	}
		
	return 0;
}
