
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	~Player();

	void update();
	void draw(sf::RenderWindow & window);
private:
	sf::CircleShape m_player;

	void Move();
	void BoundaryCheck();

	float moveSpeed;
};
#endif
