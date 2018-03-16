#include <string>
#include <iostream>

class City
{
private:
	int nh;
	std::string name;
	std::string mayor;
public:
	City(){}
	void setNh(const int &x);
	void setName(const std::string &);
	void setMayor(const std::string &s);

	int getNh();
	std::string getName();
	std::string getMayor();

	void print();
};