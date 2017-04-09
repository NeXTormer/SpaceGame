#include "game.h"

Game::Game(int width, int height, int maxfps, bool fullscreen)
	: m_Clearcolor(0x030303FF)
{
	m_Width = width;
	m_Height = height;
	m_Fullscreen = fullscreen;
	m_Resizeable = true;
	m_MaxFPS = maxfps;

	setup();
}

Game::~Game()
{
	delete m_Window;
	delete playstate;
}

void Game::setup()
{
	if (m_Fullscreen)
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(m_Width, m_Height), "SpaceGame", sf::Style::Fullscreen);
	}
	else
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(m_Width, m_Height), "SpaceGame", sf::Style::Default | sf::Style::Close);
	}
	m_Window->setFramerateLimit(m_MaxFPS);

	camera = sf::View(sf::Vector2f(0, 0), sf::Vector2f(m_Width, m_Height));

	playstate = new PlayState();
	
	m_Gamestatemanager.push(playstate);

	run();
}

void Game::run()
{
	sf::Uint32 frames = 0;
	time.restart();
	while (m_Window->isOpen())
	{
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			m_Gamestatemanager.handleEvent(event);
			switch (event.type)
			{
				case sf::Event::Closed:
					m_Window->close();
					return;
					break;
				case sf::Event::Resized:
					if (m_Resizeable)
					{
						m_Window->setSize(sf::Vector2u(event.size.width, event.size.height));
						m_Width = event.size.width;
						m_Height = event.size.height;
						LOG2("width: %i, height %i \n", m_Width, m_Height)
						break;
					}
					break;
			}
		}

		m_Window->clear(m_Clearcolor);
		m_Window->setView(camera);

		m_Gamestatemanager.update(clock.getElapsedTime().asMilliseconds());
		m_Gamestatemanager.draw();

		m_Window->display();

		frames++;
		if (time.getElapsedTime().asMilliseconds() >= 1000)
		{
			LOG1("FPS: %i\n", frames)
			frames = 0;
			time.restart();
		}
		
		clock.restart();
	}
}