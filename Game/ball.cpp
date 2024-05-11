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

void Ball::checkCollision(Grid& grid)
{
    float ballRadius = this->getBallRadius();
    int north = this->getPositionOnGrid(grid, ballRadius, 0);
    int south = this->getPositionOnGrid(grid, ballRadius, 2*ballRadius);
    int west = this->getPositionOnGrid(grid, 0, ballRadius);
    int east = this->getPositionOnGrid(grid, 2*ballRadius, ballRadius);
    std::cout << "North: " << north << "West: " << west << "South: " << south << "East: " << east << std::endl;

}

Ball::~Ball()
{
}
