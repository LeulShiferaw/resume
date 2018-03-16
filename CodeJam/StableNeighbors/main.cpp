#include <string>
#include <iostream>

using namespace std;

bool check(const string &str, int pos)
{
	if(pos==0)
	{
		if(str[str.size()-1]==str[pos])
			return false;
	}else if(str[pos-1]==str[pos]) return false;

	if((unsigned int)pos==str.size()-1)
	{
		if(str[0]==str[pos])
			return false;
	}else if(str[pos+1]==str[pos]) return false;

	return true;
}

bool correct(string &str, int pos)
{
	int i=pos;
	bool first=true;
	while(true)
	{
		swap(str[i],str[(i+1)%str.size()]);
		if(check(str,(i+1)%str.size()))
			return true;
		else if(first)
			first=false;
		else if((i+1)%str.size()==(unsigned int)pos) return false;
		++i;
		i%=str.size();
	}	
}

bool all_cor(const string &str)
{
	for(unsigned int i=0; i<str.size(); ++i)
		if(!check(str,i)) return false;
	return true;
}

int main()
{
	int t;
	cin >> t;

	int n,r,y,b,o,v,g;
	string ring="";
	for(int i=0; i<t; ++i)
	{
		ring="";
		cin >> n >> r >> o >> y >> g >> b >> v;

		for(int j=0; j<r; ++j)
			ring+='R';
		for(int j=0; j<o; ++j)
			ring+='O';
		for(int j=0; j<y; ++j)
			ring+='Y';
		for(int j=0; j<v; ++j)
			ring+='V';
		for(int j=0; j<b; ++j)
			ring+='B';
		for(int j=0; j<g; ++j)
			ring+='G';

		bool unable=false;
		while(true)
		{
			if(all_cor(ring))
				break;
			for(int j=0; j<n; ++j)
			{
				if(!check(ring,j))
				{
					if(!correct(ring,j))
					{
						unable=true;
						break;
					}
				}
			}	
			if(unable) break;
		}

		cout << "Case #" << i+1 << ": ";
		if(unable) cout << "IMPOSSIBLE" << endl;
		else cout << ring << endl;
	}
	return 0;
}
