#pragma once
#include "hole.h"
#include "tile.h"
#include <SFML/Graphics.hpp>
#include <vector>

constexpr float h_radius = 20;

void loadTexture(sf::Texture& tex_, std::string path_);
std::vector<Tile> loadObstacles(int level);
std::vector<std::vector<Tile>> loadWater(int level);
std::vector<Hole> loadHole(int level);
