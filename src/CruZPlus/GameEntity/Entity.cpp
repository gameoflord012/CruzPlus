#include "Entity.h"

namespace CruZ
{
    void Entity::update(float deltaTime)
    {
    }

    void Entity::render(sf::RenderWindow &window)
    {
    }

    EntityWorld *Entity::getEntityWorld()
    {
        return m_world;
    }

    class EntityWorld
    {
    public:
        void removeEntity(Entity &);
    };

    Entity::~Entity()
    {
        m_world->removeEntity(*this);
    }
}
