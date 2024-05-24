#include "GameEntity/SpaceShip.h"
#include "Editor/Board.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include <box2d/box2d.h>

#include "Game.h"

int main()
{
    try
    {
        CruZ::Game game;

        CruZ::Board board;
        CruZ::SpaceShip spaceShip(game.getWorld());

        game.addUpdate(spaceShip);
        game.addRender(spaceShip);
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}