#pragma once
#include <vector>
#include <string>

class Level
{
private:
	std::string levelName;
	std::string levelFile;
	std::vector<int> data;

public:
	Level(const std::string& levelName, const std::string& levelFile);
	std::string getLevelName() const;
	std::string getLevelFile() const;
	std::vector<int> getLevelData() const;
	void CreateLevel();
	void PrintLevel(Level &level);
};

