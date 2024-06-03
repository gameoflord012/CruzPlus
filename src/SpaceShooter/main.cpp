#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>

#include <CruZPlus/Game.h>
#include <box2d/box2d.h>

#include <CruZPlus/GameEntity.h>

#include "SpaceShip.h"

int main()
{
    try
    {
        CruZ::Game game;
        SpaceShooter::SpaceShip spaceShip;
        INS(CruZ::EntityWorld)->addEntity(spaceShip);
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}