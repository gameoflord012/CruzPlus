#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include <box2d/box2d.h>

#include "GameEntity/SpaceShip.h"

int main()
{
    b2World world(b2Vec2(0, -10));

    const int FPS = 60;
    const float UPDATE_INTERVAL = 1.0f / FPS;
    const clock_t CLOCK_PER_FRAME = (clock_t)(UPDATE_INTERVAL * CLOCKS_PER_SEC);

    std::clock_t gameClock = 0;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1000, 600)), "My window");

    SpaceShip spaceShip(&world);

    // init window view
    sf::View view = window.getDefaultView();
    view.setCenter({0, 0});
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
        }
        window.display();
    }
}