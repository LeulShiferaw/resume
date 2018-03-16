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
	virtual ~TournamentMember();
	virtual void print_status() const;
	static void change_location(const std::string &); //Set the new location

	//Setters
	void decrement_members(){--c_members;}
	void increment_members(){++c_members; ++t_members;}
	void set_f_name(const std::string &x){f_name = x;}
	void set_l_name(const std::string &x){l_name = x;}
	void set_d_birth(const std::string &x){d_birth = x;}

	//Getters
	int get_c_mem() const {return c_members;}
	int get_t_mem() const {return t_members;}
	std::string get_loc() const {return location;}
	std::string get_f_name() const {return f_name;}
	std::string get_l_name() const {return l_name;}
	std::string get_d_birth() const {return d_birth;}
};

class Player : public TournamentMember
{
private:
	int number;
	int number_goals;
	bool l_foot;
	std::string position;
public:
	Player();
	Player(const std::string &, const std::string &, const std::string &, const int &, 
		   const int &, const bool &, const std::string &);
	~Player(); //Had to make it virtual because I will be deleting a Player in  Refree
	Player(const Player&);

	//Setters
	void set_number(const int &n){number = n;}
	void set_lfoot(const bool &t){l_foot = t;}
	void set_pos(const std::string &s){position = s;}

	//Getters
	int get_number() const {return number;}
	int get_ngoals() const {return number_goals;}
	bool is_lfoot() const {return l_foot;}
	std::string get_pos() const {return position;}

	void print_status() const;
	void increment_goal();
	bool is_equal(const Player &p) const;
};

class Refree : public TournamentMember
{
private:
	int ycc; //yellow card count
	Player *ycl[40]; //Yellow card list
	int rcc; //Red card count
	Player *rcl[40]; //Red card list
public:
	Refree(const std::string &, const std::string &, const std::string &);
	~Refree();
	
	bool addYCL(Player *);
	bool addRCL(Player *);
	void printYCL() const;
	void printRCL() const;
	void removeYCL(const int &);
	
	int find(Player *, Player *[], const int &) const;
};