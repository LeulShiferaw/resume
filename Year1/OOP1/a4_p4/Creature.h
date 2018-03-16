#include <iostream>

using namespace std;

class Creature {
    public:
        Creature();  
        void run() const;
 
    protected:
        int distance;
};

class Wizard : public Creature {
    public:
        Wizard();
        void hover() const;
 
    private:
        int distFactor;
};

class Vampire : public Creature
{
private:
    int thirst_level;
public:
    Vampire(int x = 10):thirst_level(1 + x%10){cout << "Constructor for Vampire" << endl;}
    ~Vampire(){cout << "Destroying vampire" << endl;}
    void bite();
};

class Werewolf : public Creature
{
private:
    int hunger_level;
public:
    Werewolf(int x = 10):hunger_level(1+x%10){cout << "Constructor for Werewolf" << endl;}
    ~Werewolf(){cout << "Destroying werewolf" << endl;}
    void eat(){cout << "Eating with a hunger level: " << hunger_level << endl;}
};
