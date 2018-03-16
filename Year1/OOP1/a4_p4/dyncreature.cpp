/*
	CH08-320142
	a4_p4.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Creature.h"
#include <string>

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    Wizard *pw = NULL;
    Vampire *pv = NULL;
    Werewolf *pww = NULL;
    
    string str;
    while(true)
    {
        cout << ": ";
        cin >> str;

        if(str == "Wizard")
        {
            cout << "\nCreating a Wizard\n";
            pw = new Wizard;
        }
        else if(str == "Vampire")
            pv = new Vampire;
        else if(str == "Werewolf")
            pww = new Werewolf;
        else if(str == "quit")
            break;
        else continue;

        if(str == "Wizard")
        {
            pw->run();
            pw->hover();
            delete pw;
        }
        else if(str == "Vampire")
        {
            pv->run();
            pv->bite();
            delete pv;
        }
        else if(str == "Werewolf")
        {
            pww->run();
            pww->eat();
            delete pww;
        }
    }
    return 0;
} 