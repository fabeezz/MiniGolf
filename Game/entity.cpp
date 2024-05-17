#include "entity.h"

Entity::Entity(sf::Vector2f pos_, sf::Texture tex_) : pos{ pos_ }, tex{ tex_ } {

}

sf::Vector2f& Entity::getPos()
{
	return pos;
}

sf::Vector2f& Entity::getScale()
{
	return scale;
}

void Entity::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Entity::setPos(sf::Vector2f position)
{
	pos.x = position.x;
	pos.y = position.y;
}

void Entity::setScale(float w, float h)
{
	scale.x = w;
	scale.y = h;
}

void Entity::update(sf::Time dt) {}

Entity::~Entity() {}
