#include <iostream>

using namespace std;

typedef const int cint;
const char null_char = '.';

int main()
{
	int n;
	cin >> n;

	int left_value = 0, right_value = 0;
	char op = null_char; //No pending calculation
	char c, var, undo_c = null_char;
	bool left = true; //Current side
	bool x_left = false; //The side the var is on
	
	for (int i = 0; i < n; ++i)
	{
		cin >> c;

		if (c == '=')
			left = false;
		else if (c <= '9'&&c >= '0')
		{
			//The beginning
			if (op == null_char)
			{
				if (left)
					left_value = c - '0';
				else
					right_value = c - '0';
			}
			//Pending Calculation
			else if (left)
			{
				if (op == '+')
					left_value += c - '0';
				else
					left_value -= c - '0';
			}
			else if (op == '+')
				right_value += c - '0';
			else
				right_value -= c - '0';
			op = null_char;//No pending calculation
		}
		else if (c <= 'z'&&c >= 'a')
		{
			var = c;       //Set the variable
			undo_c = op;   //Set the char right befor the var, so I can undo it later
			x_left = left; //Set var's side.
			op = null_char;//No pending calc
		}
		else op = c;//Last choice is an operator
	}

	int val = 0;
	if (x_left)
		val = right_value - left_value;
	else
		val = left_value - right_value;

	if (undo_c == '-')
		val *= -1;

	cout << var << "=" << val << endl;
}