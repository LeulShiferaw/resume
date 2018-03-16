#include "main_game.h"

int main()
{
    main_game my_game;

    my_game.display();
    vector<_move> vec = my_game.generate_moves(1, 1);
    for (int i = 0; i<vec.size(); ++i)
        cout << vec[i].x << " " << vec[i].y << endl;
}
