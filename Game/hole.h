#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Hole : public Entity
{
public:
	Hole(sf::Vector2f pos_, sf::Texture& tex_, float h_radius_);
	sf::CircleShape& getHoleShape();
	float getHoleRad();

private:
	sf::CircleShape holeShape;
	float h_radius = 20;
};
