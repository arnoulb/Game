#include "Coin.h"

#include "Coin.h"
#include <iostream>
#include <SFML/System.hpp>

Coin::Coin()
{
	if (!texture.loadFromFile("coin.jpg"))
		std::cerr << "Error loading coin.jpg" << std::endl;
	width = texture.getSize().x / 10;
	height = texture.getSize().y;
	coin.setTexture(texture);
	coin.setTextureRect(sf::IntRect(0, 0, width, height));
	coin.setPosition(100, 100);
	coin.scale(0.5, 0.5);
	sprite = 0;
}

Coin::~Coin()
{
}

void Coin::draw(sf::RenderWindow &win)
{
	coin.setTextureRect(sf::IntRect(sprite * width, 0, width, height));
	win.draw(coin);
	sprite = (sprite + 1) % 10;
}

void Coin::newPosition(sf::RenderWindow &win)
{
	sf::Vector2u size;

	size = win.getSize();
	size.x -= (coin.getPosition().x * coin.getScale().x);
	size.y -= (coin.getPosition().y * coin.getScale().y);
	coin.setPosition(rand() % size.x, rand() % size.y);

}
const sf::Sprite &Coin::getCoin()
{
	sprite = (sprite + 1) % 10;
	coin.setTextureRect(sf::IntRect(sprite * width, 0, width, height));
	return (coin);
}
