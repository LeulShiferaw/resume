// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b) const;		// calculates the gcd of a and b
	int lcm(int a, int b) const;
	int abs(const int &) const;
public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
								// integers. Denominator by default is 1

	friend std::ostream& operator<<(std::ostream&, const Fraction &);
	friend std::istream& operator>>(std::istream&, Fraction &);
	bool operator<(const Fraction &) const;
	bool operator>(const Fraction &) const;
	Fraction operator+(const Fraction &) const;
	Fraction operator-(const Fraction &) const;
	Fraction operator*(const Fraction &) const;
	Fraction operator/(const Fraction &) const;
	Fraction& operator=(const Fraction &);
};


#endif /* FRACTION_H_ */