#include <iostream>

class Box
{
private:
	double l, w, h;
public:
	Box(const double &a = 1, const double &b = 1, const double &c = 1):l(a), w(b), h(c){}
	~Box(){}
	Box(const Box &);
	
	//Setters
	void setl(const double &);
	void setw(const double &);
	void seth(const double &);

	//Getters
	double getl() const {return l;}
	double getw() const {return w;}
	double geth() const {return h;}

	void print() const;
	void print_vol() const;
};