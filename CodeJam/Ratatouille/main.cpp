#include <math.h>
#include <iostream>

using namespace std;

int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}
bool possible(int curr, int desired)
{
	int fold;
	if(curr>desired)
	{
		fold=round(curr/desired);
		if( (((desired*fold)/(double)curr) * 100) <= 110 && (((desired*fold)/(double)curr) * 100) >= 90)
			return true;
	}
	else 
	{
		fold=round(desired/curr);
		if( (((curr*fold)/(double)desired) * 100) <= 110 && (((curr*fold)/(double)desired) * 100) >= 90)
			return true;
	}
	return false;
}

bool possible(int curr1, int curr2, int desired1, int desired2)
{
	return possible(curr1,desired1)&&possible(curr2,desired2);
}

int max_sum(int **grid, bool *taken, int n, int r)
{
	if(r==n)
		return 0;
	int max=-100;
	for(int i=0; i<n; ++i)
	{
		if(taken[i])
			continue;
		taken[i]=true;
		int temp=grid[r][i]+max_sum(grid,taken,n,r+1);
		if(temp > max || max==-100)
		{
			max=temp;
		}	
		taken[i]=false;
	}	
	return max;
}

int main()
{
	int t;
	cin >> t;

	int n,p;
	int *R;
	for(int i=0; i<t; ++i)
	{
		cin >> n >> p;

		R=new int[n];
		for(int j=0; j<n; ++j)
			cin >> R[j];

		if(n==1)
		{
			int *P=new int[p];
			int nkits=0;
			for(int j=0; j<p; ++j)
				cin >> P[j];
			for(int j=0; j<p; ++j)
			{
				//If successful
				if(possible(P[j],R[0]))
					++nkits;
				//Increment nkits
			}
			cout << "Case #" << i+1 << ": " << nkits << endl;	
			delete[]P;
		}
		else if(n==2)
		{
			int *P[2];
			P[0]=new int[p];
			P[1]=new int[p];

			int **grid=new int*[p];
			for(int j=0; j<p; ++j)
				grid[j]=new int[p];

			for(int k=0; k<n; ++k)
			{
				for(int j=0; j<p; ++j)
					cin >> P[k][j];
			}

			//Construct grid
			for(int j=0; j<p; ++j)
			{
				for(int k=0; k<p; ++k)
				{
					if(possible(P[0][j], P[1][k], R[0], R[1]))
						grid[j][k]=1;
					else grid[j][k]=0;
				}
			}

			bool taken[9];
			for(int j=0; j<9; ++j)
				taken[j]=false;
			cout << "Case #" << i+1 << ": " << max_sum(grid,taken,p,0) << endl;
			delete[]P[0];
			delete[]P[1];
			for(int j=0; j<p; ++j)
				delete[]grid[j];
			delete[]grid;
		}
		delete[]R;
	}
	return 0;
}
