#include <iostream>
#include "TournamentMember.h"	

using namespace std;

int TournamentMember::c_members = 0;
int TournamentMember::t_members = 0;
std::string TournamentMember::location = "Bremen"; //Initially location is Bremen

TournamentMember::~TournamentMember()
{
	--c_members;
	cout << "Destructor!" << endl;
	cout << "Current Members: " << c_members << endl;
	cout << "Total Members: " << t_members << endl;
}

TournamentMember::TournamentMember():f_name("John"), l_name("Doe"), d_birth("0000-00-00")
{
	++t_members;
	++c_members;

	cout << "Constructor!" << endl;
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
	cout << "Location: " << location << endl;
	cout << "Date of Birth: " << d_birth << endl;
}

void TournamentMember::change_location(const string &nl)
{
	location = nl;
}

//Class Player
Player::Player() : number(7), number_goals(0), l_foot(false), position("Goal Keeper")
{
	cout << "Player Constructor!" << endl << endl;
}

Player::Player(const std::string &fn, const std::string &ln, const std::string &db,
				 const int &n, const int &ng, const bool &lf, const std::string &pos)
 : TournamentMember(fn, ln, db), number(n), number_goals(ng), l_foot(lf), position(pos)
{
	cout  << "Player Constructor!" << endl << endl;
}

Player::~Player()
{
	cout << "Player Destructor!" << endl;
}

Player::Player(const Player &rhs)
: TournamentMember(rhs.get_f_name(), rhs.get_l_name(), rhs.get_d_birth()), number(rhs.get_number()), 
				   number_goals(rhs.get_ngoals()), l_foot(rhs.is_lfoot()), position(rhs.get_pos())
{
	cout << endl << "Player Copy Constructor!" << endl;
}

void Player::print_status() const
{
	cout << "First Name: " << get_f_name() << endl;
	cout << "Last Name: " << get_l_name() << endl;
	cout << "Location: " << get_loc() << endl;
	if(l_foot)
		cout << "Left footed" << endl;
	else cout << "Right footed" << endl;
	cout << "Date of Birth: " << get_d_birth() << endl << endl;
}

void Player::increment_goal()
{
	++number_goals;
}