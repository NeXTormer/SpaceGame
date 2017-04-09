#pragma once

#include "gamestate.h"
#include "../game/defines.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();
	void draw() override;
	void update(sf::Int32 delta) override;
	void handleEvent(sf::Event &event)override;
};