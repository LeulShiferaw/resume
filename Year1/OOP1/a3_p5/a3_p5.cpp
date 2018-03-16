/*
	CH08-320142
	a3_p5.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include <cstring>  // standard C string.h header file

using namespace std;

/*
	Naive string: the goal is to illustrate how copy constructors 
	should be handled. See also charbuffer.cpp
*/

class NaiveString {
private:
	char *str;
public:
	NaiveString(const char*);
	NaiveString(const NaiveString&);
	~NaiveString();
	void update(char, char);
	void print();
};

NaiveString::NaiveString(const char* t) {
	str = new char[strlen(t) + 1];
	strcpy(str, t);
	cout << "Constructor for " << str << endl;
}

NaiveString::~NaiveString()
{
	cout << "Destructor for " << str << endl;
	delete []str;
	str = NULL;
}

/* 
	Copy constructor: creates a new instance of 
	naive string starting from an existing one 
*/


NaiveString::NaiveString(const NaiveString& src) {
	str = new char[strlen(src.str) + 1];
	strcpy(str, src.str);
	cout << "Copy Constructor for " << str << endl;
	// please note that we can access src.str even if it is private
	// as we are inside the NaiveString class
}

/* replaces occurrences of oldchar by newchar */
void NaiveString::update(char oldchar, char newchar) {
	unsigned int i;
	for (i = 0; i < strlen(str); i++) 
		if (str[i] == oldchar)
			str[i] = newchar;
}

void NaiveString::print() {
	cout << str << endl;
}

void funcByVal(NaiveString s) {
	cout << "funcbyval() being called" << endl;
	s.update('B', 'C');
	s.print();
}

void funcByRef(NaiveString &s) {
	cout << "funcbyref() being called" << endl;
	s.update('B', 'C');
	s.print();
}

int main(int argc, char** argv)
{
	NaiveString a("aBcBdB"), b(a);
	a.print();
	b.print();

	funcByVal(a);
	funcByRef(b);
	
	a.print();
	b.print();
}