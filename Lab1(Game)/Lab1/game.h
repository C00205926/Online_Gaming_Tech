#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Player2.h"
#include <WinSock2.h>
#include <SFML/Network.hpp>
#include<iostream>
class game
{
public:
	game();
	~game();
	void run();

	Player m_player;
	PlayerTwo m_playerTwo;
	sf::RenderWindow m_window;

	bool done = false;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char connectType;
	char mode;
	char buffer[100];
	std::size_t recived;
	std::string m_text = "Connected to ";
private:
	


	void ProcessEvents();
	void render();
	void update(sf::Time t_deltaTime);
	void PluginsAndPackets();
};
#endif

