#pragma once

#include <SFML\Graphics.hpp>

#include "../gamestates/gamestatemanager.h"
#include "../gamestates/playstate.h"
#include "defines.h"

class Game
{
public:
	Game(int width, int height, int maxfps, bool fullscreen);
	~Game();

private:
	sf::RenderWindow *m_Window;
	
	sf::Color m_Clearcolor;
	sf::View camera;
	sf::Clock clock;
	sf::Clock time;

	GameStateManager m_Gamestatemanager;
	PlayState *playstate;
	
	int m_Width;
	int m_Height;
	int m_MaxFPS;

	bool m_Fullscreen;
	bool m_Resizeable;
	
	void setup();
	void run();
};