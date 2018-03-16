/*
 * JTSK-320143
 * a1_p2.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	//Read Input Filename
	char file[100];
	cin >> file;

	//Open input file
	ifstream file_in(file, ios::binary|ios::in);
	if(!file_in.is_open())
	{
		cout << "Error Opening File!\n";
		return 1;
	}

	//Open output file
	ofstream file_out("output.txt", ios::binary|ios::out);
	if(!file_out.is_open())
	{
		cout << "Error Writing to file!\n";
		return 1;
	}

	file_in.seekg(0,ios_base::end);//Go to last pos

	long length=ceil(file_in.tellg()/(double)sizeof(char));//Number of bytes

	//Read entire file
	char readFile[length];
	file_in.seekg(0,ios_base::beg);
	file_in.read(readFile,length);

	file_out.write(readFile,length);//Write entire file

	//Close files
	file_in.close();
	file_out.close();

	return 0;
}
