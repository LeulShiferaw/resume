#ifndef FACE_H
#define FACE_H

#include <c++\std_lib_facilities.h>

constexpr int cube_size = 3;

enum COLOR{ RED, GREEN, BLUE, WHITE, ORANGE };

class Face
{
private:
	bool initialized;
	COLOR colors[cube_size][cube_size];
public:
	Face();
	Face(COLOR);
	void display();
	void whole_set(COLOR);
	vector<COLOR> get_row(int);
	vector<COLOR> get_column(int);
	bool is_initialized(){ return initialized; }
	void set_row(int, const vector<COLOR>&);    //COLOR is a vector
	void set_column(int, const vector<COLOR>&); //COLOR is a vector
};

#endif