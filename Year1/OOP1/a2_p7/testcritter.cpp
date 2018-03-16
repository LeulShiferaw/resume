#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c;

	string name;
	int hunger;
	int iq;
	int bmi;
 
	cout << endl << "Please enter data: " << endl;
	cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(cin, name);
	c.setName(name);
	c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);
	
	cout << "IQ: ";
	cin >> iq;
	cout << "BMI: ";
	cin >> bmi;
	c.setIQ(iq);
	c.setBMI(bmi);

	cout << "You have created:" << endl;
	c.print();
    return 0;
}