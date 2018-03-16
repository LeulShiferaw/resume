#include <iostream>

using namespace std;

//function f(z)
long long fz(const long long &z)
{
	return 2ll*z*z-2*z+1ll;
}

//Digital root
int dig_root(long long x)
{
	int res=0;
	while(x!=0ll)
	{
		res+=(int)(x%10ll);
		x/=10ll;
	}
	if(res%100!=0)
		return dig_root(res);
	return res;
}

//Is perfect square
bool is_perfect_square(long long x)
{
	int temp=dig_root(x);
	if(temp==0||temp==1||temp==4||temp==7)
		return true;
	else return false;	
}

int main()
{
	for(long long i=1; i<=100; i++)
		if(is_perfect_square(i)) cout << i << " ";
	cout << endl;
	return 0;
}
