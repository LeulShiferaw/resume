#include "Creature.h"

Creature::Creature(): distance(10)
{}    

void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  



Wizard::Wizard() : distFactor(3)
{}  

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}



void Vampire::bite()
{
	cout << "Biting with a thirst level: " << thirst_level << endl;
}