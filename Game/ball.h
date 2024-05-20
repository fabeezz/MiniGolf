#pragma once
#include "entity.h"
#include "tile.h"
#include "hole.h"
#include "textures.h"
#include "window.h"
#include <SFML/Graphics.hpp>

constexpr float ballRad = 16;

class Ball : public Entity
{
public:
	Ball(sf::Vector2f pos_, sf::Texture& tex_, float b_radius_);
	sf::CircleShape& getBallShape();

	void setVelocity(float x, float y);
	void setVelocity(sf::Vector2f velo);
	void setLaunchVelocity(float x, float y);
	void setLaunchVelocity(sf::Vector2f velo);

	void setInitialMousePos(float x, float y);
	void setWin(bool win_);

	void update(sf::Time dt, bool mouseDown, bool mousePressed, std::vector<Tile> tiles, Hole& hole);
private:
	sf::CircleShape ballShape;
	float b_radius = ballRad;

	sf::Vector2f target;
	sf::Vector2f initMousePos;
	sf::Vector2f velocity;
	sf::Vector2f launchVelocity;
	float velocity1D;
	float launchVelocity1D;
	float friction = 0.001f;

	bool canMove = true;
	bool win = false;

};

