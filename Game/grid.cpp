#include "grid.h"
#include "color.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

Grid::Grid()
{
	numRows = 20;
	numCols = 20;
	cellSize = 50;
}

void Grid::Initialize(Level& level)
{
	std::vector<int> info = level.getLevelData();
	int k = 0;
	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numCols; j++)
		{
			table[i][j] = info[k];
			//if (i == 0 || j == 0 || i == numRows - 1 || j == numCols - 1)
				//grid[i][j] = 1;
			k++;
		}
}

void Grid::PrintGrid()
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			std::cout << table[i][j] << ", ";
		std::cout << std::endl;
	}
}

void Grid::DrawGrid(sf::RenderWindow& window) const
{
	sf::RectangleShape cell;
	std::vector<sf::Color> colors = GetCellColors();
	cell.setSize(sf::Vector2f(cellSize, cellSize));
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			int cellValue = table[i][j];
			cell.setPosition(j * cellSize+50, i * cellSize+50);
			cell.setFillColor(colors[cellValue]);
			window.draw(cell);
		}
	}
}

std::pair<int, int> Grid::getGridPosition(sf::Vector2f position) const
{
	int gridX = (int)((position.x - 50) / cellSize);  // Adjusting for the offset
	int gridY = (int)((position.y - 50) / cellSize);
	return { gridX, gridY };
}

int Grid::getCellValue(int& row, int& column) const
{
	return table[row][column];
}

