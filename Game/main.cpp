#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "My Game");
	sf::RectangleShape background;
	sf::Vector2f winSize;

	Player player;
	srand(time(NULL));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				sf::Vector2u size;
				size.x = event.size.width;
				size.y = event.size.height;
				window.setSize(size);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		winSize.x = int(window.getSize().x);
		background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
		background.setFillColor(sf::Color::Black);
		player.move(window);
		window.clear();
		window.draw(background);
		window.draw(player.getPlayer());
		window.display();
	}
	return (0);
}