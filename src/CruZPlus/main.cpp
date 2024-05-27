#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include <box2d/box2d.h>

#include "Physic.h"
#include "GameEntity.h"
#include "Game.h"

#include "Memory/BlockAllocator.h"
#include "TextureManager.h"

#include "GameEntity/Bullet.h"
#include "GameEntity/SpaceShip.h"
#include "Editor/EditorUI.h"

using namespace CruZ;

int main()
{
    try
    {
        TextureManager textureManager;
        Game game;
        BodyFactory physic(*game.getB2World());

        Instances::set(game);
        Instances::set(physic);
        Instances::set(textureManager);

        SpaceShip spaceShip;
        EditorUI editorUI;
        game.getEntityWorld()->addEntity(spaceShip);
        game.getEntityWorld()->addEntity(editorUI);
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}