#include "tile.h"

Tile::Tile(sf::Vector2f pos_, sf::Texture& tex_, sf::Vector2f size_) : Entity(pos_, tex_), size{ size_ } {
	tileShape.setPosition(pos_);
	tileShape.setSize(size_);
	tileShape.setTexture(&tex_);
}

sf::RectangleShape Tile::getRectShape()
{
	return tileShape;
}
