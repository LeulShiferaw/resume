#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int d,n;
	int k,s;
	double time=0;

	for(int j=0; j<t; ++j)
	{
		cin >> d >> n;

		time=0;
		for(int i=0; i<n; ++i)
		{
			cin >> k >> s;
			time=max(time,(double)(d-k)/s);
		}
		printf("Case #%d: %.6lf\n", j+1, (double)d/time);
	}

	
	return 0;
}
