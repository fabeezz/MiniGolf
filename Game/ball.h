#pragma once
#include <SFML/Graphics.hpp>
#include "grid.h"

class Ball {
private:
    sf::Vector2f position;
    float radius;
    sf::Color color;
    sf::CircleShape ballShape;

public:
    Ball(sf::Vector2f startPosition, float ballRadius = 10.f, sf::Color ballColor = sf::Color::White);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
    float getBallRadius();
    int getPositionOnGrid(Grid& grid, float incX, float incY);
    void checkCollision(Grid& grid);

    ~Ball();
};
