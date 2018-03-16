#include "hash.h"

using namespace std;

int main()
{
	LastDigitHashSet<int> hs;
	hs.insert(10);
	hs.insert(15);
	hs.insert(78);
	hs.insert(24);
	hs.insert(2);
	hs.insert(20);

	LDHSIterator<int> it(hs);
	while(it.has_next())
		cout << it.next() << " ";
	cout << endl;
	return 0;
}
