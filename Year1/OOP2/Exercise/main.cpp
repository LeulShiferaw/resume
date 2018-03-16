#include <iostream>
#include <stdexcept>

using namespace std;

class type_error : public logic_error
{
	public:
		explicit type_error(const string& msg):logic_error(msg){};
		const char* what() const noexcept;//noexcept is only for c++11
};

const char* type_error::what() const noexcept//noexcept is only for c++11
{
	return "There was a type error.\n";
}

int main()
{

	return 0;
}
