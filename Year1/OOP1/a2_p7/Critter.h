#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int iq;
	int bmi;
	int hunger;
	int boredom;
	double height;

public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setIQ(const int &);
	void setBMI(const int &);
	// getter method
	int getHunger();
	int getIQ();
	int getBMI();
	// service method
	void print();
};