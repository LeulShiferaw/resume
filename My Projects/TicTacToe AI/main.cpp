#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int b_s = 3; //Board size
char board[b_s][b_s];

//Globals
const char blank = ' '; //Initial state of game and also a value of the function status() stating that the game is not over
const char x = 'X';		//Also represents turn
const char o = 'O';
const char draw = 'D';
string line = "";
char turn = ' ';
char player = ' ';		//Player's turn

struct s_move //Score + position
{
	s_move() {};
	s_move(const int &s, const int &posx, const int &posy) { score = s; x = posx; y = posy; }
	int score;
	int x, y;
};

char status();                             //Win, draw or none
void display();							   //Display board
void initialize();							
void switch_turn(char &t);
s_move min(const vector<s_move> &moves);  //Return move with minimum score
s_move max(const vector<s_move> &moves);  //Return move with maximum score
s_move best_move(char c_turn, int limit);			  //Calculate the best move 


int main()
{
	while (true)
	{
		initialize();

		while (turn != x && turn != o)
		{
			cout << "X or O: ";
			cin >> turn;
		}

		assert(turn == x || turn == o);

		player = turn;
		turn = x;               //X starts
		
		char result = status();
		while (result == blank) //Game is not over
		{
			display();
			if (turn == player)
			{
				int x = -1, y = -1;
				while (x >= b_s || x < 0 || y >= b_s || y < 0)
				{
					cout << "Enter x: ";
					cin >> x;
					cout << "Enter y: ";
					cin >> y;
				}

				if (board[x][y] == blank)
				{
					board[x][y] = turn;
					switch_turn(turn);
				}
				else
					cout << "\nOcuppied!\n";
			}
			else
			{
				s_move ai_move = best_move(turn, -1);

				board[ai_move.x][ai_move.y] = turn;
				switch_turn(turn);
			}
			result = status();

		}
		display();

		if (result == draw)
			cout << "It is a draw!";
		else if (result == x)
			cout << "X Won!";
		else
			cout << "O Won!";
		cout << endl << endl;
	}
}

void initialize()
{
	line = "";
	for (int i = 0; i < (2 * b_s) + 1; ++i)
		line += "-";
	for (int i = 0; i < b_s; ++i)
		for (int j = 0; j < b_s; ++j)
			board[i][j] = blank;
}

void switch_turn(char &t)
{
	if (t == x)
		t = o;
	else
		t = x;
}

s_move min(const vector<s_move> &moves)
{
	assert(moves.size() > 0);

	int ind = 0;
	int s_score = moves[0].score;

	for (int i = 1; i < moves.size(); ++i)
	{
		if (moves[i].score < s_score)
		{
			ind = i;
			s_score = moves[i].score;
		}
	}
	return moves[ind];
}

s_move max(const vector<s_move> &moves)
{
	assert(moves.size() > 0);

	int ind = 0;
	int g_score = moves[0].score;

	for (int i = 1; i < moves.size(); ++i)
	{
		if (moves[i].score > g_score)
		{
			ind = i;
			g_score = moves[i].score;
		}
	}
	return moves[ind];
}

char status()
{
	for (int i = 0; i < b_s; ++i)
	{
		for (int j = 1; j < b_s; ++j)
		{
			if (board[i][j] != board[i][0])
				break;
			else if (j == b_s - 1 && board[i][0] != blank)
				return board[i][0];
		}
	}
	
	for (int i = 1; i < b_s; ++i)
	{
		if (board[i][i] != board[0][0])
			break;
		else if (i == b_s - 1 && board[0][0] != blank)
			return board[0][0];
	}

	for (int i = 1; i < b_s; ++i)
	{
		if (board[i][b_s - 1 - i] != board[0][b_s - 1])
			break;
		else if (i == b_s - 1 && board[0][b_s - 1] != blank)
			return board[0][b_s - 1];
	}

	for (int j = 0; j < b_s; ++j)
	{
		for (int i = 1; i < b_s; ++i)
		{
			if (board[i][j] != board[0][j])
				break;
			else if (i == b_s - 1 && board[0][j] != blank)
				return board[0][j];
		}
	}

	for (int i = 0; i < b_s; ++i)
		for (int j = 0; j < b_s; ++j)
			if (board[i][j] == blank)
				return blank;

	return draw;
}

s_move best_move(char c_turn, int limit) //In chess m_left would have to represent the depth
{
	//Base case
	char result = status();
	if (result == player)
		return s_move(10, 0, 0);
	else if (result == draw)
		return s_move(0, 0, 0);
	else if (result != blank)
		return s_move(-10, 0, 0);

	vector<s_move> n_nodes;
	//For all the possible moves make them and record the best comebacks
	//Then if it is your turn, undo the move and choose the one with the highest score.
	int best_score = -1;
	for (int i = 0; i < b_s; ++i)
	{
		for (int j = 0; j < b_s; ++j)
		{
			if (board[i][j] == blank)
			{
				board[i][j] = c_turn;

				switch_turn(c_turn);
				n_nodes.push_back(s_move(best_move(c_turn, best_score).score, i, j));
				switch_turn(c_turn);

				board[i][j] = blank;

				if (limit != -1)
				{
					if (c_turn == player)
					{
						if (n_nodes.back().score >= limit)
							return n_nodes.back();
					}
					else if (n_nodes.back().score <= limit)
						return n_nodes.back();
				}

				if (best_score == -1)
					best_score = n_nodes.back().score;
				else if (c_turn == player)
				{
					if (n_nodes.back().score > best_score)
						best_score = n_nodes.back().score;
				}
				else if (n_nodes.back().score < best_score)
					best_score = n_nodes.back().score;
			}
		}
	}

	if (c_turn == player)
		return max(n_nodes);
	else
		return min(n_nodes);
}

void display()
{
	cout << line;
	cout << endl;
	for (int i = 0; i < b_s; ++i)
	{
		cout << "|";
		for (int j = 0; j < b_s; ++j)
		{
			cout << board[i][j] << "|";
		}
		cout << endl;
		cout << line;
		cout << endl;
	}
	cout << endl;
}