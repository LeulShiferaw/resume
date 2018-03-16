#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <iostream>

class Fraction
{
	private:
		int n,d;
	public:
		Fraction(std::string);
		Fraction(const Fraction&);
		Fraction(const int,const int);
		bool operator<(const Fraction&);
		bool operator<=(const Fraction&);
		bool operator>(const Fraction&);
		bool operator>=(const Fraction&);
		bool operator==(const Fraction&);
		bool operator!=(const Fraction&);
		Fraction operator+(const Fraction&);
		Fraction operator-(const Fraction&);
		Fraction operator*(const Fraction&);
		Fraction operator/(const Fraction&);
		friend std::ostream& operator<<(std::ostream&,const Fraction&);
		friend std::istream& operator>>(std::istream&,Fraction&);
		Fraction& operator=(const Fraction&);
		int lcm(int,int);
		int gcd(int, int);
};

#endif
