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

	for (int i = 0; i < 8; ++i)
	{
		b_enpassant[i] = false;
		w_enpassant[i] = false;
	}
		
}

void main_game::display()
{
	cout << "   ---------------" << endl;
	for (int i = 7; i >= 0; --i)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < 8; ++j)
		{
			cout << board[i][j];

			if (j == 7)
				break;
			cout << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "   ---------------" << endl;
	cout << "   " << "A B C D E F G H" << endl;
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
	if (board[x][y] == B_BLANK || board[x][y] == W_BLANK)
		return false;
	return true;
}

vector<_move> main_game::generate_moves(int x, int y)
{
	vector<_move> moves;

	//PAWN MOVEMENT
	if (board[x][y] == W_PAWN)
	{
		//EN-PASSANT
		if (x==4)
		{
			if (y < 7)
			{
				if (b_enpassant[y + 1])
				{
					//Add eating enpassantly
					moves.push_back(_move(x + 1, y + 1));
				}
			}
			if (y>0)
			{
				if (b_enpassant[y - 1])
				{
					//Add eating enpassantly
					moves.push_back(_move(x + 1, y - 1));
				}
			}
		}

		//EXCLUDING THE LAST PAWN IN A ROW
		//ALL OTHERS CAN EAT A PIECE DIAGONALLY TO THE RIGHT.
		if (y<7)
		{
			if (piece_type(x + 1, y + 1) == BLACK)
				moves.push_back(_move(x + 1, y + 1));
		}
		//EXCLUDING THE FIRST PAWN IN A ROW
		//ALL OTHERS CAN EAT A PIECE DIAGONALLY TO THE LEFT.
		if (y>0)
		{
			if (piece_type(x + 1, y - 1) == BLACK)
				moves.push_back(_move(x + 1, y - 1));
		}
		//EXCLUDING THE LAST PAWN IN A FILE
		//ALL OTHERS CAN MOVE FORWARD.
		if (x != 7)
		{
			if (!is_occupied(x + 1, y))
			{
				moves.push_back(_move(x + 1, y));
				//IF THE PAWN HAS NOT MOVED YET
				//IT CAN LEAP FORWARD TWO TILES
				if (x == 1)
				{
					if (!is_occupied(x + 2, y))
						moves.push_back(_move(x + 2, y));
				}
			}

		}
	}

	else if (board[x][y] == B_PAWN)
	{
		//EN-PASSANT
		if (x == 3)
		{
			if (y < 7)
			{
				if (w_enpassant[y + 1])
				{
					//Add eating enpassantly
					moves.push_back(_move(x - 1, y + 1));
				}
			}
			if (y>0)
			{
				if (w_enpassant[y - 1])
				{
					//Add eating enpassantly
					moves.push_back(_move(x - 1, y - 1));
				}
			}
		}
		//EXCLUDING THE LAST PAWN IN A ROW
		//ALL OTHERS CAN EAT A PIECE DIAGONALLY TO THE RIGHT.
		if (y<7)
		{
			if (piece_type(x - 1, y + 1) == WHITE)
				moves.push_back(_move(x - 1, y + 1));
		}
		//EXCLUDING THE FIRST PAWN IN A ROW
		//ALL OTHERS CAN EAT A PIECE DIAGONALLY TO THE LEFT.
		if (y>0)
		{
			if (piece_type(x - 1, y - 1) == WHITE)
				moves.push_back(_move(x - 1, y - 1));
		}
		//EXCLUDING THE LAST PAWN IN A FILE
		//ALL OTHERS CAN MOVE FORWARD.
		if (x != 0)
		{
			if (!is_occupied(x - 1, y))
			{
				moves.push_back(_move(x - 1, y));
				//IF THE PAWN HAS NOT MOVED YET
				//IT CAN LEAP FORWARD TWO TILES
				if (x == 6)
				{
					if (!is_occupied(x - 2, y))
						moves.push_back(_move(x - 2, y));
				}
			}

		}
	}

	//ROOK MOVEMENT
	//AND QUEEN MOVEMENT
	else if (board[x][y] == W_ROOK || board[x][y] == W_QUEEN)
	{
		//UP
		//While it is not occupied 
		//add to moves, but
		//if we find a black piece 
		//then add that move and stop
		//else
		//stop immediately(when we find a white piece
		for (int i = x+1; i < 8; ++i)
		{
			if (!is_occupied(i, y))
				moves.push_back(_move(i, y));
			else if (piece_type(i, y) == BLACK)
			{
				moves.push_back(_move(i, y));
				break;
			}
			else
				break;
		}

		//DOWN
		for (int i = x - 1; i >= 0; --i)
		{
			if (!is_occupied(i, y))
				moves.push_back(_move(i, y));
			else if (piece_type(i, y) == BLACK)
			{
				moves.push_back(_move(i, y));
				break;
			}
			else
				break;
		}

		//LEFT
		for (int i = y - 1; i >= 0; --i)
		{
			if (!is_occupied(x, i))
				moves.push_back(_move(x, i));
			else if (piece_type(x, i) == BLACK)
			{
				moves.push_back(_move(x, i));
				break;
			}
			else
				break;
		}

		//RIGHT
		for (int i = y + 1; i < 8; ++i)
		{
			if (!is_occupied(x, i))
				moves.push_back(_move(x, i));
			else if (piece_type(x, i) == BLACK)
			{
				moves.push_back(_move(x, i));
				break;
			}
			else
				break;
		}
	}

	else if (board[x][y] == B_ROOK || board[x][y] == B_QUEEN)
	{
		//UP
		for (int i = x + 1; i < 8; ++i)
		{
			if (!is_occupied(i, y))
				moves.push_back(_move(i, y));
			else if (piece_type(i, y) == WHITE)
			{
				moves.push_back(_move(i, y));
				break;
			}
			else
				break;
		}

		//DOWN
		for (int i = x - 1; i >= 0; --i)
		{
			if (!is_occupied(i, y))
				moves.push_back(_move(i, y));
			else if (piece_type(i, y) == WHITE)
			{
				moves.push_back(_move(i, y));
				break;
			}
			else
				break;
		}

		//LEFT
		for (int i = y - 1; i >= 0; --i)
		{
			if (!is_occupied(x, i))
				moves.push_back(_move(x, i));
			else if (piece_type(x, i) == WHITE)
			{
				moves.push_back(_move(x, i));
				break;
			}
			else
				break;
		}

		//RIGHT
		for (int i = y + 1; i < 8; ++i)
		{
			if (!is_occupied(x, i))
				moves.push_back(_move(x, i));
			else if (piece_type(x, i) == WHITE)
			{
				moves.push_back(_move(x, i));
				break;
			}
			else
				break;
		}
	}

	//BISHOP MOVEMENT
	//AND QUEEN MOVEMENT
	if (board[x][y] == W_BISHOP || board[x][y] == W_QUEEN)
	{
		//UP RIGHT
		for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == BLACK)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}

		//UP LEFT
		for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == BLACK)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}

		//DOWN RIGHT
		for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == BLACK)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}

		//DOWN LEFT
		for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == BLACK)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}
	}

	else if (board[x][y] == B_BISHOP || board[x][y] == B_QUEEN)
	{
		//UP RIGHT
		for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == WHITE)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}

		//UP LEFT
		for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == WHITE)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}

		//DOWN RIGHT
		for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == WHITE)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}

		//DOWN LEFT
		for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
		{
			if (!is_occupied(i, j))
				moves.push_back(_move(i, j));
			else if (piece_type(i, j) == WHITE)
			{
				moves.push_back(_move(i, j));
				break;
			}
			else
				break;
		}
	}

	//KNIGHT MOVEMENT
	else if (board[x][y] == W_KNIGHT)
	{
		if (x + 2 < 8)
		{
			if (y - 1 >= 0)
			{
				if (!is_occupied(x+2, y-1) || piece_type(x+2, y-1)==BLACK)
					moves.push_back(_move(x + 2, y - 1));
			}
				
			if (y + 1 < 8)
			{
				if (!is_occupied(x + 2, y + 1) || piece_type(x + 2, y + 1) == BLACK)
					moves.push_back(_move(x + 2, y + 1));
			}
		}

		if (x - 2 >= 0)
		{
			if (y - 1 >= 0)
			{
				if (!is_occupied(x - 2, y - 1) || piece_type(x - 2, y - 1) == BLACK)
					moves.push_back(_move(x - 2, y - 1));
			}
			if (y + 1 < 8)
			{
				if (!is_occupied(x - 2, y + 1) || piece_type(x - 2, y + 1) == BLACK)
					moves.push_back(_move(x - 2, y + 1));
			}
		}

		if (y + 2 < 8)
		{
			if (x - 1 >= 0)
			{
				if (!is_occupied(x - 1, y + 2) || piece_type(x - 1, y + 2) == BLACK)
					moves.push_back(_move(x - 1, y + 2));
			}
			if (x + 1 < 8)
			{
				if (!is_occupied(x + 1, y + 2) || piece_type(x + 1, y + 2) == BLACK)
					moves.push_back(_move(x + 1, y + 2));
			}
		}

		if (y - 2 >= 0)
		{
			if (x - 1 >= 0)
			{
				if (!is_occupied(x - 1, y - 2) || piece_type(x - 1, y - 2) == BLACK)
					moves.push_back(_move(x - 1, y - 2));
			}
			if (x + 1 < 8)
			{
				if (!is_occupied(x + 1, y - 2) || piece_type(x + 1, y - 2) == BLACK)
					moves.push_back(_move(x + 1, y - 2));
			}
		}
	}

	else if (board[x][y] == B_KNIGHT)
	{
		if (x + 2 < 8)
		{
			if (y - 1 >= 0)
			{
				if (!is_occupied(x + 2, y - 1) || piece_type(x + 2, y - 1) == WHITE)
					moves.push_back(_move(x + 2, y - 1));
			}

			if (y + 1 < 8)
			{
				if (!is_occupied(x + 2, y + 1) || piece_type(x + 2, y + 1) == WHITE)
					moves.push_back(_move(x + 2, y + 1));
			}
		}

		if (x - 2 >= 0)
		{
			if (y - 1 >= 0)
			{
				if (!is_occupied(x - 2, y - 1) || piece_type(x - 2, y - 1) == WHITE)
					moves.push_back(_move(x - 2, y - 1));
			}
			if (y + 1 < 8)
			{
				if (!is_occupied(x - 2, y + 1) || piece_type(x - 2, y + 1) == WHITE)
					moves.push_back(_move(x - 2, y + 1));
			}
		}

		if (y + 2 < 8)
		{
			if (x - 1 >= 0)
			{
				if (!is_occupied(x - 1, y + 2) || piece_type(x - 1, y + 2) == WHITE)
					moves.push_back(_move(x - 1, y + 2));
			}
			if (x + 1 < 8)
			{
				if (!is_occupied(x + 1, y + 2) || piece_type(x + 1, y + 2) == WHITE)
					moves.push_back(_move(x + 1, y + 2));
			}
		}

		if (y - 2 >= 0)
		{
			if (x - 1 >= 0)
			{
				if (!is_occupied(x - 1, y - 2) || piece_type(x - 1, y - 2) == WHITE)
					moves.push_back(_move(x - 1, y - 2));
			}
			if (x + 1 < 8)
			{
				if (!is_occupied(x + 1, y - 2) || piece_type(x + 1, y - 2) == WHITE)
					moves.push_back(_move(x + 1, y - 2));
			}
		}
	}

	//KING MOVEMENT
	else if (board[x][y] == W_KING)
	{
		//UP
		if (x + 1 < 8)
		{
			if (!is_occupied(x + 1, y) || piece_type(x + 1, y) == BLACK)
				moves.push_back(_move(x + 1, y));
			//UP RIGHT
			if (y + 1 < 8)
			{
				if (!is_occupied(x + 1, y + 1) || piece_type(x + 1, y + 1) == BLACK)
					moves.push_back(_move(x + 1, y + 1));
			}

			//UP LEFT
			if (y - 1 >= 0)
			{
				if (!is_occupied(x + 1, y - 1) || piece_type(x + 1, y - 1) == BLACK)
					moves.push_back(_move(x + 1, y - 1));
			}
		}

		//DOWN
		if (x - 1 >= 0)
		{
			if (!is_occupied(x - 1, y) || piece_type(x - 1, y) == BLACK)
				moves.push_back(_move(x - 1, y));
			//DOWN LEFT
			if (y - 1 >= 0)
			{
				if (!is_occupied(x - 1, y - 1) || piece_type(x - 1, y - 1) == BLACK)
					moves.push_back(_move(x - 1, y - 1));
			}

			//DOWN RIGHT
			if (y + 1 < 8)
			{
				if (!is_occupied(x - 1, y + 1) || piece_type(x - 1, y + 1) == BLACK)
					moves.push_back(_move(x - 1, y + 1));
			}
		}

		//LEFT
		if (y - 1 >= 0)
		{
			if (!is_occupied(x, y - 1) || piece_type(x, y - 1) == BLACK)
				moves.push_back(_move(x, y - 1));
		}

		//RIGHT
		if (y + 1 < 8)
		{
			if (!is_occupied(x, y + 1) || piece_type(x, y + 1) == BLACK)
				moves.push_back(_move(x, y + 1));
		}

		//CASTLING
		if (!white_check)
		{
			//KING SIDE
			if ((!is_occupied(0, 6)) && (!is_occupied(0, 5)))
			{
				bool k_castle = true;
				if ((!w_k_moved) && (!k_w_rook_moved))
				{
					for (int i = 0; i < 8; ++i)
					{
						for (int j = 0; j < 8; ++j)
						{
							if (piece_type(i, j) == BLACK)
							{
								vector<_move> m = generate_moves(i, j);
								for (int k = 0; k < m.size(); ++k)
								{
									if (m[k].x == 0 && m[k].y == 6)
									{
										k_castle = false;
										break;
									}
									else if (m[k].x == 0 && m[k].y == 5)
									{
										k_castle = false;
										break;
									}
								}
							}
						}
					}
					if (k_castle)
					{
						moves.push_back(_move(0, 6));
					}
				}
			}
			//QUEEN SIDE
			if ((!is_occupied(0, 3)) && (!is_occupied(0, 2)))
			{
				bool q_castle = true;
				if ((!w_k_moved) && (!k_w_rook_moved))
				{
					for (int i = 0; i < 8; ++i)
					{
						for (int j = 0; j < 8; ++j)
						{
							if (piece_type(i, j) == BLACK)
							{
								vector<_move> m = generate_moves(i, j);
								for (int k = 0; k < m.size(); ++k)
								{
									if (m[k].x == 0 && m[k].y == 3)
									{
										q_castle = false;
										break;
									}
									else if (m[k].x == 0 && m[k].y == 2)
									{
										q_castle = false;
										break;
									}
								}
							}
						}
					}
					if (q_castle)
					{
						moves.push_back(_move(0, 2));
					}
				}
			}
		}
	}
	else if (board[x][y] == B_KING)
	{
		//UP
		if (x + 1 < 8)
		{
			if (!is_occupied(x + 1, y) || piece_type(x + 1, y) == WHITE)
				moves.push_back(_move(x + 1, y));
			//UP RIGHT
			if (y + 1 < 8)
			{
				if (!is_occupied(x + 1, y + 1) || piece_type(x + 1, y + 1) == WHITE)
					moves.push_back(_move(x + 1, y + 1));
			}

			//UP LEFT
			if (y - 1 >= 0)
			{
				if (!is_occupied(x + 1, y - 1) || piece_type(x + 1, y - 1) == WHITE)
					moves.push_back(_move(x + 1, y - 1));
			}
		}

		//DOWN
		if (x - 1 >= 0)
		{
			if (!is_occupied(x - 1, y) || piece_type(x - 1, y) == WHITE)
				moves.push_back(_move(x - 1, y));
			//DOWN LEFT
			if (y - 1 >= 0)
			{
				if (!is_occupied(x - 1, y - 1) || piece_type(x - 1, y - 1) == WHITE)
					moves.push_back(_move(x - 1, y - 1));
			}

			//DOWN RIGHT
			if (y + 1 < 8)
			{
				if (!is_occupied(x - 1, y + 1) || piece_type(x - 1, y + 1) == WHITE)
					moves.push_back(_move(x - 1, y + 1));
			}
		}

		//LEFT
		if (y - 1 >= 0)
		{
			if (!is_occupied(x, y - 1) || piece_type(x, y - 1) == WHITE)
				moves.push_back(_move(x, y - 1));
		}

		//RIGHT
		if (y + 1 < 8)
		{
			if (!is_occupied(x, y + 1) || piece_type(x, y + 1) == WHITE)
				moves.push_back(_move(x, y + 1));
		}

		//CASTLING
		if (!black_check)
		{
			//KING SIDE
			if ((!is_occupied(7, 6)) && (!is_occupied(7, 5)))
			{
				bool k_castle = true;
				if ((!b_k_moved) && (!k_b_rook_moved))
				{
					for (int i = 0; i < 8; ++i)
					{
						for (int j = 0; j < 8; ++j)
						{
							if (piece_type(i, j) == WHITE)
							{
								vector<_move> m = generate_moves(i, j);
								for (int k = 0; k < m.size(); ++k)
								{
									if (m[k].x == 7 && m[k].y == 6)
									{
										k_castle = false;
										break;
									}
									else if (m[k].x == 7 && m[k].y == 5)
									{
										k_castle = false;
										break;
									}
								}
							}
						}
					}
					if (k_castle)
					{
						moves.push_back(_move(7, 6));
					}
				}
			}
			//QUEEN SIDE
			if ((!is_occupied(7, 3)) && (!is_occupied(7, 2)))
			{
				bool q_castle = true;
				if ((!b_k_moved) && (!k_b_rook_moved))
				{
					for (int i = 0; i < 8; ++i)
					{
						for (int j = 0; j < 8; ++j)
						{
							if (piece_type(i, j) == WHITE)
							{
								vector<_move> m = generate_moves(i, j);
								for (int k = 0; k < m.size(); ++k)
								{
									if (m[k].x == 7 && m[k].y == 3)
									{
										q_castle = false;
										break;
									}
									else if (m[k].x == 7 && m[k].y == 2)
									{
										q_castle = false;
										break;
									}
								}
							}
						}
					}
					if (q_castle)
					{
						moves.push_back(_move(7, 2));
					}
				}
			}
		}
	}
	return moves;
}

