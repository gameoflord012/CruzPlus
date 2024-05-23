#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include <box2d/box2d.h>

#include "GameEntity/SpaceShip.h"
#include "Editor/Board.h"

const int FPS = 60;
const float UPDATE_INTERVAL = 1.0f / FPS;
const clock_t CLOCK_PER_FRAME = (clock_t)(UPDATE_INTERVAL * CLOCKS_PER_SEC);

int main()
{
    std::clock_t gameClock = 0;
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1000, 600)), "My window");

    b2World world(b2Vec2(0, -10));
    SpaceShip spaceShip(&world);
    Board board;

    // init window view
    sf::View view = window.getDefaultView();
    view.setCenter({0, 0});
    view.zoom(0.25);
    window.setView(view);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (event = window.pollEvent())
        {
            if (event.is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        while ((std::clock() - gameClock) > CLOCK_PER_FRAME)
        {
            gameClock += CLOCK_PER_FRAME;
            world.Step(UPDATE_INTERVAL, 6, 2);

            spaceShip.update(UPDATE_INTERVAL);
        }

        window.clear(sf::Color::Blue);
        {
            spaceShip.render(window);
            board.render(window);
        }
        window.display();
    }
}