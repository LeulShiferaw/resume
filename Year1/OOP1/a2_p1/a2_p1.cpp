/*
	CH08-320142
	a2_p1.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>

using namespace std;

#define DISPLAY(arr, n) for(int i = 0; i<n; ++i){cout << arr[i] << " ";} cout << endl;

int myfirst(int arr[], const int &n)
{
	for(int i = 0; i<n; ++i)
		if(arr[i] > 0 && arr[i]%2==0)
			return arr[i];
	return -1;
}

double myfirst(double arr[], const int &n)
{
	for(int i = 0; i<n; ++i)
		if((int)arr[i]==arr[i] && arr[i]<0)
			return arr[i];
	return -1.1;
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

char myfirst(char arr[], const int &n)
{
	for(int i = 0; i<n; ++i)
		if(!is_vowel(arr[i]))
			return arr[i];
	return '0';
}


int main()
{
	int i_arr[] = {1, 3, 7, 5};
	char c_arr[] = {'a', 'e', 'o', 'c'};
	double d_arr[] = {-1.1, 2.3, 4.2, 5};
	
	DISPLAY(i_arr, 4);
	cout << "First Int: " << myfirst(i_arr, 4) << endl << endl;

	DISPLAY(c_arr, 4);
	cout << "First char: " << myfirst(c_arr, 4) << endl << endl;

	DISPLAY(d_arr, 4);
	cout << "First double: " << myfirst(d_arr, 4) << endl;
	return 0;
}