string main_game::piece_type(int x, int y)
{
	if (is_occupied(x, y))
	{
		if (board[x][y] >= "A" && board[x][y] <= "Z")
			return WHITE;
		else
			return BLACK;
	}
	return NONE;
}

void main_game::execute_move(int x1, int y1, int x2, int y2)
{
	vector<_move> m = generate_moves(x1, y1);

	string x2y2 = board[x2][y2]; //Used  to undo move

	int tx1 = x1, ty1 = y1;      //Used to change the status of king and rook mov't. Useful for castling.

	//Used to change or leave the curr enpassant status
	bool reset_enpassant = true;

	//If white is in check
	//Then only allow moves that take it out of check
	if (white_check)
	{
		for (int i = 0; i < m.size(); ++i)
		{
			if (m[i].x == x2 && m[i].y == y2)
			{
				board[x2][y2] = board[x1][y1];
				board[x1][y1] = tile(x1, y1);
				if (is_w_check())
				{
					//Undo move and end
					board[x1][y1] = board[x2][y2];
					board[x2][y2] = x2y2;
					break;
				}
				switch_turn();
				white_check = false;
				//BLOCK CASTLING ACCORDINGLY
				if (board[x2][y2] == W_KING)
					w_k_moved = true;
				else if (tx1 == 0 && ty1 == 0)
					q_w_rook_moved = true;
				else if (tx1 == 0 && ty1 == 7)
					k_w_rook_moved = true; 

				//After every move take the chance of an enpassant away
				if (reset_enpassant)
				{
					for (int i = 0; i < 8; ++i)
					{
						b_enpassant[i] = false;
						w_enpassant[i] = false;
					}
				}
				break;
			}
		}
	}
	//The same with black
	else if (black_check)
	{
		for (int i = 0; i < m.size(); ++i)
		{
			if (m[i].x == x2 && m[i].y == y2)
			{
				board[x2][y2] = board[x1][y1];
				board[x1][y1] = tile(x1, y1);
				if (is_b_check())
				{
					//Undo move and end
					board[x1][y1] = board[x2][y2];
					board[x2][y2] = x2y2;
					break;
				}
				switch_turn();
				black_check = false;
				//BLOCK CASTLING ACCORDINGLY
				if (board[x2][y2] == B_KING)
					b_k_moved = true;
				else if (tx1 == 7 && ty1 == 0)
					q_b_rook_moved = true;
				else if (tx1 == 7 && ty1 == 7)
					k_b_rook_moved = true;
		 
				//After every move take the chance of an enpassant away
				if (reset_enpassant)
				{
					for (int i = 0; i < 8; ++i)
					{
						b_enpassant[i] = false;
						w_enpassant[i] = false;
					}
				}
				break;
			}
		}
	}
	else
	{
		//WHITE KING CASTLING
		if (board[x1][y1] == W_KING && x2 == 0 && y2 == 6)
		{
			//KING SIDE
			if (x2 == 0 && y2 == 6)
			{
				for (int i = 0; i < m.size(); ++i)
				{
					if (m[i].x == x2 && m[i].y == y2)
					{
						board[x2][y2] = board[x1][y1];
						board[x1][y1] = tile(x1, y1);

						board[0][5] = board[0][7];
						board[0][7] = tile(0, 7);
						//After every move take the chance of an enpassant away
						if (reset_enpassant)
						{
							for (int i = 0; i < 8; ++i)
							{
								b_enpassant[i] = false;
								w_enpassant[i] = false;
							}
						}
						break;
					}
				}
			}
			//QUEEN SIDE
			else if (x2 == 0 && y2 == 2)
			{
				for (int i = 0; i < m.size(); ++i)
				{
					if (m[i].x == x2 && m[i].y == y2)
					{
						board[x2][y2] = board[x1][y1];
						board[x1][y1] = tile(x1, y1);

						board[0][3] = board[0][0];
						board[0][0] = tile(0, 0);
						//After every move take the chance of an enpassant away
						if (reset_enpassant)
						{
							for (int i = 0; i < 8; ++i)
							{
								b_enpassant[i] = false;
								w_enpassant[i] = false;
							}
						}
						break;
					}
				}
			}
		}
		//BLACK KING CASTLING
		else if (board[x1][y1] == B_KING && x2 == 7 && y2 == 6)
		{
			//KING SIDE
			if (x2 ==7 && y2 == 6)
			{
				for (int i = 0; i < m.size(); ++i)
				{
					if (m[i].x == x2 && m[i].y == y2)
					{
						board[x2][y2] = board[x1][y1];
						board[x1][y1] = tile(x1, y1);

						board[7][5] = board[7][7];
						board[7][7] = tile(7, 7);
						//After every move take the chance of an enpassant away
						if (reset_enpassant)
						{
							for (int i = 0; i < 8; ++i)
							{
								b_enpassant[i] = false;
								w_enpassant[i] = false;
							}
						}
						break;
					}
				}
			}
			//QUEEN SIDE
			else if (x2 == 7 && y2 == 2)
			{
				for (int i = 0; i < m.size(); ++i)
				{
					if (m[i].x == x2 && m[i].y == y2)
					{
						board[x2][y2] = board[x1][y1];
						board[x1][y1] = tile(x1, y1);

						board[7][3] = board[7][0];
						board[7][0] = tile(7, 0);
						//After every move take the chance of an enpassant away
						if (reset_enpassant)
						{
							for (int i = 0; i < 8; ++i)
							{
								b_enpassant[i] = false;
								w_enpassant[i] = false;
							}
						}
						break;
					}
				}
			}
		}


		//White Promotion
		else if (board[x1][y1] == W_PAWN && x2 == 7)
		{
			for (int i = 0; i < m.size(); ++i)
			{
				if (m[i].x == x2 && m[i].y == y2)
				{
					board[x2][y2] = board[x1][y1];
					board[x1][y1] = tile(x1, y1);

					if (piece_type(x2, y2) == WHITE)
					{
						if (is_w_check())
						{
							//Undo move and end
							board[x1][y1] = board[x2][y2];
							board[x2][y2] = x2y2;
							break;
						}
					}

					//Promote to a new piece
					int choice = -1;
					do
					{
						cout << "Which piece would you like to upgrade to?" << endl;
						cout << "1. QUEEN\n2. BISHOP\n3. KNIGHT\n4. ROOK\n";
						cin >> choice;
					} while (choice < 1 && choice > 4);

					if (choice == 1)
						board[x2][y2] = W_QUEEN;
					else if (choice == 2)
						board[x2][y2] = W_BISHOP;
					else if (choice == 3)
						board[x2][y2] = W_KNIGHT;
					else if (choice == 4)
						board[x2][y2] = W_ROOK;

					switch_turn();
					//After every move take the chance of an enpassant away
					if (reset_enpassant)
					{
						for (int i = 0; i < 8; ++i)
						{
							b_enpassant[i] = false;
							w_enpassant[i] = false;
						}
					}
					break;
				}
			}
		}
		//Black Promotion
		else if (board[x1][y1] == B_PAWN && x2 == 0)
		{
			for (int i = 0; i < m.size(); ++i)
			{
				if (m[i].x == x2 && m[i].y == y2)
				{
					board[x2][y2] = board[x1][y1];
					board[x1][y1] = tile(x1, y1);

					if (piece_type(x2, y2) == BLACK)
					{
						if (is_b_check())
						{
							//Undo move and end
							board[x1][y1] = board[x2][y2];
							board[x2][y2] = x2y2;
							break;
						}
					}

					//Promote to a new piece
					int choice = -1;
					do
					{
						cout << "Which piece would you like to upgrade to?" << endl;
						cout << "1. QUEEN\n2. BISHOP\n3. KNIGHT\n4. ROOK\n";
						cin >> choice;
					} while (choice < 1 && choice > 4);

					if (choice == 1)
						board[x2][y2] = B_QUEEN;
					else if (choice == 2)
						board[x2][y2] = B_BISHOP;
					else if (choice == 3)
						board[x2][y2] = B_KNIGHT;
					else if (choice == 4)
						board[x2][y2] = B_ROOK;

					switch_turn();
					//After every move take the chance of an enpassant away
					if (reset_enpassant)
					{
						for (int i = 0; i < 8; ++i)
						{
							b_enpassant[i] = false;
							w_enpassant[i] = false;
						}
					}
					break;
				}
			}
		}
		//En-passant
		else if (board[x1][y1] == B_PAWN && x1 == 6 && x2 == 4)
		{

			for (int i = 0; i < m.size(); ++i)
			{
				if (m[i].x == x2 && m[i].y == y2)
				{
					board[x2][y2] = board[x1][y1];
					board[x1][y1] = tile(x1, y1);

					if (is_b_check())
					{
						//Undo move and end
						board[x1][y1] = board[x2][y2];
						board[x2][y2] = x2y2;
						break;
					}
					b_enpassant[y2] = true;
					reset_enpassant = false;
					switch_turn();
					break;
				}
			}
		}
		else if (board[x1][y1] == W_PAWN && x1 == 1 && x2 == 3)
		{
			for (int i = 0; i < m.size(); ++i)
			{
				if (m[i].x == x2 && m[i].y == y2)
				{
					board[x2][y2] = board[x1][y1];
					board[x1][y1] = tile(x1, y1);

					if (is_b_check())
					{
						//Undo move and end
						board[x1][y1] = board[x2][y2];
						board[x2][y2] = x2y2;
						break;
					}
					w_enpassant[y2] = true;
					reset_enpassant = false;
					switch_turn();
					break;
				}
			}
		}
		//Normal move
		else
		{
			for (int i = 0; i < m.size(); ++i)
			{
				if (m[i].x == x2 && m[i].y == y2)
				{
					//EN-PASSANT MOVE
					//Only remove the opponent's pawn 
					//the rest is done normally.
					bool w_enpassant1 = false;
					if (board[x1][y1] == W_PAWN && x2 == 5 && (y2 == y1 - 1 || y2 == y1 + 1) && (!is_occupied(x2, y2)))
					{
						w_enpassant1 = true;
						board[x1][y2] = tile(x1, y2);
					}
					
					bool b_enpassant1 = false;
					if (board[x1][y1] == B_PAWN && x2 == 2 && (y2 == y1 - 1 || y2 == y1 + 1) && (!is_occupied(x2, y2)))
					{
						b_enpassant1 = true;
						board[x1][y2] = tile(x1, y2);
					}

					board[x2][y2] = board[x1][y1];
					board[x1][y1] = tile(x1, y1);

					if (piece_type(x2, y2) == WHITE)
					{
						if (is_w_check())
						{
							//Undo move and end
							board[x1][y1] = board[x2][y2];
							board[x2][y2] = x2y2;
							if (w_enpassant1)
								board[x1][y2] = B_PAWN;
							break;
						}
					}
					else if (piece_type(x2, y2) == BLACK)
					{
						if (is_b_check())
						{
							//Undo move and end
							board[x1][y1] = board[x2][y2];
							board[x2][y2] = x2y2;
							if (b_enpassant1)
								board[x1][y2] = W_PAWN;
							break;
						}
					}
					switch_turn();

					//BLOCK CASTLING ACCORDINGLY
					if (board[x2][y2] == W_KING)
						w_k_moved = true;
					else if (tx1 == 0 && ty1 == 0)
						q_w_rook_moved = true;
					else if (tx1 == 0 && ty1 == 7)
						k_w_rook_moved = true;
					
					//BLOCK CASTLING ACCORDINGLY
					if (board[x2][y2] == B_KING)
						b_k_moved = true;
					else if (tx1 == 7 && ty1 == 0)
						q_b_rook_moved = true;
					else if (tx1 == 7 && ty1 == 7)
						k_b_rook_moved = true;

					//After every move take the chance of an enpassant away
					if (reset_enpassant)
					{
						for (int i = 0; i < 8; ++i)
						{
							b_enpassant[i] = false;
							w_enpassant[i] = false;
						}
					}
					break;
				}
			}
		}
	}

}

