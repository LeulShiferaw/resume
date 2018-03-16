#include "face.h"

Face::Face()
{
	initialized = false;
}

Face::Face(COLOR color)
{
	initialized = true;

	whole_set(color);
}

void Face::whole_set(COLOR color)
{
	for (int x = 0; x < cube_size; ++x)
	{
		for (int y = 0; y < cube_size; ++y)
		{
			colors[x][y] = color;
		}
	}
}

void Face::set_row(int row, const vector<COLOR>& row_colors)
{
	if (row_colors.size() != cube_size)
		error("Error in set_row");
	for (int i = 0; i < cube_size; ++i)
	{
		row_colors[row][i] = row_colors[i];
	}
}

void Face::set_column(int column, const vector<COLOR>& column_colors)
{
	if (column_colors.size() != cube_size)
		error("Error in set_row");
	for (int i = 0; i < cube_size; ++i)
	{
		column_colors[column][i] = column_colors[i];
	}
}

vector<COLOR> Face::get_row(int row)
{
	if (row >= cube_size)
		error("Error in get_row");

	vector<COLOR> row_vec;
	for (int i = 0; i < cube_size; ++i)
	{
		row_vec.push_back(colors[row][i]);
	}

	return row_vec;
}

vector<COLOR> Face::get_column(int column)
{
	if (column >= cube_size)
		error("Error in get_row");

	vector<COLOR> column_vec;
	for (int i = 0; i < cube_size; ++i)
	{
		column_vec.push_back(colors[column][i]);
	}

	return column_vec;
}