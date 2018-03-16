#include <iostream>

using namespace std;

typedef const double cdouble;

double expand(cdouble &x, cdouble &e)
{
	double value = 1.0;
	double total = 1.0;

	for (int i = 0; i < 10000; ++i)
	{
		value = value * (e - i) * x / (i + 1);
		total += value;
	}
	return total;
}

double power(cdouble &v, cdouble &e)
{
	return 2.0*expand(v / pow(2, 1 / e) - 1.0, e);
}

int main()
{
	double x = power(8, 1 / 9.0);
	cout << x << endl;
}