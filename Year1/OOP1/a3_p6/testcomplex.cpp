/*
	CH08-320142
	a3_p6
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Complex.h"

int main()
{
	double x, y;
	Complex a, b;

	cout << "Real and Imaginary 1: ";
	cin >> x >> y;
	a.set_r(x);
	a.set_i(y);

	cout << "Real and Imaginary 2: ";
	cin >> x >> y;
	b.set_r(x);
	b.set_i(y);

	cout << "Conjugate 1: ";
	a.conjugate().print();

	cout << "Conjugate 2: ";
	b.conjugate().print();

	cout << "Sum: ";
	a.add(b).print();

	cout << "Diff: ";
	b.subtract(a).print();

	cout << "Product: ";
	a.multiply(b).print();
	return 0;
}