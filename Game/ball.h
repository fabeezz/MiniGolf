#pragma once
#include "grid.h"
#include <algorithm>
#include <SFML/Graphics.hpp>

class Ball {
private:
	sf::Vector2f position;
	float radius;
	sf::Color color;
	sf::CircleShape ballShape;
	float dirX = 1.0f, dirY = 1.0f;
	float velocity = 300;

public:
	Ball(sf::Vector2f startPosition, float ballRadius = 10.f, sf::Color ballColor = sf::Color::White);

	void draw(sf::RenderWindow& window) const;

	sf::Vector2f getPosition() const;
	float getBallRadius();
	sf::CircleShape getCircleShape();
	int getPositionOnGrid(Grid& grid, float incX, float incY);

	//bool checkCollisionWithCell(Grid& grid);
	//void update(sf::Time dt, Grid& grid);
	void update(sf::Time dt, Grid& grid);

	bool collisionNorth(Grid& grid);
	bool collisionSouth(Grid& grid);
	bool collisionWest(Grid& grid);
	bool collisionEast(Grid& grid);
	bool collisionNW(Grid& grid);
	bool collisionNE(Grid& grid);
	bool collisionSW(Grid& grid);
	bool collisionSE(Grid& grid);
	void checkCollision(Grid& grid);

	~Ball();
};
