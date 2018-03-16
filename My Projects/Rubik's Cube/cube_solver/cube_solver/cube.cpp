#include "cube.h"

Cube::Cube()
{

}

void up_left()
{

}

void up_right()
{
	vector<Face> temp_faces;

	for (int i = 0; i < 6; ++i)
		temp_faces.push_back(faces[i]);

	//Exchange the first row values
	faces[0].set_row(1, temp_faces[3].get_row(1));
	faces[1].set_row(1, temp_faces[2].get_row(1));
	faces[2].set_row(1, temp_faces[1].get_row(1));
	faces[3].set_row(1, temp_faces[2].get_row(1));
}

void