#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	//R/ship
	int **friends = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		friends[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			if (j == i) //Everyone is a friend of themselve
			{
				friends[i][j] = 1;
				continue;
			}
			friends[i][j] = -1; //Neither friends nor enemies.
		}
			
	}

	int op; //Operation 1-set friends, 2-SetEnemies, 3-areFriends, 4-areEnemies
	cin >> op;

	int x, y;
	while (op != 0)
	{
		cin >> x >> y;

		switch (op)
		{
		case 1:
			if (friends[x][y] == 0)  //If enemies
			{
				cout << "-1" << endl;
				break;
			}
			friends[x][y] = 1;
			friends[y][x] = 1;

			//Friend of a friend, enemy of a friend
			for (int i = 0; i < n; ++i)
			{
				if (friends[y][i] == 1)
				{
					friends[x][i] = 1;
					friends[i][x] = 1;
				}	
				else if (friends[y][i] == 0)
				{
					friends[i][x] = 0;
					friends[x][i] = 0;
				}
					

				if (friends[x][i] == 1)
				{
					friends[y][i] = 1;
					friends[i][y] = 1;
				}
				else if (friends[x][i] == 0)
				{
					friends[y][i] = 0;
					friends[i][y] = 0;
				}
					
			}

			break;
		case 2:
			if (friends[x][y] == 1)  //If friends
			{
				cout << "-1" << endl;
				break;
			}
			friends[x][y] = 0;
			friends[y][x] = 0;

			//Friend of an enemy, enemy of an enemy
			for (int i = 0; i < n; ++i)
			{
				if (friends[y][i] == 1)
				{
					friends[x][i] = 0;
					friends[i][x] = 0;
				}
				else if (friends[y][i] == 0)
				{
					friends[i][x] = 1;
					friends[x][i] = 1;
				}
					

				if (friends[x][i] == 1)
				{
					friends[y][i] = 0;
					friends[i][y] = 0;
				}
				else if (friends[x][i] == 0)
				{
					friends[y][i] = 1;
					friends[i][y] = 1;
				}
					
			}

			break;
		case 3:
			if (friends[x][y] == 1)
				cout << "1" << endl;
			else
				cout << "0" << endl;
			break;
		case 4:
			if (friends[x][y] == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
			break;
		default:
			break;
		}

		cin >> op;
	}

	//Destroy Array
	for (int i = 0; i < n; ++i)
		delete[]friends[i];
	delete[]friends;
}