#include <iostream>

using namespace std;

bool full(char **grid, const int &r, const int &c)
{
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j)
			if(grid[i][j]=='?')
				return false;
	return true;
}

bool empty(char **grid, const int &i, const int &c)
{
	for(int j=0; j<c; ++j)
		if(grid[i][j]!='?')
			return false;
	return true;
}
void extend(char **grid, const int &r, const int &c)
{
	char prev;
	for(int i=0; i<r; ++i)
	{
		prev='-';
		for(int j=0; j<c; ++j)
		{
			//If cell empty
			if(grid[i][j]=='?')
			{
				if(prev=='-')//If there was nothing prior to it
				{
					if(j==c-1)//If this is the last column
					{
						if(i>0)//If it is not at the top
						{
							if(!empty(grid,i-1,c))//Check if the row above is empty
							{
								for(int k=0; k<c; ++k)//Copy the row above
									grid[i][k]=grid[i-1][k];
							}
							else if(i<r-1)//If it not at the bottom
							{
								for(int k=0; k<c; ++k)//Copy the row below
									grid[i][k]=grid[i+1][k];
							}
						}	
						else if(i<r-1)//If it not at the bottom
						{
							for(int k=0; k<c; ++k)//Copy the row below
								grid[i][k]=grid[i+1][k];
						}
					}
					continue;
				}
				else grid[i][j]=prev;
			}	
			else if(prev=='-')
			{
				prev=grid[i][j];
				//Go back
				for(int k=j-1; k>=0; --k)
					grid[i][k]=prev;
			}
			else prev=grid[i][j];
		}
	}
}

int main()
{
	int t;
	cin >> t;

	int r,c;
	char **grid;
	for(int i=0; i<t; ++i)
	{
		cin >> r >> c;
		grid=new char*[r];
		for(int j=0; j<r; ++j)
			grid[j]=new char[c];

		for(int j=0; j<r; ++j)
		{
			for(int k=0; k<c; ++k)
			{
				cin >> grid[j][k];	
			}
		}

		while(!full(grid, r, c))
		{
			extend(grid,r,c);
		}

		cout << "Case #" << i+1 << ": " << endl;
		for(int j=0; j<r; ++j)
		{
			for(int k=0; k<c; ++k)
				cout << grid[j][k];
			cout << endl;
		}
	
		for(int j=0; j<r; ++j)
			delete[]grid[j];
		delete[]grid;
	}
	return 0;
}
