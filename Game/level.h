#pragma once
#include "ball.h"
#include "textures.h"
#include "window.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <vector>

//-------------------------------------------------------------

std::vector<Tile> loadObstacles(int level);
std::vector<std::vector<Tile>> loadWater(int level);
std::vector<Hole> loadHole(int level);
std::vector<Ball> loadBall(int level);
