#include "level.h"
#include <iostream>

void loadTexture(sf::Texture& tex_, std::string path_)
{
	std::string destination = "resources/textures/" + path_;
	if (!tex_.loadFromFile(destination)) {
		std::cerr << "Failed to load textures from " << destination << std::endl;
		return;
	}
} // vreau doar o data!

std::vector<Tile> loadObstacles(int level)
{
	static sf::Texture tex;
	loadTexture(tex, "obstacleTX.png");

	std::vector<Tile> obstacles;
	switch (level)
	{
	case 1:
		obstacles.push_back(Tile({ 200, 200 }, tex, { 100, 100 }));
		obstacles.push_back(Tile({ 500, 500 }, tex, { 100, 100 }));
		obstacles.push_back(Tile({ 400, 400 }, tex, { 100, 100 }));
		obstacles.push_back(Tile({ 300, 300 }, tex, { 100, 100 }));
		break;

	case 2:
		obstacles.push_back(Tile({ 400, 400 }, tex, { 100, 100 }));
		break;
	}

	/*
	TODO: add more tiles
	*/
	return obstacles;
}

std::vector<std::vector<Tile>> loadWater(int level)
{
	static sf::Texture waterTX_l;
	static sf::Texture waterTX_r;
	static sf::Texture waterTX_u;
	static sf::Texture waterTX_d;

	loadTexture(waterTX_l, "waterTX_l.png");
	loadTexture(waterTX_r, "waterTX_r.png");
	loadTexture(waterTX_u, "waterTX_u.png");
	loadTexture(waterTX_d, "waterTX_d.png");

	std::vector<Tile> w_l;
	std::vector<Tile> w_r;
	std::vector<Tile> w_u;
	std::vector<Tile> w_d;

	switch (level)
	{
	case 1:
		w_l.push_back(Tile({ 300, 200 }, waterTX_l, { 100, 100 }));
		w_u.push_back(Tile({ 750, 500 }, waterTX_u, { 100, 100 }));
		w_r.push_back(Tile({ 550, 400 }, waterTX_r, { 100, 100 }));
		w_d.push_back(Tile({ 400, 500 }, waterTX_d, { 100, 100 }));
		break;

	case 2:
		w_l.push_back(Tile({ 550, 400 }, waterTX_l, { 100, 100 }));
		break;
	}

	/*
	TODO: add more tiles
	*/
	return { w_l, w_r, w_u, w_d };
}

std::vector<Hole> loadHole(int level) // de ce nu merge Hole
{
	static sf::Texture tex;
	loadTexture(tex, "holeTX.png");

	std::vector<Hole> holes;

	switch (level)
	{
	case 1:
		holes.push_back(Hole({ 800, 200 }, tex, h_radius));
		break;

	case 2:
		holes.push_back(Hole({ 200, 200 }, tex, h_radius));
		break;
	}

	/*
	TODO: add more holes
	*/
	return holes;
}