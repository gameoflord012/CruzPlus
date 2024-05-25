#include "GameEntity/SpaceShip.h"
#include "Editor/Board.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include <box2d/box2d.h>

#include "Physic.h"
#include "Game.h"
#include "Instances.h"
#include "GameEntity/Bullet.h"
#include "Memory/BlockAllocator.h"

using namespace CruZ;

int main()
{
    try
    {
        Game game;
        BlockAllocator allocator;
        Physic physic(*game.getWorld());

        Instances::set(game);
        Instances::set(physic);
        Instances::set(allocator);

        SpaceShip spaceShip;
        game.addUpdate(spaceShip);
        game.addRender(spaceShip);

        sf::Texture bulletTex;
        assert(bulletTex.loadFromFile("res/main_ship_bullet.png"));
        Bullet bullet(allocator, bulletTex);
        game.addUpdate(bullet);
        game.addRender(bullet);

        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}