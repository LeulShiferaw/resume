#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void flip(char &c)
{
	if(c=='+')
		c='-';
	else c='+';	
}
int main()
{
	int i,n_flip,j,t,k,sz;
	bool is_correct;
	string s;
	cin >> t;
	for(int c=1; c<=t; ++c)
	{
		cin >> s >> k;

		n_flip=0;
		sz=s.size()-k;
		for(i=0; i<sz; ++i)
		{
			if(s[i]=='+') //Only flip if it starts with a +
				continue;
			++n_flip;
			for(j=0; j<k; ++j)
				flip(s[i+j]);
		}

		//Last k elements
		if(s[sz]=='-')
		{
			++n_flip;
			for(j=0;j<k;++j)
				flip(s[sz+j]);
		}

		is_correct=true;
		for(j=0;j<k;++j)
		{
			if(s[sz+j]=='-')
			{
				is_correct=false;
				break;	
			}
		}

		cout << "Case #" << c << ": ";
		if(is_correct) cout << n_flip << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