void main_game::switch_turn()
{
	if (turn == WHITE)
		turn = BLACK;
	else
		turn = WHITE;
}

bool main_game::is_b_check()
{
	//GOES THROUGH THE BOARD
	//WHEN YOU FIND A WHITE PIECE
	//CHECK IF ITS POSSIBLE MOVE
	//CONTAINS THE BLACK KING.
	vector<_move> m;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (piece_type(i, j) == WHITE)
			{
				m = generate_moves(i, j);
				for (int k = 0; k < m.size(); ++k)
				{
					if (board[m[k].x][m[k].y] == B_KING)
					{
						black_check = true;
						return true;
					}
						
				}
			}
		}
	}
	return false;
}

bool main_game::is_w_check()
{
	//GOES THROUGH THE BOARD
	//WHEN YOU FIND A BLACK PIECE
	//CHECK IF ITS POSSIBLE MOVE
	//CONTAINS THE WHITE KING.
	vector<_move> m;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (piece_type(i, j) == BLACK)
			{
				m = generate_moves(i, j);
				for (int k = 0; k < m.size(); ++k)
				{
					if (board[m[k].x][m[k].y] == W_KING)
					{
						white_check = true;
						return true;
					}
						
				}
			}
		}
	}
	return false;
}

bool main_game::check_mate()
{
	vector<_move> m;
	//WHEN WHITE IS IN CHECK
	//GO THROUGH THE BOARD
	//WHEN YOU FIND A WHITE PIECE, THIS INCLUDES THE WHITE KING ITSLEF,
	//CHECK IF ANY OF ITS MOVES CAN SAVE WHITE 
	//IF NONE OF THEM CAN RETURN TRUE.
	if (white_check)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (piece_type(i, j) == WHITE)
				{
					m = generate_moves(i, j);
					for (int k = 0; k < m.size(); ++k)
					{
						string kxky = board[m[k].x][m[k].y];
						board[m[k].x][m[k].y] = board[i][j];
						if (!is_w_check())
						{
							//Undo move and return false
							board[i][j] = board[m[k].x][m[k].y];
							board[m[k].x][m[k].y] = kxky;
							return false;
						}
					}
				}
			}
		}
		return true;
	}
	//SAME AS WHITE
	else if (black_check)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (piece_type(i, j) == BLACK)
				{
					m = generate_moves(i, j);
					for (int k = 0; k < m.size(); ++k)
					{
						string kxky = board[m[k].x][m[k].y];
						board[m[k].x][m[k].y] = board[i][j];
						if (!is_b_check())
						{
							//Undo move and return false
							board[i][j] = board[m[k].x][m[k].y];
							board[m[k].x][m[k].y] = kxky;
							return false;
						}
						//Undo move
						board[i][j] = board[m[k].x][m[k].y];
						board[m[k].x][m[k].y] = kxky;
					}
				}
			}
		}
		return true;
	}
	
	//If both white and black are not in check
	return false;
}

bool main_game::attacked(string enemy, int x, int y)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (piece_type(i, j) == enemy)
			{
				vector<_move> m = generate_moves(i, j);
				for (int k = 0; k < m.size(); ++k)
				{
					if (m[k].x == x && m[k].y == y)
						return true;
				}
			}
		}
	}
	return false;
}

void main_game::is_draw()
{
	if (!(white_check || black_check))
	{
		movement_check();
		if ((!white_move) || (!black_move))
			draw = true;
		else draw = false;
	}
	else
		draw = false;
}

void main_game::movement_check()
{
	white_move = false;
	black_move = false;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j<8; ++j)
		{
			vector<_move> m = generate_moves(i, j);
			if (m.size() > 0)
			{
				if (piece_type(i, j) == WHITE)
					white_move = true;
				else
					black_move = true;
			}
		}
	}
}
