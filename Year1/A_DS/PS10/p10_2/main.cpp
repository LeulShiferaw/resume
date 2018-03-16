#include <iostream>
#include "matrix22.h"

using namespace std;

void display(const Matrix22 &mat)
{
	for(int i=0; i<2; ++i)
	{
		for(int j=0; j<2; ++j)
			cout << mat.get(i,j) << " ";
		cout << endl;
	}
}

int main()
{
	cpp_int temp[][2]={{1,1},{1,0}};

	Matrix22 F(temp);
	Matrix22Multiplication multiplier;
	display(multiplier.op(multiplier.op(F,F),F));
	return 0;
}
