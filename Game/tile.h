#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Tile : public Entity
{
public:
	Tile(const sf::Vector2f pos_, sf::Texture& tex_, sf::Vector2f size_);
	Tile(const sf::Vector2f pos_, sf::Texture& tex_, float squareSize_);
	sf::RectangleShape& getRectShape();

private:
	sf::RectangleShape tileShape;
	sf::Vector2f size;
};
