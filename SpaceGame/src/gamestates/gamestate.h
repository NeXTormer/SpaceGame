#pragma once

#include <SFML\Graphics.hpp>

class GameState
{
public:
	virtual void handleEvent(sf::Event &event) = 0;
	virtual void update(sf::Int32 delta) = 0;
	virtual void draw() = 0;
};