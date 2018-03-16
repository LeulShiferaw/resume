#include <iostream>

using namespace std;

#define pegs 3   //DON'T CHANGE
#define size 4

class toh
{
private:
	int steps = 0;
	int total_steps = 0;
	int pegs_sum = 0;
	int game[pegs][size];
public:
	toh();
	int left(int a, int b);
	void move(int n, int curr_peg, int f_peg);
	void display();
	int calc_steps(int n);
};

toh::toh()
{
	for (int i = 0; i < size; ++i)
	{
		game[0][i] = i+1;
	}
	for (int i = 1; i < pegs; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			game[i][j] = 0;
		}
	}
	for (int i = 0; i < pegs; ++i)
		pegs_sum += i + 1;
	
	total_steps = calc_steps(size);
}

//Calculate the intermediate step.
int toh::left(int a, int b)
{
	return pegs_sum - a - b;
}

//Make move
//If moving more one disk then do it recursively.
void toh::move(int n, int curr_peg, int f_peg)
{
	if (n - 1 < 0)
	{
		//Make move
		int temp = game[curr_peg][n];
		game[curr_peg][n] = 0;
		for (int i = size - 1; i >= 0; --i)
		{
			if (game[f_peg][i] == 0)
			{
				game[f_peg][i] = temp;
				break;
			}
		}
		++steps;
		cout << "Step " << steps << "/" << total_steps << ": " << endl;
		display();
		cout << endl;
		cout << endl;
		cin.get();
	}
	else if (game[curr_peg][n - 1] == 0)
	{
		//Make move
		int temp = game[curr_peg][n];
		game[curr_peg][n] = 0;
		for (int i = size - 1; i >= 0; --i)
		{
			if (game[f_peg][i] == 0)
			{
				game[f_peg][i] = temp;
				break;
			}
		}
		++steps;
		cout << "Step " << steps << "/" << total_steps << ": " << endl;
		display();
		cout << endl;
		cout << endl;
		cin.get();
	}
	else
	{
		//In order to move everything to one of the pegs
		//move all but the last to the other peg
		//then move the one left to the wanted peg then 
		//put all of them back on
		//Eg.
	    /*	 1      0	   0
			 2      0	   0
		     3      0	   0
			 4		0	   0

			would first move like
			
			0      0	   0
			0      1	   0
			0      2	   0
			4	   3	   0

			then 

			0      0	   0
			0      1	   0
			0      2	   0
			0	   3	   4

			finally
			
			0      0	   1
			0      0	   2
			0      0	   3
			0	   0	   4*/

		int prev_val = game[curr_peg][n - 1]; //Used to get the piece i currently moved i will compare it later when i move it back
		//This is b/c the current index of the piece might not be the same after i move it the first time.

		//Move everything on top out of the way
		move(n - 1, curr_peg, left(curr_peg + 1, f_peg + 1) - 1);

		//Move the one left to the destination
		move(n, curr_peg, f_peg);
		
		int temp;
		for (int i = size - 1; i >= 0; --i)
		{
			if (game[left(curr_peg + 1, f_peg + 1) - 1][i] == prev_val)
				temp = i;
		}
		
		//Then move them back
		move(temp, left(curr_peg + 1, f_peg + 1) - 1, f_peg);
	}

}

void toh::display()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < pegs; ++j)
		{
			cout << game[j][i] << "          ";
		}
		cout << endl;
	}
}

int toh::calc_steps(int n)
{
	if (n == 1)
		return 1;
	return (2 * (calc_steps(n - 1))) + 1;
}

int main()
{
	toh my_game;
	my_game.display();
	cin.get();
	cout << endl;
	cout << endl;
	my_game.move(size-1, 0, pegs-1);
	cout << endl;
	cout << "TA DAA!!!!!!" << endl;
	my_game.display();
}