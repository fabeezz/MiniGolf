#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
private:
	sf::Vector2f pos;
	sf::Vector2f scale = { 1,1 };
	sf::Texture tex;

public:
	Entity(sf::Vector2f pos_, sf::Texture tex_);
	sf::Vector2f& getPos();
	sf::Vector2f& getScale();

	void setPos(float x, float y);
	void setPos(sf::Vector2f position);
	void setScale(float w, float h);
	void update(sf::Time dt);

	~Entity();
};
