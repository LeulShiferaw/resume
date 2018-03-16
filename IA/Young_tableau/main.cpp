#include <iostream>

using namespace std;

//Global Variables
int m, n;
const int inf=2000000000;

void swap(int **array, const int &x1, const int &y1, const int &x2, const int &y2)
{
	int temp=array[x1][y1];
	array[x1][y1]=array[x2][y2];
	array[x2][y2]=temp;
}

//Put element into correct position
void heapify(int **table, int x, int y)
{
	//Basecase
	if(x==m-1 && y==n-1)
		return;
	else if(x==m-1)//Last row
	{
		if(table[x][y+1]<table[x][y])
		{
			swap(table,x,y,x,y+1);
			heapify(table,x,y+1);
		}else return;
	}else if(y==n-1)//Last column
	{
		if(table[x+1][y]<table[x][y])
		{
			swap(table,x,y,x+1,y);
			heapify(table,x+1,y);
		}else return;
	}else{//Somewhere else
		if(table[x+1][y]<table[x][y+1])//Compare the two elements
		{
			if(table[x+1][y]<table[x][y])
			{
				swap(table,x,y,x+1,y);
				heapify(table,x+1,y);
			}
			else return;
		}else if(table[x][y+1]<table[x][y])
		{
			swap(table,x,y,x,y+1);
			heapify(table,x,y+1);
		}else return;	
	}
}

int extractMin(int **table)
{
	//Save min
	int min=table[0][0];
	//Swap with last element
	swap(table,0,0,m-1,n-1);
	//Make last element infinity
	table[m-1][n-1]=inf;
	heapify(table,0,0);	
	return min;	
}

void display(int **array,const int &r, const int &c)
{
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			if(array[i][j]==inf)
				cout << "inf ";
			else cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cout << "m,n: ";
	cin >> m >> n;

	//Create table
	int **table=new int*[m];
	for(int i=0; i<m; ++i)
		table[i]=new int[n];

	//Read table
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			cin >> table[i][j];

	display(table,m,n);
	extractMin(table);
	display(table,m,n);

	//Delete Table
	for(int i=0; i<m; ++i)
		delete[]table[i];
	delete[]table;
	table=NULL;
	return 0;
}
