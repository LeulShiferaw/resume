/*	
	CH08-320142
	a5_p3.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "TournamentMember.h"

int main()
{
	Player p1("Leul", "Shiferaw", "1998-10-08", 7, 300, false, "Striker");
	Player p2("Tensaiye", "Zelealem", "1999-03-09", 9, 30, false, "Goal Keeper");
	Player p3("Isaac", "Amare", "1956-04-08", 2, 3, true, "Defender");
	
	Player::change_location("Hamburg");

	p1.print_status();
	p2.print_status();
	p3.print_status();

	return 0;
}