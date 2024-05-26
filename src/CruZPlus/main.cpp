#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include <box2d/box2d.h>

#include "BodyFactory.h"
#include "Game.h"

#include "Memory/BlockAllocator.h"
#include "Memory/TexutureManager.h"

#include "GameEntity/Bullet.h"
#include "GameEntity/SpaceShip.h"

using namespace CruZ;

int main()
{
    try
    {
        TextureManager textureManager;
        Game game;
        Physic physic(*game.getB2World());

        Instances::set(game);
        Instances::set(physic);
        Instances::set(textureManager);

        SpaceShip spaceShip;
        game.getEntityWorld()->addEntity(spaceShip);
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}