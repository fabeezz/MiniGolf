#include <SFML/Graphics.hpp>
#include <iostream>
#include "grid.h"
#include "ball.h"
#include "level.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1100, 1100), "SFML works!");

    Level level1("Level1", "resources/levels/level1.txt");
    level1.CreateLevel();
    //level1.PrintLevel(level1);
    
    Grid grid = Grid();
    grid.Initialize(level1);
    grid.PrintGrid();
    
    Ball ball = Ball({ 500, 500 }, 15, sf::Color::White);



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