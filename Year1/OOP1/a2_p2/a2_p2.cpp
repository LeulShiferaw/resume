/*
	CH08-320142
	a2_p2.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap(float &x, float &y)
{
	float temp = x;
	x = y;
	y = temp;
}

void swap(const char* &str1, const char* &str2)
{
	const char* temp = str1;
	cout << "Temp: " << temp;
	cin.get();
	str1 = str2;
	
	cout << "I_str1: " << str1;
	cin.get();
	str2 = temp;
	cout << "I_str2: " << str2;
	cin.get();

}

int main()
{
	int a = 7, b = 15;
	float x = 3.5, y = 9.2;
	const char *str1 = "One";
	const char *str2 = "Two";

	cout << "a = " << a << ", b = " << b << endl;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

	swap(a, b);
	swap(x, y);
	swap(str1, str2);

	cout << "a = " << a << ", b = " << b << endl;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

	return 0;
}