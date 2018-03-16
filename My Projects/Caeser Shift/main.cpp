#include <iostream>
#include <string>

using namespace std;

typedef const int cint;
typedef const string cstr;

string caeser_shift(cstr& s, cint &n)
{
	string result = "";
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i]<'A'&&s[i]>'Z')
			result += s[i];
		result += 'A' + (s[i] + n) % 26;
	}
		
	return result;
}

int main()
{
	int n;
	string s;
	cout << "String: ";
	cin >> s;

	cout << "N: ";
	while (cin >> n)
	{
		cout << caeser_shift(s, n) << endl;
		cout << "N: ";
	}
		
}