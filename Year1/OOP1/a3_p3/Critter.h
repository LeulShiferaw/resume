#include <string> // defines standard C++ string class

class Critter
{
private:  
	std::string name;
	double hunger;
	int boredom;
	double height;
	double converter(int);
	int convert_back(double);
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