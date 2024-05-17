#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Tile : public Entity
{
public:
	Tile(sf::Vector2f pos_, sf::Texture& tex_, sf::Vector2f size_);
	sf::RectangleShape getRectShape();

private:
	sf::RectangleShape tileShape;
	sf::Vector2f size;
};
