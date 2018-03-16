#include <string> // defines standard C++ string class

class Critter
{
private:  
	std::string name;
	int hunger;
	int boredom;
	double height;

public: 
	Critter(std::string = "default_critter");
	Critter(std::string, int, int, int = 10);

	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	// getter method
	int getHunger();
	// service method
	void print();
};