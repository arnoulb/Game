#include "Player.h"
#include <iostream>

Player::Player()
{
	if (!texture.loadFromFile("dracaufeu_mov.png"))
		std::cerr << "Error loading player.png" << std::endl;
	width = texture.getSize().x / 3;
	height = texture.getSize().y / NBLINES;
	player.setTexture(texture);
	player.setTextureRect(sf::IntRect(0, 0, width, height));
	player.setPosition(100, 100);
	player.scale(4, 4);
	sens = DOWN;

}


Player::~Player()
{

}

sf::Sprite const& Player::getPlayer()
{
	return (this->player);
}

void Player::draw(sf::RenderWindow &win)
{
	win.draw(player);
}

void Player::move(const sf::RenderWindow &win)
{
	sf::Vector2u win_size;
	sf::Vector2f player_pos;

	win_size = win.getSize();
	player_pos = player.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		moveUpRight((player_pos.x + width * player.getScale().y) + 1 < win_size.x && player_pos.y - 1 > 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		moveUpLeft(player_pos.x - 1 > 0 && player_pos.y - 1 > 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		moveDownRight((player_pos.y + height * player.getScale().y) + 1 < win_size.y && (player_pos.x + width * player.getScale().y) + 1 < win_size.x);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		moveDownLeft((player_pos.y + height * player.getScale().y) + 1 < win_size.y && player_pos.x - 1 > 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		moveDown((player_pos.y + height * player.getScale().y) + 1 < win_size.y);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		moveUp(player_pos.y - 1 > 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		moveLeft(player_pos.x - 1 > 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		moveRight((player_pos.x + width * player.getScale().y) + 1 < win_size.x);
	player.setTextureRect(sf::IntRect(0, sens * height, width, height));
}

void Player::moveRight(bool cond)
{
	sens = RIGHT;
	if (cond)
		player.move(STEP, 0);
}

void Player::moveLeft(bool cond)
{
	sens = LEFT;
	if (cond)
		player.move(-STEP, 0);
}

void Player::moveUp(bool cond)
{
	sens = UP;
	if (cond)
		player.move(0, -STEP);
}

void Player::moveDown(bool cond)
{
	sens = DOWN;
	if (cond)
		player.move(0, STEP);
}

void Player::moveUpRight(bool cond)
{
	sens = UPRIGHT;
	if (cond)
		player.move(STEP, -STEP);
}

void Player::moveUpLeft(bool cond)
{
	sens = UPLEFT;
	if (cond)
		player.move(-STEP, -STEP);
}

void Player::moveDownLeft(bool cond)
{
	sens = DOWNLEFT;
	if (cond)
		player.move(-STEP, STEP);
}

void Player::moveDownRight(bool cond)
{
	sens = DOWNRIGHT;
	if (cond)
		player.move(STEP, STEP);
}
