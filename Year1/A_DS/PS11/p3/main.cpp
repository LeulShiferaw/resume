#include <vector>
#include <iostream>

using namespace std;

//e-size
//s1=start 1
//s2=start 2
vector<int> add(const vector<int> &v1, const vector<int> &v2, int e, int s1, int s2)
{
	vector<int> res;
	for(int i=0; i<e; ++i)
		res.push_back(v1[s1+i]+v2[s2+i]);
	return res;
}

vector<int> subtract(const vector<int> &v1, const vector<int> &v2, int e, int s1, int s2)
{
	vector<int> res;
	for(int i=0; i<e; ++i)
		res.push_back(v1[s1+i]-v2[s2+i]);
	return res;
}

vector<int> multiply(const vector<int> &v1, const vector<int> &v2, int s, int e)
{
	if(e==(s+1))
	{
		vector<int> res;
		res.push_back(v1[s]*v2[s]);
		return res;
	}
	
	int m=(s+e)/2;
	vector<int> a=multiply(v1,v2,s,m);
	vector<int> c=multiply(v1,v2,m,e);
	vector<int> sum1=add(v1,v1,m-s,s,m);
	vector<int> sum2=add(v2,v2,m-s,s,m);
	vector<int> b=multiply(sum1,sum2,0,m-s);
	b=subtract(b,a,b.size(),0,0);
	b=subtract(b,c,b.size(),0,0);

	vector<int> res;
	for(unsigned int i=0; i<a.size(); ++i)
		res.push_back(a[i]);
	for(unsigned int i=0; i<b.size(); ++i)
		res.push_back(b[i]);
	for(unsigned int i=0; i<c.size(); ++i)
		res.push_back(c[i]);
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> p(n),q(n);
	for(int i=0; i<n; ++i)
		cin >> p[i];
	for(int i=0; i<n; ++i)
		cin >> q[i];

	vector<int> res=multiply(p,q,0,n);	
	for(unsigned int i=0; i<res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;	
	return 0;
}
