#include "gamestatemanager.h"

void GameStateManager::handleEvent(sf::Event &event)
{
	m_Gamestates.top()->handleEvent(event);
}

void GameStateManager::update(float delta)
{
	m_Gamestates.top()->update(delta);
}

void GameStateManager::draw()
{
	m_Gamestates.top()->draw();
}

void GameStateManager::push(GameState *gamestate)
{
	m_Gamestates.push(gamestate);
}

void GameStateManager::pop()
{
	m_Gamestates.pop();
}

GameState* GameStateManager::peek()
{
	return m_Gamestates.top();
}