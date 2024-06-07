#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>

#include <CruZPlus/Game.h>
#include <box2d/box2d.h>

#include <CruZPlus/GameEntity.h>

// #include "GameObjects/PlayerShip.h"
// #include "SpaceShooter/Settings.h"

int main()
{
    try
    {
        auto shad = sf::Shader::loadFromFile("fuck", "fuck", "fuck");
        sf::Shader::bind(&shad.value());
        sf::Shader::bind(NULL);
        glm::
        
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}