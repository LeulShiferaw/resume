#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

double pi=3.14159265358979323846264338327950288;
class data
{
	public:
		int r,h;
		double s_area;
		double a_base;

		void compute_sarea(){s_area=pi*r*r+pi*2*r*h;};
		void compute_abase(){a_base=pi*r*r;};
};

double max_sarea(data A[], const int &n, int k, int c, double pabase)
{
	//Base case
	if(n-c==k)
	{
		double res=0;
		for(int i=c; i<n; ++i)
		{
			res+=A[i].s_area-pabase;
			pabase=A[i].a_base;
		}
		return res;
	}else if(k<=0) return 0;
	else if(n-c<k) return 0;

	double temp;
	double greatest=0;
	for(int i=c; i<n; ++i)
	{
		if(n-(i+1)<k-1)
			break;
		temp=A[i].s_area-pabase+max_sarea(A,n,k-1,i+1,A[i].a_base);	
		if(temp>greatest)
			greatest=temp;
	}
	return greatest;
}

data pan_cakes[10];
int main()
{
	int t;
	cin >> t;
	
	int n,k;

	for(int i=0; i<t; ++i)
	{
		cin >> n >> k;
		for(int i=0; i<n; ++i)
		{
			cin >> pan_cakes[i].r >> pan_cakes[i].h;
			pan_cakes[i].compute_sarea();
			pan_cakes[i].compute_abase();
		}
		sort(pan_cakes,pan_cakes+n,[](data a,data b){return a.r<b.r;});

		cout << fixed;
		cout << setprecision(9);
		cout << "Case #" << i+1 << ": " << max_sarea(pan_cakes,n,k,0,0) << endl;
	}
	return 0;
}
