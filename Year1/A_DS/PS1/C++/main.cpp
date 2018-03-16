#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int gcd(cpp_int a, cpp_int b)
{
	if(a==0)
		return b;
	else if(b==0)
		return a;
	else if(a==1||b==1)
		return 1;
	else return gcd(b%a, a);//Skips iterative addition
}

int main()
{
	cpp_int a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;
	
	if(b<a)
	{
		cpp_int temp=a;
		a=b;
		b=temp;
	}

	cout << "GCD: " << gcd(a, b) << endl;

	return 0;
}
