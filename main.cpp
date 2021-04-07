#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
	sf::Vector2f speed(rand()%2?1:-1,rand()%2?1:-1);
	sf::Clock clock;
	sf::Time elapsed;
	window.setFramerateLimit(60);
    while (window.isOpen())
    {
		elapsed+=clock.restart();
		if(elapsed>=sf::milliseconds(200)) {
			elapsed = sf::Time::Zero;
			speed = sf::Vector2f(rand()%2?1:-1,rand()%2?1:-1);
		}
		shape.setPosition(shape.getPosition()+speed);
		if(shape.getPosition().x<0)
			shape.setPosition(0,shape.getPosition().y);
		if(shape.getPosition().y<0)
			shape.setPosition(shape.getPosition().x,0);
		if(shape.getPosition().x+shape.getGlobalBounds().width> window.getSize().x)
			shape.setPosition(window.getSize().x-shape.getGlobalBounds().width,shape.getPosition().y);
		if(shape.getPosition().y+shape.getGlobalBounds().height> window.getSize().y)
			shape.setPosition(shape.getPosition().x,window.getSize().y-shape.getGlobalBounds().height);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}