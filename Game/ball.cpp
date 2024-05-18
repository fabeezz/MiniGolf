#include "ball.h"

Ball::Ball(sf::Vector2f pos_, sf::Texture& tex_, float b_radius_) : Entity(pos_, tex_), b_radius{ b_radius_ } {
	ballShape.setPosition(pos_);
	ballShape.setRadius(b_radius_);
	ballShape.setTexture(&tex_);
}

/*
// Assuming Entity class also needs to be copied correctly
Ball::Ball(const Ball& other)
	: Entity(other), // Call the copy constructor of the base class Entity
	b_radius(other.b_radius), // Copy the radius
	ballShape(other.ballShape) // Copy the sf::CircleShape
{
	// Since sf::CircleShape does not store a reference to its texture, we need to reassign it
	ballShape.setTexture(other.ballShape.getTexture());
	// Ensure the position and other properties are also copied if they are not already handled by the sf::CircleShape copy
	ballShape.setPosition(other.ballShape.getPosition());
	ballShape.setRadius(other.ballShape.getRadius());
	ballShape.setTextureRect(other.ballShape.getTextureRect());
}
*/

sf::CircleShape& Ball::getBallShape()
{
	return ballShape;
}
