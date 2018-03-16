#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_range(int l, int h)
{
	return rand()%(h-l+1)+l;
}

//To sort the one array based on another copy other array to position b of a Pair array
struct Pair
{
	int a, b;
	bool operator<(const Pair& rhs)const{return b<rhs.b;}//For sort to be based on b
};

void permute_sorting(Pair *pairs, const int &n)
{
	const int n_cube=n*n*n;
	for(int i=0; i<n; ++i)
		pairs[i].b=random_range(1, n_cube);//Randomly assign priority
	sort(pairs, pairs+n);//sort based on priority
}

void display(Pair *pairs, const int &n)
{
	for(int i=0; i<n; ++i)
		cout << pairs[i].a << " ";
	cout << endl;
}

int main()
{
	srand(time(0));

	int n;
	cin >> n;

	Pair *pairs=new Pair[n];

	for(int i=0; i<n; ++i)
		cin >> pairs[i].a;

	permute_sorting(pairs, n);
	display(pairs, n);	

	delete pairs;
	pairs=NULL;
	return 0;
}
