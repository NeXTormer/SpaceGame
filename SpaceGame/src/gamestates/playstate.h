#pragma once

#include "gamestate.h"
#include "../game/defines.h"
#include "../entities/background.h"
class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow &window);
	~PlayState();
	void draw() override;
	void update(float delta) override;
	void handleEvent(sf::Event &event) override;

private:
	sf::RenderWindow &m_Window;
	Background background;

	
};