#include "background.h"

Background::Background(int width, int height)
{
	m_Width = width;
	m_Height = height;
	m_Texture.loadFromFile("res/backgrounds/black.png");
	m_Iterationsx = floor(width / m_Texture.getSize().x) + 1;
	m_Iterationsy = floor(width / m_Texture.getSize().y) + 1;
	m_SingleTextureSize = m_Texture.getSize().x;

	m_Mesh = sf::VertexArray(sf::PrimitiveType::Quads, m_Iterationsx * m_Iterationsy * 4);

	for (int i = 0; i < 4 ; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sf::Vertex *current = &m_Mesh[(i * 4 + j) * 4];

			current[0].position = sf::Vector2f(j * m_SingleTextureSize, i * m_SingleTextureSize);
			current[1].position = sf::Vector2f((j + 1) * m_SingleTextureSize, i * m_SingleTextureSize);
			current[2].position = sf::Vector2f((j + 1) * m_SingleTextureSize, (i + 1) * m_SingleTextureSize);
			current[3].position = sf::Vector2f(j * m_SingleTextureSize, (i + 1) * m_SingleTextureSize);

			current[0].texCoords = sf::Vector2f(0, 0);
			current[1].texCoords = sf::Vector2f(m_SingleTextureSize, 0);
			current[2].texCoords = sf::Vector2f(m_SingleTextureSize, m_SingleTextureSize);
			current[3].texCoords = sf::Vector2f(0, m_SingleTextureSize);
		}
	}
}

Background::~Background()
{

}

void Background::draw(sf::RenderTarget &target, sf::RenderStates renderstates) const
{
	renderstates.transform = getTransform();
	renderstates.texture = &m_Texture;

	target.draw(m_Mesh, renderstates);
	
	renderstates.transform.translate(sf::Vector2f(-m_Width, 0));

	target.draw(m_Mesh, renderstates);
}

void Background::update(float delta)
{
	if (getPosition().x > m_Width) 
	{
		setPosition(sf::Vector2f(0, 0));
	}
	move(sf::Vector2f(delta, 0));

}