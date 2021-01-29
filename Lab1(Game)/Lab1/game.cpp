#include "game.h"

game::game() :
	m_window(sf::VideoMode(1280, 720), "Lab1")
{
}

game::~game()
{
}

void game::run()
{
	PluginsAndPackets();
	while (m_window.isOpen())
	{
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	
	
	while (!done)
	{
		if (mode == 's')
		{
			std::getline(std::cin, m_text);
			socket.send(m_text.c_str(), m_text.length() + 1);
			mode = 'r';
		}
		else if (mode == 'r')
		{
			socket.receive(buffer, sizeof(buffer), recived);
			if (recived > 0)
			{
				std::cout << "Message: " << buffer << std::endl;
				mode = 's';
			}
		}
		
	}
		while (m_window.isOpen())
		{
			ProcessEvents(); // as many as possible
			timeSinceLastUpdate += clock.restart();
			while (timeSinceLastUpdate > timePerFrame)
			{
				timeSinceLastUpdate -= timePerFrame;
				ProcessEvents(); // at least 60 fps
				update(timePerFrame); //60 fps
			}
			render(); // as many as possible
		}
	}
}

void game::ProcessEvents()
{

}

void game::update(sf::Time t_deltaTime)
{
	m_player.update();
	m_playerTwo.update();
}

void game::PluginsAndPackets()
{
	std::cout << "Enter s for server Enter c for client: " << std::endl;
	std::cin >> connectType;

	if (connectType == 's')
	{
		sf::TcpListener lis;
		lis.listen(2000);
		lis.accept(socket);
		m_text += "Server";
		mode = 's';
	}
	else if (connectType == 'c')
	{
		socket.connect(ip, 2000);
		m_text += "Client";
		mode = 'r';
	}
	socket.send(m_text.c_str(), m_text.length() + 1);
	socket.receive(buffer, sizeof(buffer), recived);

	std::cout << buffer << std::endl;
}

void game::render()
{
	m_window.clear();

	m_playerTwo.draw(m_window);
	m_player.draw(m_window);

	m_window.display();
}
