#include "Entity.h"
#include "EntityWorld.h"

namespace CruZ
{
    void Entity::update(float)
    {
    }

    void Entity::render(sf::RenderWindow &)
    {
    }

    EntityWorld *Entity::getEntityWorld()
    {
        return m_world;
    }

    Entity::~Entity()
    {
        m_world->removeEntity(*this);
    }
}
