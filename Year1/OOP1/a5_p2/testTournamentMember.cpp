/*
	CH08-320142
	a5_p2.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "TournamentMember.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	TournamentMember test("Leul", "Shiferaw", "1998-10-08");
	test.print_status();

	cout << endl;
	TournamentMember test_0;
	test_0.print_status();
	
	test_0.set_f_name("Leul");
	test_0.set_l_name("Haile");
	test_0.set_d_birth("1997-08-19");
	
	cout << endl;
	test_0.print_status();
	cout << endl;
	return 0;
}