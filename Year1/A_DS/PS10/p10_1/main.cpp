#include <string>
#include <iostream>

using namespace std;

class type
{
	public:
		int age;
		string profession,name;
		type(const int&,const string&,const string&);
};

type::type(const int &a,const string &n, const string &p)
	:age(a),profession(p),name(n){}

int main()
{
	type my_typ=type(30,"Alice","Teacher");

	return 0;
}
