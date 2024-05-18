#pragma once
#include "entity.h"
#include "textures.h"
#include "window.h"
#include <SFML/Graphics.hpp>

constexpr float ballRad = 16;

class Ball : public Entity
{
public:
	Ball(sf::Vector2f pos_, sf::Texture& tex_, float b_radius_);
	sf::CircleShape& getBallShape();

private:
	sf::CircleShape ballShape;
	float b_radius;
};

