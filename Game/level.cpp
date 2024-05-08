#include "level.h"
#include <iostream>
#include <fstream>

Level::Level(const std::string& levelName, const std::string& levelFile)
	: levelName(levelName), levelFile(levelFile) {}

std::string Level::getLevelName() const
{
	return levelName;
}

std::string Level::getLevelFile() const
{
	return levelFile;
}

std::vector<int> Level::getLevelData() const
{
	return data;
}

void Level::CreateLevel()
{
	std::ifstream inputFile(this->getLevelFile());
	if (inputFile.is_open()) {
		int value;
		while (inputFile >> value)
			this->data.push_back(value);
	}
	inputFile.close();
}

void Level::PrintLevel(Level &level)
{
	for (int it : level.getLevelData())
		std::cout << it << " ";
}
