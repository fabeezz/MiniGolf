#include <SFML/Graphics.hpp>
#include <iostream>
#include "grid.h"
#include "ball.h"
#include "level.h"

constexpr int vmWIDTH = 1100, vmHEIGHT = 1100;
constexpr int ballRadius = 15;

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
    
    Ball ball = Ball({ 505, 300 }, ballRadius , sf::Color::White);

    sf::Vector2f ballPosition = ball.getPosition(); //ball's position
    //std::cout << "Ball pos: "<<ballPosition.x << " " << ballPosition.y << std::endl;
    std::pair<int, int> ballOnGridPosition = grid.getGridPosition(ballPosition);
    //std::cout << "Ball pos on grid: " << ballOnGridPosition.first << " " << ballOnGridPosition.second << std::endl;
    std::cout << "Ball is on the cell with number: " << 
        grid.getCellValue(ballOnGridPosition.second, ballOnGridPosition.first) << std::endl;

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