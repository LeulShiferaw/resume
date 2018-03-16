/*
	CH08-320142
	a2_p4.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, j) for(i = 0; (unsigned int)i < j; ++i)

//Random number in range [l, h]
int rand_range(const int &l, const int &h)
{
	return rand() % (h-l+1) + l;
}

bool is_vowel(const char &c)
{
	switch(c)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}

//Replaces every vowel with an underscore
void underscore(string &word)
{
	int i;
	FOR(i, word.size()){if(is_vowel(word[i])) word[i] = '_';}
}

int main()
{
	srand(time(0));

	int tries;
	string guess;
	string list[] = {"computer", "television", "keyboard", "laptop", "mouse"
			   	     "video", "audio", "gaming PC", "I", "don't", "know", "what",
		    		 "Oh", "wait", "maybe", "the", "end"};
	
	char play = 'y';
	string word;
	string b_word;
	while(play == 'y')
	{
		tries = 0;
		word = list[rand_range(0, 16)];
		b_word = word;
		underscore(word);
		do
		{
			cout << "Word: " << word << endl;

			cout << "Guess: ";
			cin >> guess;
			cin.get();
			++tries;

			if(guess == "quit")
				return 0;

		}while(guess != b_word);
		
		cout << "Number of tries: " << tries << endl;
		cout << "Would you like to play(y/n)?" << endl;
		cin >> play;
		cin.get();
	}

	return 0;
}