#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>

#include "CruZPlus/Memory/BlockAllocator.h"
#include "Entity.h"
#include "Bullet.h"

namespace CruZ
{
    class SpaceShip : public Entity, public PhysicComponent
    {
    public:
        SpaceShip();
        void render(sf::RenderWindow &window);
        void update(float elapsedTime);
        ~SpaceShip();

    private:
        BlockAllocator m_allocator;
        b2World *m_b2world;
        sf::Sprite *m_sprite;

        bool m_lastSpace;

        std::vector<Bullet *> m_bullets;
    };
}