/*
	CH08-320142
	a5_p4.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include "TournamentMember.h"

using namespace std;

int main()
{
	Player p1("Leul", "Shiferaw", "0009-99-98", 89, 9, true, "Striker");
	Player p2("Leul", "Haile", "0569-99-98", 9, 9, false, "Striker");
	Refree r1("Zaki", "Teferra", "0000-99-28");

	//I removed all the constructor messages because they cluster up 
	//and fill the space


	//All four of the messages will show up
	//Because first I will add p1 to ycl then I will try agian
	//but fail b/c it already exists so I will add it to RCL after deleting it from YCL
	//Then I will add p2 to RCL and I will try again but fail b/c it already exsists
	if(r1.addYCL(&p1))
		cout << "Successfully added player 1 to Yellow Card List" << endl;
	if(!r1.addYCL(&p1))
		cout << "Not successful when adding player 1 to Yellow Card List" << endl;
	if(r1.addRCL(&p2))
		cout << "Successfully added player 2 to Red Card List" << endl;
	if(!r1.addRCL(&p2))
		cout << "Not successful when adding player 2 to Red Card List" << endl;
	
	//Nothig in YCL
	r1.printYCL();

	//Both are in RCL
	r1.printRCL();
	return 0;
}