#include "ball.h"
#include "grid.h"
#include "level.h"
#include <iostream>
#include <SFML/Graphics.hpp>

constexpr int vmWIDTH = 1100, vmHEIGHT = 1100;
constexpr float ballRadius = 15;

int main()
{
	sf::RenderWindow window(sf::VideoMode(vmWIDTH, vmHEIGHT), "MiniGolf");
	sf::Time dt;
	sf::Clock clock;

	Level level1("Level1", "resources/levels/level1.txt");
	level1.CreateLevel();
	//level1.PrintLevel(level1);
	/*
	TODO: add more levels, make it so that an function initializes all levels
	*/

	Grid grid = Grid();
	grid.Initialize(level1);
	//grid.PrintGrid();

	Ball ball = Ball({ 520, 220 }, ballRadius, sf::Color::White);

	std::cout << ball.collisionEast(grid);

	//std::cout << "Ball is on value: " << ball.getPositionOnGrid(grid, ballRadius, 0);

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

		grid.DrawGrid(window);
		ball.checkCollision(grid);
		ball.update(dt);
		ball.draw(window);


		window.display();
	}

	return 0;
}