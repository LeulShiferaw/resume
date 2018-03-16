#include "TournamentMember.h"

int main()
{
	TournamentMember test("Leul", "Shiferaw", "1998-10-08");
	test.print_status();
	TournamentMember test_0();
	test_0.set_f_name("Leul");
	test_0.set_l_name("Haile");
	test_0.set_d_birth("1997-08-19");
	test_0.print_status();
	return 0;
}