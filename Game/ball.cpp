#include "ball.h"

Ball::Ball(sf::Vector2f startPosition, float ballRadius, sf::Color ballColor) :
    position(startPosition), radius(ballRadius), color(ballColor) {
    ballShape.setRadius(radius);
    ballShape.setFillColor(color);
    ballShape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window) const {
    window.draw(ballShape);
}

sf::Vector2f Ball::getPosition() const {
    return ballShape.getPosition();
}

Ball::~Ball()
{
}
