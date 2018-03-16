#include <iostream>

using namespace std;

class Complex
{
private:
	double r, i;
public:
	Complex():r(0), i(0){}
	Complex(const double x, const double y):r(x), i(y){}
	Complex(const Complex&);
	~Complex(){}

	//Setters
	void set_i(const double &x){i = x;}
	void set_r(const double &x){r = x;}

	//Getters
	double get_i(){return i;}
	double get_r(){return r;}

	//Methods
	void print();
	Complex add(Complex);
	Complex subtract(Complex);
	Complex multiply(Complex);
	Complex conjugate();

	//Operator overloads
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	Complex& operator=(const Complex&);
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
};
