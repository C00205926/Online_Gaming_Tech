#include "Player.h"

Player::Player()
{
	m_player.setRadius(20.f);
	m_player.setPosition(20.f, 20.f);
	m_player.setFillColor(sf::Color::Blue);
	m_player.setOutlineThickness(2.5f);
	m_player.setOutlineColor(sf::Color::White);

	moveSpeed = 10.f;
}

Player::~Player()
{

}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(m_player);
}

void Player::update()
{
	Move();
	BoundaryCheck();
}

void Player::Move()
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_player.move(-moveSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player.move(moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_player.move(0.f, -moveSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_player.move(0.f, moveSpeed);
	}
}

void Player::BoundaryCheck()
{
	sf::FloatRect playerPos = m_player.getGlobalBounds();

	if (playerPos.left <= 0)
		m_player.setPosition(0, playerPos.top);
	else if (playerPos.left + playerPos.width >= 1280)
		m_player.setPosition(1280 - playerPos.width, playerPos.top);
	if (playerPos.top <= 0)
		m_player.setPosition(playerPos.left , 0);
	else if (playerPos.top + playerPos.height >= 720)
		m_player.setPosition(playerPos.left, 720 - playerPos.height);
}
