#include "Complex.h"

Complex::Complex(const Complex &x)
{
	r = x.r;
	i = x.i;
}

void Complex::print()
{
	cout << noshowpos << r << showpos << i << "i" << endl;
}

Complex Complex::conjugate()
{
	return Complex(r, -i);
}

Complex Complex::add(Complex x)
{
	return Complex(x.get_r() + r, x.get_i() + i);
}

Complex Complex::subtract(Complex x)
{
	return Complex(r - x.get_r(), i - x.get_i());
}

Complex Complex::multiply(Complex x)
{
	return Complex(r*x.get_r() - i*x.get_i(), r*x.get_i() + i*x.get_r());
}


//Operator overload implementations
Complex operator+(const Complex& c1, const Complex& c2)
{
	Complex a(c1.r+c2.r, c1.i+c2.i);
	return a;
}

Complex operator-(const Complex& c1, const Complex& c2)
{
	Complex a(c1.r-c2.r, c1.i-c2.i);
	return a;

}

Complex operator*(const Complex& c1, const Complex& c2)
{
	Complex a(c1.r*c2.r-c1.i*c2.i, (c1.r*c2.i)+c1.i*c2.r);
	return a;
	
}

Complex& Complex::operator=(const Complex& rhs)
{
	this->r=rhs.r;
	this->i=rhs.i;

	return (*this);
}

istream& operator>>(istream& in, Complex& c)
{
	in >> c.r >> c.i;
	return in;
}

ostream& operator<<(ostream& out, const Complex& c)
{
	out << noshowpos << c.r << showpos << c.i << "i" << endl;
	return out;
}
