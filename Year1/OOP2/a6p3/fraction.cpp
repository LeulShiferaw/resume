#include "fraction.h"

Fraction::Fraction(const int x, const int y) : n(x)
{
	d=y;
	if(d==0)
		throw "Invalid data or logical error\n";
}

Fraction::Fraction(const Fraction &rhs) : n(rhs.n),d(rhs.d)
{
	if(d==0)
		throw "Invalide data or logical error\n";
}

Fraction::Fraction(std::string str)
{
	if(str.size()==0)
		throw "Invalid data or logical error\n";

	int res=0;//Temporary variable for numerator then denominator
	if(str[0]=='+')//If it is positive
	{
		res+=0;
	}
	else if(str[0]=='-')//If it negative
	{
		res=-1;
	}
	else res=str[0]-'0';//If it positive w/out sign
	
	unsigned int i=1;
	while(str[i]!='/')//Get all numerator
	{
		if(i>=str.size())
			throw "Invalid data or logical error\n";
		res*=10;
		if(res<0)
			res-=str[i]-'0';
		else res+=str[i]-'0';
		++i;
	}	
	++i;

	n=res;//Numerator = res
	res=0;//Start again for denominator
	if(str[i]=='+')
	{
		res+=0;
	}
	else if(str[i]=='-')
	{
		res=-1;
	}
	else res=str[i]-'0';
	
	++i;
	while((unsigned int)i<str.size())
	{
		res*=10;
		if(res<0)
			res-=str[i]-'0';
		else res+=str[i]-'0';
		++i;
	}
	d=res;
	if(d<0)
	{
		n=-n;
		d=-d;
	}
	else if(d==0)
		throw "Invalid data or logical error\n";
}

bool Fraction::operator<(const Fraction &rhs)
{
	return (((double)n)/d) < (((double)rhs.n)/rhs.d);
}

bool Fraction::operator<=(const Fraction &rhs)
{
	return (((double)n)/d) <= (((double)rhs.n)/rhs.d);
}

bool Fraction::operator>(const Fraction &rhs)
{
	return (((double)n)/d) > (((double)rhs.n)/rhs.d);
}

bool Fraction::operator>=(const Fraction &rhs)
{
	return (((double)n)/d) >= (((double)rhs.n)/rhs.d);
}

bool Fraction::operator==(const Fraction &rhs)
{
	return (((double)n)/d) == (((double)rhs.n)/rhs.d);
}

bool Fraction::operator!=(const Fraction &rhs)
{
	return (((double)n)/d) != (((double)rhs.n)/rhs.d);
}

Fraction Fraction::operator+(const Fraction &rhs)
{
	int den=lcm(d,rhs.d);
	if(den==0)
		throw "Invalid data or logical error\n";

	Fraction x=Fraction(den/(double)d * n + den/(double)rhs.d * rhs.n, den);
	return  x;
}

Fraction Fraction::operator-(const Fraction &rhs)
{
	int den=lcm(d,rhs.d);
	if(den==0)
		throw "Invalid data or logical error\n";
	Fraction x=Fraction(den/(double)d * n - den/(double)rhs.d * rhs.n, den);
	return  x;
}

Fraction Fraction::operator*(const Fraction &rhs)
{
	if(d==0 || rhs.d==0)
		throw "Invalid data or logical error\n";
	int num=n*rhs.n;
	int den=d*rhs.d;
	int gcddn=gcd(num,den);
	Fraction x=Fraction(num/gcddn,den/gcddn);
	return  x;
}

Fraction Fraction::operator/(const Fraction &rhs)
{
	if(d==0 || rhs.n==0 || rhs.d==0)
		throw "Invalid data or logical error\n";
	Fraction inv(rhs.d,rhs.n);
	return (*this)*inv;
}

std::ostream& operator<<(std::ostream &out, const Fraction &frac)
{
	if(frac.d==0)
		throw "Invalid data or logical error\n";
	out << frac.n << "/" << frac.d;
	return out;
}

std::istream& operator>>(std::istream &ins, Fraction &frac)
{
	ins >> frac.n >> frac.d;
	return ins;
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
	n=rhs.n;
	d=rhs.d;
	return *this;
}

int Fraction::gcd(int a, int b)
{
	if(a<0) a*=-1;
	if(b<0) b*=-1;

	if(b<a) std::swap(a,b);
	
	if(a==0) return b;
	return gcd(b%a,a);
}

int Fraction::lcm(int a, int b)
{
	int den=gcd(a,b);
	return a*b/den;
}
