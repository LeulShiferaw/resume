#include "heap.h"

using namespace std;

int main()
{
	int A[]={5,6,2,3,4,1,2,1};
	Heap hp(A,sizeof(A)/sizeof(int));
	hp.display();
	cout << endl;
	hp.sort();
	hp.display();
	return 0;
}
