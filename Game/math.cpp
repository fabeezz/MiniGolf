#include "math.h"

float getDistance(sf::Vector2f pointA, sf::Vector2f pointB)
{
    return (sqrt(pow(pointA.x - pointA.x, 2) + pow(pointA.y - pointB.y, 2)));
}
