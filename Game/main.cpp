#include <SFML/Graphics.hpp>
#include <iostream>
#include "grid.h"
#include "ball.h"
#include "level.h"

constexpr int vmWIDTH = 1100, vmHEIGHT = 1100;
constexpr float ballRadius = 15;

int main()
{
    sf::RenderWindow window(sf::VideoMode(vmWIDTH, vmHEIGHT), "MiniGolf");

    Level level1("Level1", "resources/levels/level1.txt");
    level1.CreateLevel();
    //level1.PrintLevel(level1);
    /*
    TODO: add more levels, make it so that an function initializes all levels
    */
    
    Grid grid = Grid();
    grid.Initialize(level1);
    //grid.PrintGrid();
    
    Ball ball = Ball({ 520, 220 }, ballRadius , sf::Color::White);

    ball.checkCollision(grid);

    std::cout << "Ball is on value: " << ball.getPositionOnGrid(grid, ballRadius, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //std::cout << sf::Mouse::getPosition(window).x <<" "<< sf::Mouse::getPosition(window).y<< std::endl;
        window.clear(sf::Color::Black);

        grid.DrawGrid(window);
        ball.draw(window);
        window.display();
    }
    
    return 0;
}