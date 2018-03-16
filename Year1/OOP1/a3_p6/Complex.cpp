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

