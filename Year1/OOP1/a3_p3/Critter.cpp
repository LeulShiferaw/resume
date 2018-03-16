#include <iostream>
#include "Critter.h"

using namespace std;

Critter::Critter(std::string s): name(s), hunger(0), boredom(0), height(0.5){}
Critter::Critter(std::string s, int x, int y, int z): name(s), hunger(x), boredom(y), height(converter(z)){}

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = converter(newhunger);
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << convert_back(hunger) << "." << endl;
}

int Critter::getHunger() {
	return convert_back(hunger);
}

double Critter::converter(int x)
{
	return x/10.0; 
}

int Critter::convert_back(double x)
{
	return x*10;
}