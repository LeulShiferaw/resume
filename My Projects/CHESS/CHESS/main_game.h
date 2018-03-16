#ifndef MAIN_GAME_H_INCLUDED
#define MAIN_GAME_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct _move
{
	_move(int a, int b) { x = a; y = b; }
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
	string B_BLANK = " "; //The tiles are considered as pieces too

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

	//Turn
	string turn = WHITE;

	//CHECK
	//TO AVOID CALLING THE CHECK FUNCTION
	//AGAIN SINCE WE ALWAYS CALL IT IN THE MAIN
	//FUNCTION
	bool white_check = false;
	bool black_check = false;

	//FOR CASTLING
	bool q_w_rook_moved = false; //Queen white rook moved
	bool k_w_rook_moved = false; //King white rook moved
	bool w_k_moved = false;      //White king moved

	bool q_b_rook_moved = false; //Queen black rook moved
	bool k_b_rook_moved = false; //King black rook moved
	bool b_k_moved = false;      //Black king moved

	bool b_enpassant[8];         //To save the curr enpassant status
	bool w_enpassant[8];         //To save the curr enpassant status
	bool black_move = true;      //To check if black can move used int is_draw function
	bool white_move = true;      //Same as black
	bool draw = false;           //If the game is a draw used in is_draw function
public:
	main_game();
	void display();
	string tile(int x, int y);
	bool is_occupied(int x, int y);
	vector<_move> generate_moves(int x, int y);
	string piece_type(int x, int y);
	void execute_move(int x1, int y1, int x2, int y2);
	void switch_turn();
	string get_turn() { return turn; }
	bool is_w_check();
	bool is_b_check();
	bool check_mate();
	bool attacked(string enemy, int x, int y);
	void is_draw();                                    //Sets the draw var by using movement_check function.
	void movement_check();							   //Checks if white or black is stuck and sets the black_move and white_move vars accordingly.
	bool get_draw() { return draw; }                   //Used to return var draw much more efficient in the AI class instead of calling is_draw every time.
};


#endif // MAIN_GAME_H_INCLUDED
