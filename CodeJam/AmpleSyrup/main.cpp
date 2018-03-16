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
		void compute_sarea();
		double abase(){return (double)(r*r*pi);}
};

void data::compute_sarea()
{
	s_area=pi*r*r + pi*2*r*h;
}

data pan_cakes[11];
int main()
{
	int t,n,k;
	cin >> t;
	for(int j=0; j<t; ++j)
	{
		cin >> n >> k;

		for(int i=0; i<n; ++i)
		{
			cin >> pan_cakes[i].r >> pan_cakes[i].h;
			pan_cakes[i].compute_sarea();
		}

		sort(pan_cakes,pan_cakes+n,[](data a, data b){return a.s_area>b.s_area;});
		sort(pan_cakes,pan_cakes+k,[](data a, data b){return a.r>=b.r;});
		double res=0;
		for(int i=0; i<k; ++i)
		{
			res+=pan_cakes[i].s_area;
			if(i!=k-1)
			{
				res-=pan_cakes[i+1].abase();
			}
		}
		cout << fixed;
		cout << setprecision(9);
		cout << "Case #" << j+1 << ": " << res << endl;
	}
	return 0;
}
