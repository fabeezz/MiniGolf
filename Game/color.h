#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

const sf::Color gCourse(0, 145, 112); //course's green grass
const sf::Color bLimit(139, 69, 19); // course's limit
const sf::Color lbObstacle(244, 164, 96); //course's obstacles
const sf::Color bWater(135, 206, 250); //course's water flow

std::vector<sf::Color> GetCellColors();