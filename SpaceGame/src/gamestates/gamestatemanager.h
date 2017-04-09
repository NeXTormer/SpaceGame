#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <stack>

#include "gamestate.h"

class GameStateManager
{
public:
	void handleEvent(sf::Event &event);
	void update(sf::Int32 delta);
	void draw();

	void push(GameState *gamestate);
	void pop();
	GameState* peek();

private:
	std::stack<GameState*> m_Gamestates;
};