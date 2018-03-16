#include "City.h"

void City::setNh(const int &x)
{
	nh = x;
}

void City::setName(const std::string &s)
{
	name = s;
}

void City::setMayor(const std::string &s)
{
	mayor = s;
}

int City::getNh()
{
	return nh;
}

std::string City::getName()
{
	return name;
}

std::string City::getMayor()
{
	return mayor;
}

void City::print()
{
	std::cout << "Number of inhabitants: " << nh << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Mayor: " << mayor << std::endl;
}