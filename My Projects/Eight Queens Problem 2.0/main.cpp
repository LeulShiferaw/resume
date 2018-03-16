/*Placing queens in an r by c chess board w/out being able to kill eachother.*/

#include <iostream>
#include <string>

using namespace std;

typedef const int cint;

cint c = 16, r = 16;
bool *row; //Availability of each row
bool *diagonal_0;
bool *diagonal_1;
string line = "";

void display(bool **board, cint &nc, cint &nr)
{
	line = "-";
	for (int i = 0; i < nc; ++i)
		line += "--";
		
	cout << line << endl;
	for (int i = 0; i < nr; ++i)
	{
		cout << "|";
		for (int j = 0; j < nc; ++j)
		{
			if (board[i][j])
				cout << "Q";
			else
				cout << " ";
			cout << "|";
		}
		cout << endl;
	}
	cout << line << endl;
}

//cc = current column
void solve(bool **board, cint &nc, cint &nr, int cc, int &n_ways)
{
	for (int i = 0; i < nr; ++i)
	{
		int d_0 = i - cc + nc - 1; //Avoids negative numbers
		int d_1 = i + cc;
		if (!row[i] && !diagonal_0[d_0] && !diagonal_1[d_1])
		{
			if (cc == nc - 1) //Base Case
			{
				++n_ways;
				board[i][cc] = true;

				/*display(board, nc, nr);
				cin.get();*/
				
				board[i][cc] = false;
				continue;
			}

			//Current row is taken and so are the diagonals
			row[i] = true;
			diagonal_0[d_0] = true;
			diagonal_1[d_1] = true;
			board[i][cc] = true;

			solve(board, nc, nr, cc + 1, n_ways);
			
			//Restore
			row[i] = false;
			diagonal_0[d_0] = false;
			diagonal_1[d_1] = false;
			board[i][cc] = false;
		}
	}
	return;
}

int main()
{
	//Create Variables
	int nd = c + r - 1; //Number of Diagonals
	row = new bool[r];  //Is row[i] available?
	diagonal_0 = new bool[nd]; //Goes from top left to bottom right(based on x-y)
	diagonal_1 = new bool[nd]; //Goes from top right to bottom left(based on x+y)

	//Create Board & initialize array row
	bool **board = new bool*[r];
	for (int i = 0; i < r; ++i)
	{
		row[i] = false;
		board[i] = new bool[c];
	}

	//Initialize diagonals
	for (int i = 0; i < nd; ++i)
	{
		diagonal_0[i] = false;
		diagonal_1[i] = false;
	}

	//Initialize Board
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			board[i][j] = false;
	
	//Solve problem
	int n_ways = 0;
	solve(board, c,	r, 0, n_ways);
	cout << "There are " << n_ways << " number of ways to solve this." << endl;

	//Destroy Variables
	delete[]row;
	delete[]diagonal_0;
	delete[]diagonal_1;

	//Destroy Board
	for (int i = 0; i < r; ++i)
		delete[]board[i];
	delete[]board;
}