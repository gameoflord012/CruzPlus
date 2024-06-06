#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>

#include <CruZPlus/Game.h>
#include <box2d/box2d.h>

#include <CruZPlus/GameEntity.h>

#include "GameObjects/PlayerShip.h"
#include "SpaceShooter/Settings.h"

int main()
{
    try
    {
        CruZ::Game game;
        game.getView()->zoom(SpaceShooter::Settings::CAMERA_ZOOM);

        SpaceShooter::PlayerShip playerShip;
        INS(CruZ::EntityWorld)->addEntity(playerShip);

        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}