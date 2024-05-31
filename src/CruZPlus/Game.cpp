#include "Game.h"

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <cassert>
#include <cstdio>
#include <filesystem>

#include <imgui-SFML.h>
#include <imgui.h>

#include "CruZPlus/GameEntity/EntityWorld.h"
#include "CruZPlus/Helper/TimeHelper.h"
#include "CruZPlus/Settings.h"
#include "CruZPlus/Configure.h"

namespace CruZ
{
Game::Game()
{
    m_entityWorld = new EntityWorld;
    m_b2World = new b2World(b2Vec2(0, -10));
}

b2World *Game::getB2World()
{
    assert(m_b2World != nullptr);
    return m_b2World;
}

EntityWorld *Game::getEntityWorld()
{
    return m_entityWorld;
}

void Game::run()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1000, 600)), "My window");
    assert(ImGui::SFML::Init(window));

    sf::View view = window.getDefaultView();
    view.setCenter({0, 0});
    view.zoom(ZOOM);
    window.setView(view);

    sf::Clock gameClock;
    float elapsedSeconds = 0;

    printf("%s\n", std::filesystem::current_path().string().c_str());

    while (window.isOpen())
    {
        sf::Event event;
        while (event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        elapsedSeconds += gameClock.restart().asSeconds();
        while (elapsedSeconds > UPDATE_DURATION)
        {
            elapsedSeconds -= UPDATE_DURATION;
            {
                ImGui::SFML::Update(window, Helper::convertToTime(UPDATE_DURATION));
                m_b2World->Step(UPDATE_DURATION, 6, 2);
                m_entityWorld->updateAll(UPDATE_DURATION);
            }
        }

        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
        ImGui::GetIO().IniFilename = CRUZ_BINARY_DIR "/imgui.ini";

        window.clear(sf::Color::Blue);
        {
            m_entityWorld->renderAll(window);
            ImGui::SFML::Render(window);
        }
        window.display();
    }

    ImGui::SFML::Shutdown();
}

Game::~Game()
{
    delete m_b2World;
    delete m_entityWorld;
}
} // namespace CruZ
