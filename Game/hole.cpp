#include "hole.h"

Hole::Hole(sf::Vector2f pos_, sf::Texture& tex_, float h_radius_) : Entity(pos_, tex_), h_radius{ h_radius_ } {
	holeShape.setPosition(pos_);
	holeShape.setRadius(h_radius_);
	holeShape.setTexture(&tex_);
}

sf::CircleShape& Hole::getHoleShape()
{
	return holeShape;
}

float Hole::getHoleRad()
{
	return h_radius;
}
