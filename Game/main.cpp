#include "hole.h"
#include "level.h"
#include "tile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

constexpr int vmWIDTH = 1100, vmHEIGHT = 1100;
//constexpr float ballRadius = 15;

int main()
{
	sf::RenderWindow window(sf::VideoMode(vmWIDTH, vmHEIGHT), "MiniGolf");
	//window.setFramerateLimit(60);
	sf::Time dt;
	sf::Clock clock;

	while (window.isOpen())
	{
		dt = clock.restart();
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//std::cout << sf::Mouse::getPosition(window).x <<" "<< sf::Mouse::getPosition(window).y<< std::endl;
		window.clear(sf::Color::Black);

		int level = 1;

		std::vector<Tile> obstacles = loadObstacles(level);
		std::vector<std::vector<Tile>> water = loadWater(level);
		Hole hole = loadHole(level)[0];
		for (Tile& obstacle : obstacles)
			window.draw(obstacle.getRectShape());
		for (std::vector<Tile>& flow : water)
			for (Tile& water_tile : flow)
				window.draw(water_tile.getRectShape());
		window.draw(hole.getCircShape());
		window.display();
	}

	return 0;
}