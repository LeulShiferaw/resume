#include "main_game.h"
#include <Windows.h>

int main()
{
	main_game my_game;
	
	//Converted values of move 
	//eg. e2e4 would be 
	//  1   4   3   4 
	int x1, y1, x2, y2;

	string move;
	while (true)
	{
		system("cls");
		my_game.display();

		cout << "Turn: " << my_game.get_turn() << endl << endl;

		//Is in check
		if (my_game.is_b_check() || my_game.is_w_check())
		{
			if (my_game.check_mate())
			{
				cout << "CHECKMATE!!!" << endl;
				return 0;
			}
			cout << "CHECK!" << endl << endl;
		}
			

		cout << ">> ";
		cin >> move;

		//MOVE ERROR CHECKING
		if (move.size() != 4)
			continue;

		if (move[0] >= 'A' && move[0] <= 'Z')
			y1 = move[0] - 'A';
		else if (move[0] >= 'a' && move[0] <= 'z')
			y1 = move[0] - 'a';
		else
			continue;
		
		if (move[1] >= '1' && move[1] <= '8')
			x1 = move[1] - '1';
		else
			continue;

		if (move[2] >= 'A' && move[2] <= 'Z')
			y2 = move[2] - 'A';
		else if (move[2] >= 'a' && move[2] <= 'z')
			y2 = move[2] - 'a';
		else
			continue;

		if (move[3] >= '1' && move[3] <= '8')
			x2 = move[3] - '1';
		else
			continue;

		//if (my_game.piece_type(x1, y1) != my_game.get_turn())
		//{
		//	cout << "Invalid!" << endl;
		//	continue;
		//}

		my_game.execute_move(x1, y1, x2, y2);
		//
		my_game.is_draw();
		if (my_game.get_draw())
		{
			cout << "DRAW" << endl;
			return 0;
		}
	}
}
