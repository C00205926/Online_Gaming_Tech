
#ifndef PLAYER2_H
#define PLAYER2_H

#include <SFML/Graphics.hpp>


class PlayerTwo
{
public:
	PlayerTwo();
	~PlayerTwo();

	void update();
	void draw(sf::RenderWindow& window);
	sf::CircleShape m_player;
private:


	void Move();
	void BoundaryCheck();

	float moveSpeed;
};
#endif