#include <iostream>
#include "TournamentMember.h"	

using namespace std;

int TournamentMember::c_members = 0;
int TournamentMember::t_members = 0;
std::string TournamentMember::location = "Bremen"; //Initially location is Bremen

TournamentMember::TournamentMember():f_name("John"), l_name("Doe"), d_birth("0000-00-00")
{
	++t_members;
	++c_members;

	cout << "Constructor!" << endl;
	cout << "Current Members: " << c_members << endl;
	cout << "Total Members: " << t_members << endl;
}

TournamentMember::~TournamentMember()
{
	--c_members;
	cout << "Destructor!" << endl;
	cout << "Current Members: " << c_members << endl;
	cout << "Total Members: " << t_members << endl;
}

TournamentMember::TournamentMember(const std::string &f_name, const std::string &l_name, const std::string & d_birth)
{
	this->f_name = f_name;
	this->l_name = l_name;
	this->d_birth = d_birth;

	++t_members;
	++c_members;

	cout << "Constructor!" << endl;
	cout << "Current Members: " << c_members << endl;
	cout << "Total Members: " << t_members << endl;	
}

TournamentMember::TournamentMember(const TournamentMember &rhs)
	:f_name(rhs.f_name), l_name(rhs.l_name), d_birth(rhs.d_birth)
{
	++t_members;
	++c_members;

	cout << "Copy Constructor!" << endl;
	cout << "Current Members: " << c_members << endl;
	cout << "Total Members: " << t_members << endl;
}

void TournamentMember::print_status() const
{
	cout << "First Name: " << f_name << endl;
	cout << "Last Name: " << l_name << endl;
	cout << "Date of Birth: " << d_birth << endl;
}

void TournamentMember::change_location(const std::string &nl)
{
	location = nl;
}
