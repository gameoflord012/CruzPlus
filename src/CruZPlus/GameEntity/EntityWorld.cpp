#include "EntityWorld.h"

namespace CruZ
{
    void EntityWorld::updateAll(float deltaTime)
    {
        for (size_t i = 0; i < m_entities.size(); i++)
        {
            m_entities[i]->update(deltaTime);
        }
    }

    void EntityWorld::renderAll(sf::RenderWindow &window)
    {
        for (size_t i = 0; i < m_entities.size(); i++)
        {
            m_entities[i]->render(window);
        }
    }

    void EntityWorld::addEntity(Entity &entity)
    {
        auto it = std::find(m_entities.begin(), m_entities.end(), &entity);

        if (it != m_entities.end())
        {
            assert(false && "already added");
        }

        m_entities.push_back(&entity);

        entity.m_world = this;
    }
    
    void EntityWorld::removeEntity(Entity &entity)
    {
        auto it = std::find(m_entities.begin(), m_entities.end(), &entity);
        if (it != m_entities.end())
            m_entities.erase(it);
    }
}