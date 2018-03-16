#ifndef MAIN_GAME_H_INCLUDED
#define MAIN_GAME_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct _move
{
    _move(int a, int b) {x = a; y = b;}
    int x, y;
};

class main_game
{
private:
	string board[8][8];

	//Pieces
    string B_KING = "k";
    string B_QUEEN = "q";
    string B_BISHOP = "b";
    string B_KNIGHT = "n";
    string B_ROOK = "r";
    string B_PAWN = "p";
    string B_BLANK = " ";  //The tiles are considered as pieces too

    string W_KING = "K";
    string W_QUEEN = "Q";
    string W_BISHOP = "B";
    string W_KNIGHT = "N";
    string W_ROOK = "R";
    string W_PAWN = "P";
    string W_BLANK = "X";

    //piece type
    string BLACK = "black";
    string WHITE = "white";
    string NONE = "none";

public:
	main_game();
	void display();
	string tile(int x, int y);
	bool is_occupied(int x, int y);
	vector<_move> generate_moves(int x, int y);
	string piece_type(int x, int y);
};


#endif // MAIN_GAME_H_INCLUDED
