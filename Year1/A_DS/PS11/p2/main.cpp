#include <string>
#include <iostream>

using namespace std;

int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}

bool find_sol(bool board[][8],bool row[],bool col[],bool dia1[],bool dia2[][8],int cr)
{
	if(cr>=8)
		return true;
	for(int i=0; i<8; ++i)
	{
		//If it doesn't violate a rule
		if(row[cr]||col[i]||dia1[cr+i])continue;
		if(cr>=i)
		{
			if(dia2[0][cr-i]) continue;
		}
		else if(dia2[1][i-cr])continue;

		board[cr][i]=true;
		row[cr]=true;
		col[i]=true;
		dia1[cr+i]=true;
		if(cr>=i) dia2[0][cr-i]=true;
		else dia2[1][i-cr]=true;

		//If it returns true after the next iteration
		//it returns true only if nothing goes wrong until the end
		if(find_sol(board,row,col,dia1,dia2,cr+1))
		{
			return true;
		}

		if(cr>=i)dia2[0][cr-i]=false;
		else dia2[1][i-cr]=false;
		dia1[cr+i]=false;
		row[cr]=false;
		col[i]=false;
		board[cr][i]=false;
	}
	return false;
}

int main()
{
	bool board[8][8];
	string break_str="-----------------";
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			board[i][j]=false;	

	//Contains information of whether there is a queen on a certain row,col,right diagonal,left diagonal when the row>=col and left diagonal when col>row respectively
	bool row[8],col[8],dia1[15],dia2[2][8];

	//Intialize them all to false
	for(int i=0; i<8; ++i)
	{
		row[i]=false;
		col[i]=false;
	}
	for(int i=0; i<15; ++i)
		dia1[i]=false;
	for(int i=0; i<2; ++i)
		for(int j=0; j<8; ++j)
			dia2[i][j]=false;

	find_sol(board,row,col,dia1,dia2,0);

	//Display board
	cout << break_str << endl;
	for(int i=0; i<8; ++i)
	{
		cout << "|";
		for(int j=0; j<8; ++j)
		{
			if(board[i][j])
				cout << "Q|";
			else cout << " |";
		}
		cout << endl;
	}
	cout << break_str << endl;
	cout << endl;
	return 0;
}
