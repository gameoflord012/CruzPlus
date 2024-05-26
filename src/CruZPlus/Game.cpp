#include "Game.h"

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <cassert>

#include <CruZPlus/Settings.h>

namespace CruZ
{
    Game::Game()
    {
        m_b2World = new b2World(b2Vec2(0, -10));
    }

    b2World *Game::getB2World()
    {
        assert(m_b2World != nullptr);
        return m_b2World;
    }

    EntityWorld *Game::getEntityWorld()
    {
        return &m_entityWorld;
    }

    void Game::run()
    {
        // init window
        sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1000, 600)), "My window");
        sf::View view = window.getDefaultView();
        view.setCenter({0, 0});
        view.zoom(ZOOM);
        window.setView(view);

        std::clock_t gameClock = 0;
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

                m_b2World->Step(UPDATE_INTERVAL, 6, 2);
                m_entityWorld.updateAll(UPDATE_INTERVAL);
            }

            window.clear(sf::Color::Blue);
            {
                m_entityWorld.renderAll(window);
            }
            window.display();
        }
    }
    
    Game::~Game()
    {
        delete m_b2World;
    }
}
