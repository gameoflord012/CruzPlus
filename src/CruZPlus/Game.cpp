#include "Game.h"

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <cassert>

Game::Game()
{
    m_b2World = new b2World(b2Vec2(0, -10));
}

b2World *Game::getWorld()
{
    assert(m_b2World != nullptr);
    return m_b2World;
}

void Game::run()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1000, 600)), "My window");
    sf::View view = window.getDefaultView();
    view.setCenter({0, 0});
    view.zoom(0.25);
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
            updateAll(UPDATE_INTERVAL);
        }

        window.clear(sf::Color::Blue);
        {
            renderAll(window);
        }
        window.display();
    }
}

bool Game::addUpdate(IUpdate &iupdate)
{
    auto it = std::find(m_updates.begin(), m_updates.end(), &iupdate);
    if (it != m_updates.end())
    {
        assert(false && "already added");
        return false;
    }

    m_updates.push_back(&iupdate);
    return true;
}

bool Game::addRender(IRender &irender)
{
    auto it = std::find(m_renders.begin(), m_renders.end(), &irender);
    if (it != m_renders.end())
    {
        assert(false && "already added");
        return false;
    }

    m_renders.push_back(&irender);
    return true;
}

void Game::updateAll(float deltaTime)
{
    for (size_t i = 0; i < m_updates.size(); i++)
    {
        m_updates[i]->update(deltaTime);
    }
}

void Game::renderAll(sf::RenderWindow &window)
{
    for (size_t i = 0; i < m_updates.size(); i++)
    {
        m_renders[i]->render(window);
    }
}

Game::~Game()
{
    delete m_b2World;
}
