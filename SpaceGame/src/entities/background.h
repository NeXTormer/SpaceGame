#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>

class Background : public sf::Drawable, public sf::Transformable
{
public:
	Background(int width, int height);
	~Background();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates renderstates) const;
	void update(float delta);
private:
	sf::Texture m_Texture;
	sf::VertexArray m_Mesh;

	int m_Movespeed = 10;
	int m_Width;
	int m_Height;
	int m_Iterationsx;
	int m_Iterationsy;
	int m_SingleTextureSize;

	int m_pos2 = 0;

};