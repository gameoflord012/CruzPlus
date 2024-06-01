#include "Game.h"

#include <cassert>
#include <cstdio>
#include <filesystem>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>

#include <box2d/box2d.h>

#include <imgui-SFML.h>
#include <imgui.h>

#include "CruZPlus/Input.h"
#include "CruZPlus/Configure.h"
#include "CruZPlus/GameEntity/EntityWorld.h"
#include "CruZPlus/Helper/TimeHelper.h"
#include "CruZPlus/Settings.h"

namespace CruZ
{
Game::Game()
{
    m_input = new Input;
    m_entityWorld = new EntityWorld;
    m_b2World = new b2World(b2Vec2(0, -10));

    Instances::set(m_input);
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

    m_view = new sf::View({0, 0}, window.getDefaultView().getSize());
    m_view->setCenter({0, 0});
    m_view->zoom(ZOOM);
    window.setView(*m_view);

    sf::Clock gameClock;
    float elapsedSeconds = 0;

    // printf("%s\n", std::filesystem::current_path().string().c_str());

    while (window.isOpen())
    {
        sf::Event event;
        while (event = window.pollEvent())
        {
            if (event.is<sf::Event::Closed>())
            {
                window.close();
            }

            ImGui::SFML::ProcessEvent(window, event);
            m_input->processEvent(event);
        }

        elapsedSeconds += gameClock.restart().asSeconds();
        while (elapsedSeconds > UPDATE_DURATION)
        {
            elapsedSeconds -= UPDATE_DURATION;
            {
                m_input->updateInput();
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
    delete m_view;
}
} // namespace CruZ
