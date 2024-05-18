#include "ball.h"
#include "hole.h"
#include "level.h"
#include "textures.h"
#include "tile.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode((int)vmWIDTH, (int)vmHEIGHT), "MiniGolf");
	//window.setFramerateLimit(60);
	sf::Time dt;
	sf::Clock clock;

	initializeTextures();
	int level = 1;
	std::vector<Tile> obstacles = loadObstacles(level);
	std::vector<std::vector<Tile>> water = loadWater(level);
	std::vector<Hole> holes = loadHole(level);
	Ball ball = loadBall(level)[0];
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

		//std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
		window.clear(sf::Color(0, 145, 112));

		for (Tile& obstacle : obstacles)
			window.draw(obstacle.getRectShape());
		//for (std::vector<Tile>& flow : water)
			//for (Tile& water_tile : flow)
				//window.draw(water_tile.getRectShape());
		for (Hole& hole : holes) {
			window.draw(hole.getHoleShape());
		}
		window.draw(ball.getBallShape());

		window.display();
	}

	return 0;
}