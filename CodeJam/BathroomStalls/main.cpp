#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	long long n,k,temp,minlr,maxlr;
	cin >> t;

	//Make heap
	priority_queue<long long> q;
	for(int i=0; i<t; ++i)
	{
		q=priority_queue<long long>();
		cin >> n >> k;
		q.push(n);
		for(long long j=0; j<k; ++j)
		{
			temp=q.top();//Everytime you pop add its to elements to heap
			q.pop();
			if(temp%2==0)
			{
				maxlr=temp/2;
				minlr=maxlr-1;
	
				q.push(maxlr);
				q.push(minlr);
			}		
			else
			{
				maxlr=(temp-1)/2;
				minlr=maxlr;
	
				q.push(maxlr);
				q.push(minlr);
			}
		}
		cout << "Case #" << i+1 << ": " << maxlr << " " << minlr << endl;
	}
	return 0;
}
