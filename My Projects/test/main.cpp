/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	bool used[n+5];
	for(int i=0; i<n+2; ++i)
		used[i]=false;

	int k=0;
	int s=(n*(n+1))/2;
	for(int i=1; i<=n; ++i)
	{
		if((s-i)%(i+1)!=0)//Else k is a double
			continue;

		k=(s-i)/(i+1);	//Counter part for i
		if(k<=n && k!=i && !used[k])
		{
			cout << i << " " << k << endl;	
			used[k]=true;
			used[i]=true;
		}
	}
	return 0;
}
