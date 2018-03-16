#include "iring.h"

iring::iring()
:ring(""), i(0)
{}

int iring::get()
{
	char ch;
	cin >> ch;

	if (ch <'0' && ch > '9')
		error("Invalid Character " + ch);

	ring += ch;
	i += (ch - '0') * (pow(10, ring.size() - 1));

	return i;
}

int iring::int_form()
{
	return i;
}

void iring::set_int(int val)
{
	i = val;
}

string iring::string_form()
{
	return ring;
}