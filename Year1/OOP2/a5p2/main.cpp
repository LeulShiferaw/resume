/*
 * JTSK-320143
 * a5_p2.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <iostream>
#include <exception>

using namespace std;

class OwnException : public exception
{
	public:
		virtual const char* what() const throw();
};

const char* OwnException::what() const throw()
{
	return "This is a default case exception";
}

void fun(char c)
{
	switch(c)
	{
		case '1':
			throw 'e';
		case '2':
			throw 999;
		case '3':
			throw false;
		default:
			throw OwnException();
	}
}

int main()
{
	try
	{
		fun('1');
	}
	catch(const char &c)
	{
		cerr << "Exception caught in main: " << c << endl;
	}

	try
	{
		fun('2');
	}
	catch(const int &i)
	{
		cerr << "Exception caught in main: " << i << endl;
	}
	

	try
	{
		fun('3');
	}
	catch(const bool &b)
	{
		cerr << "Exception caught in main: " << b << endl;
	}
	

	try
	{
		fun('u');
	}
	catch(const OwnException &oex)
	{
		cerr << "Exception caught in main: " << oex.what() << endl;
	}

	return 0;
}

