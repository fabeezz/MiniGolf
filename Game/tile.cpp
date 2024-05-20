#include "tile.h"

Tile::Tile(const sf::Vector2f pos_, sf::Texture& tex_, sf::Vector2f size_) : Entity(pos_, tex_), size{ size_ } {
	tileShape.setPosition(pos_);
	tileShape.setSize(size_);
	tileShape.setTexture(&tex_);
}

Tile::Tile(const sf::Vector2f pos_, sf::Texture& tex_, float squareSize_) : Entity(pos_, tex_), size {squareSize_, squareSize_} {
	tileShape.setPosition(pos_);
	tileShape.setSize(size);
	tileShape.setTexture(&tex_);
}

sf::RectangleShape& Tile::getRectShape()
{
	return tileShape;
}
