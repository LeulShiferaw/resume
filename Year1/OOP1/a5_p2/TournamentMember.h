#include <string>

class TournamentMember
{
private:
	std::string f_name, l_name, d_birth;

	static int c_members; //Current members
	static int t_members; //Total members ever
	static std::string location;
public:
	TournamentMember();
	TournamentMember(const std::string &, const std::string &, const std::string &);
	TournamentMember(const TournamentMember &);
	~TournamentMember();
	void print_status() const;
	static void change_location(const std::string &); //Set the new location

	//Setters
	void set_f_name(const std::string &x){f_name = x;}
	void set_l_name(const std::string &x){l_name = x;}
	void set_d_birth(const std::string &x){d_birth = x;}

	//Getters
	std::string get_f_name() const {return f_name;}
	std::string get_l_name() const {return l_name;}
	std::string get_d_birth() const {return d_birth;}
};
