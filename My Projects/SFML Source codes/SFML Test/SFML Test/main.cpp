#include <iostream>
#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

#define ORIGIN 300

float func(float x)
{
	return sin(x)*10;
}

struct pos
{
	float x;
	float y;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Graphs");

	sf::RectangleShape x_axis, y_axis;

	//X_axis initializations
	x_axis.setSize(sf::Vector2f(600, 1));
	x_axis.setPosition(sf::Vector2f(0, 299));

	//Y_axis initializations
	y_axis.setSize(sf::Vector2f(1, 600));
	y_axis.setPosition(sf::Vector2f(299, 0));

	sf::RectangleShape point;
	point.setSize(sf::Vector2f(1, 1));
	point.setPosition(sf::Vector2f(100, 100));

	vector<pos> graph;

	for (float i = 0; i < 200; i+=0.1)
	{
		pos temp;
		temp.x = i;
		temp.y = func(temp.x);
		graph.push_back(temp);
	}

	for (int i = 0; i < graph.size(); i++)
	{
		cout << graph[i].x << " " << graph[i].y << endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		window.clear();
		window.draw(x_axis);
		window.draw(y_axis);
		for (int i = 0; i < graph.size(); i++)
		{
			point.setPosition(sf::Vector2f(ORIGIN+graph[i].x, ORIGIN-graph[i].y));
			window.draw(point);
		}
		window.display();
	}
}