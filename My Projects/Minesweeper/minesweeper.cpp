#include <iostream>

using namespace std;

int main()
{
	int rows = -1, cols = -1;
	int case_n = 1;
	cin >> rows >> cols;  //Get row and column

	while(rows!=0&&cols!=0){	//Repeat until a 0 0 read
		//Create the array
		//This is the only I can create
		//an array without using a constexpr int.
		char **grid = new char*[rows];

		//Create rows
		for (int i = 0; i<rows; ++i)
			grid[i] = new char[cols];

		//For each row create a column
		for (int i = 0; i<rows; ++i)
			for (int j = 0; j<cols; ++j)
			{
				char temp;
				cin >> temp;
				grid[i][j] = temp;
			}
		
		//Print Field
		cout << "Field #" << case_n << ": " << endl;
		++case_n;

		//Go through the grid
		for (int i = 0; i<rows; ++i){
			for (int j = 0; j<cols; ++j){
				int mines = 0;            //Number of mines
				if(grid[i][j]=='*'){  
					cout << "*";
					continue;
				}

				//If it can go up
				if(i!=0){
					//Check all the three possibilities
					if(grid[i-1][j]=='*')
						++mines;
					if(j!=0){
						if(grid[i-1][j-1]=='*')
							++mines;
					}
					if(j!=cols-1){
						if(grid[i-1][j+1]=='*')
							++mines;
					}
				}
				//If it can go down
				if(i!=rows-1){
					if(grid[i+1][j]=='*')
						++mines;
					if(j!=0){
						if(grid[i+1][j-1]=='*')
							++mines;
					}
					if(j!=cols-1){
						if(grid[i+1][j+1]=='*')
							++mines;
					}	
				}
				//If it can go left
				if(j!=0)
					if(grid[i][j-1]=='*')
						++mines;
				//If it can go right
				if(j!=cols-1)
					if(grid[i][j+1]=='*')
						++mines;
				//Note: the side mov'ts must be separate b/c there may 
				//be a possibility where it can't go up or down but it can go side to side.
				cout << mines;
			}
			cout << endl;
		}
		//Give the memory back
		for (int i = 0; i<rows; ++i)
			delete []grid[i];
		delete []grid;
		cin >> rows >> cols; //Reread the rows and cols
	}
	return 0;
}