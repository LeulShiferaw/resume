//What is the probability of choosing three cards in increasing order from a shuffle deck of 10 cards labeled 1 through 10?
#include <iostream>

using namespace std;

int main()
{
	int e = 0;
	for (int i = 0; i <= 7; ++i)
		for (int j = i + 1; j <= 8; ++j)
			for (int k = j + 1; k <= 9; ++k)
				++e;
	cout << e << "/" << 10*9*8 << endl;
}