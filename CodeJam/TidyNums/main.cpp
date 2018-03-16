
#include <math.h>
#include <deque>
#include <iostream>

using namespace std;

deque<int> digits(long long n)
{
	deque<int> res;

	do
	{
		res.push_front(n%10);	
		n/=10;
	}while(n!=0);

	return res;
}

bool is_tidy(long long n)
{
	int prev=10;

	while(n!=0)
	{
		if(n%10 > prev) return false;
		prev=n%10;
		n/=10;
	}
	return true;
}

bool is_tidy(const deque<int> &vec)
{
	int prev=10;

	for(int i=vec.size()-1; i>=0; --i)
	{
		if(vec[i]>prev) return false;
		prev=vec[i];
	}
	return true;
}

long long number(const deque<int> &vec)
{
	long long mul=1;
	long long res=0;
	for(int i=vec.size()-1; i>=0; --i,mul*=10)
		res+=mul*vec[i];
	return res;	
}

void throw_tidy(unsigned int i, const deque<int> &orig, deque<int> &curr, unsigned int first)
{
	if(i==orig.size())
	{
		if(is_tidy(curr) && number(curr)<=number(orig))
			throw curr;
		else return;
	}

	if(i==first)
	{
		for(int j=0; j<=orig[i]; ++j)
		{
			curr[i]=(orig[i]-j);
			throw_tidy(i+1,orig,curr,first);
		}
		++first;
	}
	else if(i>first)
	{
		for(int j=9; j>=0; --j)
		{
			curr[i]=j;
			if(curr[i]<curr[i-1])
				return;
			throw_tidy(i+1,orig,curr,first);
		}
	}
}


long long catch_tidy(const deque<int> &orig)
{
	try
	{
		deque<int> curr;
		for(unsigned int i=0; i<orig.size(); ++i)
			curr.push_back(orig[i]);
		throw_tidy(0,orig,curr,0);
	}
	catch(const deque<int> &vec)
	{
		return number(vec);
	}

	cout << "ERROR DOESN'T CATCH ANYTHING!!!\n";
}

int main()
{
	/* Small Case 
	int t,n;
	cin >> t;

	for(int i=0; i<t; ++i)
	{
		cin >> n;
		while(true)
		{
			if(is_tidy(n)) break;
			n--;
		}
		cout << "Case #" << i+1 << ": " << n << endl;
	}
	return 0;
	*/

	int t;
	cin >> t;
	
	long long n;
	deque<int> digs;
	for(int i=0; i<t; ++i)
	{
		cin >> n;
		digs.clear();
		digs=digits(n);	
		
		cout << "Case #" << i+1 << ": " << catch_tidy(digs) << endl;
	}

	return 0;
}
