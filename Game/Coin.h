#pragma once
#include <SFML/Graphics.hpp>
class Coin
{
public:
	Coin();
	~Coin();
	void draw(sf::RenderWindow &);
	const sf::Sprite &getCoin();
	void newPosition(sf::RenderWindow &);

private:
	int sprite;
	int width;
	int height;
	sf::Texture texture;
	sf::Sprite coin;

	sf::Clock time;
	bool fpsUpdate;
	float fpsCount;
	float fpsSpeed;
	float fpsSwitch;
};

