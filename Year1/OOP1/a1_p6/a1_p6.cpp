/*
	CH08-320142
	a1_p6.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rand_range(const int &l, const int &h)
{
	return rand()%(h-l+1) + l;
}

int main()
{
	srand(time(0));

	int guess, rand_num = rand_range(1, 100);
	while(true)
	{
		cout << "Enter guess: ";
		cin >> guess;	

		if(guess == rand_num)
		{
			cout << "You are Correct!!!!" << endl;
			break;
		}else if(guess < rand_num) cout << "Too low" << endl;
		else cout << "Too high" << endl;
	}

	return 0;
}