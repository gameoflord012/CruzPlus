#pragma once

#include <unordered_set>
#include <vector>

#include "Entity.h"
#include "IUpdate.h"
#include "IRender.h"

namespace CruZ
{
    class EntityWorld
    {
    public:
        void updateAll(float);
        void renderAll(sf::RenderWindow &);
        void addEntity(Entity &);
        void removeEntity(Entity &);
    private:
        std::vector<Entity*> m_entities;
    };
}