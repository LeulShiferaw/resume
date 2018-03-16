#include "main_game.h"

main_game::main_game()
{
	board[0][0] = W_ROOK;
	board[0][1] = W_KNIGHT;
	board[0][2] = W_BISHOP;
	board[0][3] = W_QUEEN;
	board[0][4] = W_KING;
	board[0][5] = W_BISHOP;
	board[0][6] = W_KNIGHT;
	board[0][7] = W_ROOK;

	for (int i = 0; i < 8; ++i)
		board[1][i] = W_PAWN;
	for (int j = 2; j < 6; ++j)
	{
		for (int i = 0; i < 8; ++i)
		{
			board[j][i] = tile(j, i);
		}
	}
	for (int i = 0; i < 8; ++i)
		board[6][i] = B_PAWN;
    board[7][0] = B_ROOK;
	board[7][1] = B_KNIGHT;
	board[7][2] = B_BISHOP;
	board[7][3] = B_QUEEN;
	board[7][4] = B_KING;
	board[7][5] = B_BISHOP;
	board[7][6] = B_KNIGHT;
	board[7][7] = B_ROOK;
	board[2][1] = B_ROOK;
}

void main_game::display()
{
	for (int i = 7; i >= 0; --i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

string main_game::tile(int x, int y)
{
	//For every even digited row
	//the black ones are the even digited
	//files.
	if (x % 2 == 0)
	{
		if (y % 2 == 0)
			return B_BLANK;
		else
			return W_BLANK;
	}
	else
	{
		if (y % 2 == 0)
			return W_BLANK;
		else
			return B_BLANK;
	}
}

bool main_game::is_occupied(int x, int y)
{
    if(board[x][y]==B_BLANK || board[x][y]==W_BLANK)
        return false;
    return true;
}

vector<_move> main_game::generate_moves(int x, int y)
{
    vector<_move> moves;
    if(board[x][y]==W_PAWN)
    {
        if(y<7)
        {
            if(piece_type(x+1, y+1)==BLACK)
                moves.push_back(_move(x+1, y+1));
        }
        if(y>0)
        {
            if(piece_type(x+1, y-1)==BLACK)
                moves.push_back(_move(x+1, y-1));
        }
        if(x!=7)
        {
            if(!is_occupied(x+1, y))
            {
                moves.push_back(_move(x+1, y));
                 if(x==1)
                {
                    if(!is_occupied(x+2, y))
                        moves.push_back(_move(x+2, y));
                }
            }

        }
    }
    return moves;
}

string main_game::piece_type(int x, int y)
{
    if(is_occupied(x, y))
    {
        if(board[x][y] >= "A" && board[x][y] <= "Z")
            return WHITE;
        else
            return BLACK;
    }
    return NONE;
}


