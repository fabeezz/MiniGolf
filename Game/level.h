#pragma once
#include "hole.h"
#include "tile.h"
#include "window.h"
#include "ball.h"
#include "textures.h"
#include <SFML/Graphics.hpp>
#include <vector>

constexpr float holeRad = 20;

//-------------------------------------------------------------

std::vector<Tile> loadObstacles(int level);
std::vector<std::vector<Tile>> loadWater(int level);
std::vector<Hole> loadHole(int level);
std::vector<Ball> loadBall(int level);
