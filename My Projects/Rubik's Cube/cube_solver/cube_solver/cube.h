#ifndef CUBE_H
#define CUBE_H

#include "face.h"

class Cube
{
private:
	Face faces[6];
public:
	Cube();                 //Enter the values of the faces
	void display();         //Display all the faces
	void up_left();
	void up_right();
	void right_up();
	void right_down();
	void left_up();
	void left_down();
	void down_left();
	void down_right();
	bool is_initialized();  //Check all faces
};

#endif