#include "ball.h"
#include "grid.h"
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

void Ball::update(sf::Time dt)
{
	sf::Vector2f newPosition = { this->getPosition().x,this->getPosition().y };
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

void Ball::checkCollision(Grid& grid)
{
	if (this->collisionEast(grid) == true || this->collisionWest(grid) == true)
		dirX = -dirX;
	if (this->collisionNorth(grid) == true || this->collisionSouth(grid) == true)
		dirY = -dirY;
}

Ball::~Ball()
{
}
