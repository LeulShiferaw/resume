#include "fraction.h"

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	if(d == 0)
		throw "Error!\nDenominator is 0";

	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b) const
{
	if(a > b) //a has to be smaller
	{
		a += b;
		b = a - b;
		a -= b;
	}
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

int Fraction::lcm(int a, int b) const
{
	return a * b / gcd(a, b);
}

std::ostream& operator<<(std::ostream& outs, const Fraction& rhs)
{
	outs << rhs.num << "/" << rhs.den;
	return outs;
}

std::istream& operator>>(std::istream& ins, Fraction& rhs)
{
	ins >> rhs.num >> rhs.den;
	while(rhs.den==0)
	{
		std::cout << "Enter denomiator again: ";
		ins >> rhs.den;
	}
	return ins;
}

Fraction Fraction::operator+(const Fraction &rhs) const
{
	int LCM = lcm(den, rhs.den);
	return Fraction((LCM/den)*num + (LCM/rhs.den)*rhs.num, LCM);
}

Fraction Fraction::operator*(const Fraction &rhs) const
{
	return Fraction(num*rhs.num, den*rhs.den);
}

Fraction Fraction::operator/(const Fraction &rhs) const
{
	if(rhs.num == 0)
	{
		std::cout << "Error Dividing!" << std::endl;
		throw "Denominator is 0";
	}
	return Fraction(num*rhs.den, den*rhs.num);
}