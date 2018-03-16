#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

enum STATUS{DRAW, X, O, UNKNOWN};

//To hold the ai's move and score simultaeneously.
struct AI_move
{
	AI_move(){};
	AI_move(int s){ score = s; }
	int pos;
	int score;
};

class TTT
{
private:
	string turn = "X";
	string board[9];
public:
	TTT();	
	void display();
	void switch_turn();
	void make_move(int x);
	string state(int i);
	string get_turn(){ return turn; }
	STATUS status();
	AI_move ai_move(string m_turn);
};

TTT::TTT()
{
	board[0] = "0";
	board[1] = "1";
	board[2] = "2";
	board[3] = "3";
	board[4] = "4";
	board[5] = "5";
	board[6] = "6";
	board[7] = "7";
	board[8] = "8";
}

void TTT::display()
{
	cout << "=======" << endl;
	for (int i = 0; i < 9; ++i)
	{
		if ((i + 1) % 3 == 0)
		{
			cout << "|" << board[i] << "|" << endl;
			continue;
		}
			
		cout << "|" << board[i];
	}
	cout << "=======";
}

void TTT::switch_turn()
{
	if (turn == "X")
		turn = "O";
	else
		turn = "X";
}

//Make move i according to turn
//then switch turn.
void TTT::make_move(int x)
{
	board[x] = turn;
	switch_turn();
}

//Return O if "O" won
//       X if "X" won
//       DRAW if draw
//       UNKNOWN if not finished.
STATUS TTT::status()
{
	for (int i = 1; i < 3; ++i)
	{
		if (board[i] != board[i - 1])
			break;
		if (i == 2)
		{
			if (board[i] == "X")
				return X;
			else if (board[i] == "O")
				return O;
		}
	}

	for (int i = 4; i < 6; ++i)
	{
		if (board[i] != board[i - 1])
			break;
		if (i == 5)
		{
			if (board[i] == "X")
				return X;
			else if (board[i] == "O")
				return O;
		}
	}

	for (int i = 7; i < 9; ++i)
	{
		if (board[i] != board[i - 1])
			break;
		if (i == 8)
		{
			if (board[i] == "X")
				return X;
			else if (board[i] == "O")
				return O;
		}
	}

	for (int i = 3; i < 7; i+=3)
	{
		if (board[i] != board[i - 3])
			break;
		if (i == 6)
		{
			if (board[i] == "X")
				return X;
			else if (board[i] == "O")
				return O;
		}
	}

	for (int i = 4; i < 8; i += 3)
	{
		if (board[i] != board[i - 3])
			break;
		if (i == 7)
		{
			if (board[i] == "X")
				return X;
			else if (board[i] == "O")
				return O;
		}
	}

	for (int i = 5; i < 9; i += 3)
	{
		if (board[i] != board[i - 3])
			break;
		if (i == 8)
		{
			if (board[i] == "X")
				return X;
			else if (board[i] == "O")
				return O;
		}
	}

	if (board[0] == board[4] && board[0] == board[8])
	{
		if (board[0] == "X")
			return X;
		else if (board[0] == "O")
			return O;
	}

	if (board[6] == board[4] && board[6] == board[2])
	{
		if (board[6] == "X")
			return X;
		else if (board[6] == "O")
			return O;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (board[i] != "X" && board[i] != "O")
			break;
		if (i == 8)
			return DRAW;
	}
	return UNKNOWN;
}

//Minimax data structure
AI_move TTT::ai_move(string m_turn)
{
	//If the ai won this recursion
	//then return a score of 10 
	//specifically for this move.

	if (status() == O)
	{
		if (m_turn == "O")
			return AI_move(10);
		else if (m_turn == "X")
			return AI_move(-10);
	}
	else if (status() == X)
	{
		if (m_turn == "O")
			return AI_move(-10);
		else if (m_turn == "X")
			return AI_move(10);
	}
		
	else if (status() == DRAW)
		return AI_move(0);

	//Get all the moves and store them in
	//moves along with their score.
	vector<AI_move> moves;

	for (int i = 0; i < 9; ++i)
	{
		string prev_val = board[i];
		if (board[i] != "X" && board[i] != "O")
		{
			AI_move move;
			move.pos = i;
			make_move(i);                       //make_move already contains a switch_turn function
			move.score = ai_move(m_turn).score;
			board[i] = prev_val;                //Undo move
			switch_turn();						//Switch the turn back.
			moves.push_back(move);
		}
	}

	//If it is currently the ai's turn 
	//then you have to pick the largest score.
	if (turn == m_turn)
	{
		int g_score = -10000000;
		int result = 0;

		for (int i = 0; i < moves.size(); ++i)
		{
			if (moves[i].score > g_score)
			{
				g_score = moves[i].score;
				result = i;
			}
		}
		return moves[result];
	}

	//Else pick the smallest
	//hence minimax.
	else
	{
		int l_score = 100000000;
		int result = 0;
		for (int i = 0; i < moves.size(); ++i)
		{
			if (moves[i].score < l_score)
			{
				l_score = moves[i].score;
				result = i;
			}
		}
		return moves[result];
	}
}

//The state of a tile in a board.
string TTT::state(int i)
{
	if (i<9)
		return board[i];
	return "Unknown";
}

int main()
{
	//Initialize ai turn to be anything other than
	//"X" or "O".
	string ai_turn = "NONE";
	string choice;
	cout << "Multi or No (y/n)?";
	cin >> choice;

	//If not multi assign start values
	if (choice == "n")
	{
		cout << "x or o: ";
		cin >> choice;
		if (choice == "x")
			ai_turn = "O";
		else
			ai_turn = "X";
	}

	TTT my_board;
	int move = 0;

	//while game continues
	while (my_board.status() == UNKNOWN)
	{
		my_board.display();
		cout << "\nTurn: " << my_board.get_turn() << endl;
		
		//If it is ai's turn.
		//If multi will never run
		//because get_turn() is either "X" or "O".
		if (my_board.get_turn() == ai_turn)
		{
			my_board.make_move(my_board.ai_move(ai_turn).pos);
			cout << endl;
			continue;
		}

		do
		{
			cout << "\n>> ";
			cin >> move;
		} while (my_board.state(move) == "X" || my_board.state(move) == "O" || move >= 9);
		
		my_board.make_move(move);
		cout << endl;
		system("cls");
	}

	if (my_board.status() == X)
		cout << "X Won!" << endl;
	else if (my_board.status() == O)
		cout << "O Won!" << endl;
	else
		cout << "Draw" << endl;
	cin.get();
	cin.get();
	return 0;
}