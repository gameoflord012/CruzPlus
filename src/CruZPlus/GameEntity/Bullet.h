#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CruZPlus/Memory/BlockAllocator.h"
#include "Entity.h"
#include "Physic/PhysicComponent.h"

class CruZ::BlockAllocator;

namespace CruZ
{
    class Bullet : public Entity, private PhysicComponent
    {
    public:
        Bullet(BlockAllocator &);
        void setPosition(const sf::Vector2f &position);
        void update(float deltaTime);
        void render(sf::RenderWindow &);
        ~Bullet();

    private:
        BlockAllocator *m_allocator;
        sf::Sprite *m_sprite;
    };
}