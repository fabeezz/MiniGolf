#include "level.h"
#include <iostream>

constexpr float obst64X = 64.0f;
constexpr float obst128X = 128.0f;
constexpr float obst64Y = 67.0f;
constexpr float obst128Y = 131.0f;

sf::Vector2f vect128 = { 128.0f, 131.0f };
sf::Vector2f vect64 = { 64.0f, 67.0f };

//-----------------------------------------------------------------------------------

std::vector<Tile> loadObstacles(int level)
{
	/*
		 ___800___
		|
	   960
		|
	*/
	std::vector<Tile> obstacles = {};

	switch (level)
	{
	case 1:
		obstacles.push_back(Tile({ 0, (vmHEIGHT - vect128.y) / 2 }, obstacleTX, vect128));
		obstacles.push_back(Tile({ vmWIDTH - vect128.x, (vmHEIGHT - obst128Y) / 2 }, obstacleTX, vect128));
		obstacles.push_back(Tile({ obst128X, (vmHEIGHT - vect128.y) / 2 }, obstacleTX, vect128));
		obstacles.push_back(Tile({ vmWIDTH - 2 * obst128X, (vmHEIGHT - obst128Y) / 2 }, obstacleTX, vect128));

		break;

	case 2:
		obstacles.push_back(Tile({ 400, 400 }, obstacleTX, { 100, 100 }));
		break;
	}
	//TODO: add more tiles

	return obstacles;
}

std::vector<std::vector<Tile>> loadWater(int level)
{
	std::vector<Tile> w_l = {};
	std::vector<Tile> w_r = {};
	std::vector<Tile> w_u = {};
	std::vector<Tile> w_d = {};

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

std::vector<Hole> loadHole(int level)
{
	std::vector<Hole> holes = {};
	float holeRad = 20;
	switch (level)
	{
	case 1:
		holes.push_back(Hole({ vmWIDTH / 2 - holeRad, 100 }, holeTX, holeRad));
		break;

	case 2:
		holes.push_back(Hole({ 200, 200 }, holeTX, holeRad));
		break;
	}
	//TODO: add more holes
	return holes;
}

std::vector<Ball> loadBall(int level)
{
	std::vector<Ball> balls;
	switch (level)
	{
	case 1: {
		balls.push_back(Ball({ vmWIDTH / 2 - ballRad, vmHEIGHT - 100 }, ballTX, ballRad));
		break;
	}
	case 2: {

		break;
	}
	default:
		break;

	}
	return balls;
}
