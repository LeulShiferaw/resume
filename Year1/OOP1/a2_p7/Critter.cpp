#include <iostream>
#include "Critter.h"

using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::setIQ(const int &x){
	iq = x;
}

void Critter::setBMI(const int &x){
	bmi = x;
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << " My IQ and BMI are " << iq << " and " << bmi << " (respectively)." << endl;
}

int Critter::getHunger() {
	return hunger;
}

int Critter::getIQ()
{
	return iq;
}

int Critter::getBMI()
{
	return bmi;
}