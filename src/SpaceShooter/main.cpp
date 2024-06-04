#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>

#include <CruZPlus/Game.h>
#include <box2d/box2d.h>

#include <CruZPlus/GameEntity.h>

#include "SpaceShip.h"
#include "SpaceShooter/Settings.h"

int main()
{
    try
    {
        CruZ::Game game;
        game.getView()->zoom(SpaceShooter::Settings::CAMERA_ZOOM);
        SpaceShooter::SpaceShip spaceShip;
        INS(CruZ::EntityWorld)->addEntity(spaceShip);
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}