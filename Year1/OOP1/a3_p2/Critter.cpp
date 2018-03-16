#include <iostream>
#include "Critter.h"

using namespace std;

Critter::Critter(std::string s): name(s), hunger(0), boredom(0), height(5){}
Critter::Critter(std::string s, int x, int y, int z): name(s), hunger(x), boredom(y), height(z){}

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
}

int Critter::getHunger() {
	return hunger;
}