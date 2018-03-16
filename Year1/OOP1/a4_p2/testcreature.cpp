/*
	CH08-320142
	a4_p2.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Creature.h"

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    Vampire v;
    v.run();
    v.bite();

    Werewolf ww;
    ww.run();
    ww.eat();

    return 0;
} 