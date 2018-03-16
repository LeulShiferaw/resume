#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML sample");
    sf::CircleShape Circle;
    sf::Event event;
    while(window.pollEvent(event))
    {
        while(event.type == sf::Event::Closed)
            window.close();
        window.clear();
        window.draw(Circle);
        window.display();
    }
}
