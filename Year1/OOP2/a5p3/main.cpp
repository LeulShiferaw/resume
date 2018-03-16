/*
 * JTSK-320143
 * a5_p3.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <iostream>

using namespace std;

//Motor class
class Motor
{
	public:
		Motor();
};

Motor::Motor() 
{
	throw "This motor has problems\n";
}

//Car class
class Car
{
	private:
		Motor my_mot;
	public:
		Car();
		~Car();
};

Car::Car() : my_mot(){}
Car::~Car(){}

//Garage class
class Garage
{
	private:
		Car my_car;
	public:
		Garage();
		~Garage();
};

Garage::Garage()
try : my_car()
{
	
}
catch(...)
{
	throw "The car in this garage has problems with the motor";
}
Garage::~Garage(){}

int main()
{
	try
	{
		Garage my_gar;
	}
	catch(char const* msg)
	{
		cout << msg << endl;
	}
	return 0;
}
