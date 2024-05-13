#pragma once
#include "level.h"
#include <SFML/Graphics.hpp>
#include <vector>
class Grid
{
private:
	int numRows, numCols;
	int cellSize;
	int table[20][20];
public:
	Grid();
	void Initialize(Level& level);
	void PrintGrid();
	void DrawGrid(sf::RenderWindow& window) const;

	std::pair<int, int> getGridPosition(sf::Vector2f position) const;
	int getCellValue(int& row, int& column) const;
};

