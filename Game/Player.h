#pragma once

#include <SFML/Graphics.hpp>

enum
{
	RIGHT, // = 0
	LEFT, // = 1
	UP, // = 2
	DOWN, // = 3
	UPRIGHT, // = 4
	UPLEFT, // = 5
	DOWNLEFT, // = 6
	DOWNRIGHT // = 7
};

#define STEP 0.5 // Vitesse de déplacement
#define NBLINES 8 // Nombre de lignes de l'image

class Player
{
public:
	Player();
	~Player();
	sf::Sprite const& getPlayer();
	void move(const sf::RenderWindow &);
	void moveLeft(bool);
	void moveRight(bool);
	void moveUp(bool);
	void moveDown(bool);
	void moveUpRight(bool);
	void moveDownLeft(bool);
	void moveDownRight(bool);
	void moveUpLeft(bool);
	void draw(sf::RenderWindow &);

private:
	sf::Texture texture;
	sf::Sprite player;
	int width;
	int height;
	int sens;

};

