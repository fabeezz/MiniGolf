#pragma once
#include <vector>
#include "level.h"
#include <SFML/Graphics.hpp>
class Grid
{
private:
	int numRows, numCols;
	int cellSize;
public:
	Grid();
	void Initialize(Level& level);
	void PrintGrid();
	void DrawGrid(sf::RenderWindow& window) const;
	int grid[20][20];
};

