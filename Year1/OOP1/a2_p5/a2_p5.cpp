/*
	CH08-320142
	a2_p5.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <string>
#include <iostream>

using namespace std;

#define FOR(i, j) for(i = 0; (unsigned int)i<j; ++i)

bool isPalindrome(string s)
{
	int i;
	FOR(i, s.size()/2)
		if(s[i] != s[s.size()-1-i]) 
			return false;
	return true;
}

int main()
{
	string word = "";
	
	while(true)
	{
		cout << "Enter word: ";
		cin >> word;

		if(word == "exit")
			return 0;
		else if(isPalindrome(word))
			cout << "Palindrome" << endl;
		else cout << "Not Palindrome" << endl;
	}

	return 0;
}