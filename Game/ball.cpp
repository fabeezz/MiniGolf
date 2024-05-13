#include "ball.h"
#include "grid.h"
#include <algorithm>
#include <cmath>
#include <iostream>

Ball::Ball(sf::Vector2f startPosition, float ballRadius, sf::Color ballColor) :
	position(startPosition), radius(ballRadius), color(ballColor) {
	ballShape.setRadius(radius);
	ballShape.setFillColor(color);
	ballShape.setPosition(position);
	ballShape.setOutlineThickness(2.f); // Thickness of the outline
	ballShape.setOutlineColor(sf::Color::Black); // Color of the outline
}

void Ball::draw(sf::RenderWindow& window) const {
	window.draw(ballShape);
}

sf::Vector2f Ball::getPosition() const {
	return ballShape.getPosition();
}

float Ball::getBallRadius() {
	return this->radius;
}

sf::CircleShape Ball::getCircleShape()
{
	return ballShape;
}

int Ball::getPositionOnGrid(Grid& grid, float incX, float incY)
{
	float ballRadius = this->getBallRadius();
	sf::Vector2f ballCentrePosition = this->getPosition(); //ball's origin position
	ballCentrePosition.x += incX;
	ballCentrePosition.y += incY;
	//std::cout << "Ball pos: "<<ballPosition.x << " " << ballPosition.y << std::endl;
	std::pair<int, int> ballOnGridPosition = grid.getGridPosition(ballCentrePosition);
	//std::cout << "Ball pos on grid: " << ballOnGridPosition.first << " " << ballOnGridPosition.second << std::endl;
	//std::cout << "Ball is on the cell with number: " <<
		//grid.getCellValue(ballOnGridPosition.second, ballOnGridPosition.first) << std::endl;
	return grid.getCellValue(ballOnGridPosition.second, ballOnGridPosition.first);
}
/*
bool Ball::checkCollisionWithCell(Grid& grid) {
	sf::Vector2f ballCenter = this->getPosition();
	ballCenter.x += this->radius;  // Adjust to get the center of the ball
	ballCenter.y += this->radius;

	int cellSize = grid.getCellSize();

	std::pair<int, int> gridPos = grid.getGridPosition(ballCenter);
	int cellValue = grid.getCellValue(gridPos.second, gridPos.first);

	if (cellValue == 1 || cellValue == 2) {
		// Calculate the nearest point on the rectangle to the ball's center
		float nearestX = std::max(static_cast<float>(gridPos.first * cellSize + 50),
			std::min(ballCenter.x, static_cast<float>((gridPos.first + 1) * cellSize + 50)));
		float nearestY = std::max(static_cast<float>(gridPos.second * cellSize + 50),
			std::min(ballCenter.y, static_cast<float>((gridPos.second + 1) * cellSize + 50)));

		// Calculate the distance from the ball's center to this nearest point
		float distX = ballCenter.x - nearestX;
		float distY = ballCenter.y - nearestY;
		float distance = std::sqrt(distX * distX + distY * distY);

		// Check if the distance is less than the ball's radius
		if (distance <= this->radius) {
			return true;  // Collision detected
		}
	}
	return false;  // No collision
}

void Ball::update(sf::Time dt, Grid& grid) {
	if (!checkCollisionWithCell(grid)) {
		sf::Vector2f newPosition = this->getPosition();
		newPosition.x += dirX * velocity * dt.asSeconds();
		newPosition.y += dirY * velocity * dt.asSeconds();
		this->getCircleShape().setPosition(newPosition);
	} else {
		// Handle collision (e.g., reverse direction, stop, etc.)
		dirX = -dirX;
		dirY = -dirY;
	}
}
*/

void Ball::update(sf::Time dt, Grid& grid)
{
	sf::Vector2f newPosition = { this->getPosition().x,this->getPosition().y };
	this->checkCollision(grid);
	
	newPosition.x += dirX * velocity * dt.asSeconds();
	newPosition.y += dirY * velocity * dt.asSeconds();
	ballShape.setPosition(newPosition);
}

bool Ball::collisionNorth(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	int ok = this->getPositionOnGrid(grid, ballRadius, 0);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionSouth(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	int ok = this->getPositionOnGrid(grid, ballRadius, 2 * ballRadius);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionWest(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	int ok = this->getPositionOnGrid(grid, 0, ballRadius);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionEast(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	int ok = this->getPositionOnGrid(grid, 2 * ballRadius, ballRadius);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionNW(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	float rv = ballRadius * (sqrt(2) - 1);
	float x = sqrt(pow(rv, 2) / 2);
	int ok = this->getPositionOnGrid(grid, x, x);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionNE(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	float rv = ballRadius * (sqrt(2) - 1);
	float y = sqrt(pow(rv, 2) / 2);
	float x = y + ballRadius;
	int ok = this->getPositionOnGrid(grid, x, y);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionSW(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	float rv = ballRadius * (sqrt(2) - 1);
	float x = sqrt(pow(rv, 2) / 2);
	float y = x + ballRadius;
	int ok = this->getPositionOnGrid(grid, x, y);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

bool Ball::collisionSE(Grid& grid)
{
	float ballRadius = this->getBallRadius();
	float rv = ballRadius * (sqrt(2) - 1);
	float x = sqrt(pow(rv, 2) / 2);
	x += ballRadius;
	int ok = this->getPositionOnGrid(grid, x, x);
	if (ok == 1 || ok == 2)
		return true;
	return false;
}

/*
bool Ball::collisionCorner(Grid& grid)
{
	float ballRadius = this->getBallRadius();
}
*/

void Ball::checkCollision(Grid& grid)
{
	if (this->collisionEast(grid) == true || this->collisionWest(grid) == true)
	{
		dirX = -dirX;
		this->getCircleShape().setPosition(this->getPosition().x + 1, this->getPosition().y);
	}
	if (this->collisionNorth(grid) == true || this->collisionSouth(grid) == true)
	{
		dirY = -dirY;
		this->getCircleShape().setPosition(this->getPosition().x, this->getPosition().y + 1);
	}
	if (this->collisionNE(grid) == true)
	{
		dirX = -dirX;
		dirY = -dirY;
		this->getCircleShape().setPosition(this->getPosition().x - 1, this->getPosition().y + 1);
	}
	if (this->collisionNW(grid) == true)
	{
		dirX = -dirX;
		dirY = -dirY;
		this->getCircleShape().setPosition(this->getPosition().x + 1, this->getPosition().y + 1);
	}
	if (this->collisionSE(grid) == true)
	{
		dirX = -dirX;
		dirY = -dirY;
		this->getCircleShape().setPosition(this->getPosition().x - 1, this->getPosition().y - 1);
	}
	if (this->collisionSW(grid) == true)
	{
		dirX = -dirX;
		dirY = -dirY;
		this->getCircleShape().setPosition(this->getPosition().x + 1, this->getPosition().y - 1);
	}

}

Ball::~Ball()
{
}
