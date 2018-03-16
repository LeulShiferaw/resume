#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

class RatNum
{
	private:
		cpp_int d, e;
	public:
		RatNum(cpp_int=0, cpp_int=0);
		bool equal(const RatNum&);
		cpp_int gcd(cpp_int, cpp_int);
		RatNum add(const RatNum&);
		RatNum addinv(const RatNum&);//Additive Inverse
		RatNum mult(const RatNum&);
		RatNum multinv(const RatNum&);//Multiplicitive inverse
		RatNum normal();
};

RatNum::RatNum(cpp_int a, cpp_int b)
:d(a)
{
	if(b <= 0)
		throw "E is not positive!";
       	else b=e;	
}

bool RatNum::equal(const RatNum& b)
{
	return d*b.e==e*b.d;
}

cpp_int RatNum::gcd(cpp_int a, cpp_int b)
{
	if(a<b)
	{
		cpp_int temp=a;
		a=b;
		b=temp;
	}
	if(a==0)
		return b;
	return gcd(b%a, a);
}

RatNum RatNum::add(const RatNum& b)
{
	return RatNum(d*b.e+e*b.d, e*b.e);
}

RatNum RatNum::addinv(const RatNum& a)
{
	return RatNum(-a.d, a.e);
}

RatNum RatNum::mult(const RatNum& b)
{
	return RatNum(d*b.d, e*b.e);
}

RatNum RatNum::multinv(const RatNum& a)
{
	return RatNum(a.e, a.d);
}

RatNum RatNum::normal()
{
	cpp_int g=gcd(d, e);
	return RatNum(d/g, e/g);
}

int main()
{
	try{

	}
	catch(const string &s)
	{
		cerr << s << endl;
		return 1;
	}
	return 0;
}
