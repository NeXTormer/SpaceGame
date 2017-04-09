#include "playstate.h"

PlayState::PlayState(sf::RenderWindow &window)
	: m_Window(window), background(window.getSize().x, window.getSize().y)
{
	
}

PlayState::~PlayState()
{

}

void PlayState::draw()
{
	m_Window.draw(background);
}

void PlayState::update(float delta)
{
	background.update(delta);
}

void PlayState::handleEvent(sf::Event &event)
{

}