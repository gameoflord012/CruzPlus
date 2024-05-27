#pragma once

#include <SFML/Graphics.hpp>

#include <CruZPlus/GameEntity.h>

namespace CruZ
{
    class EditorUI : public Entity
    {
    public:
        EditorUI();
        void render(sf::RenderWindow &window);
        ~EditorUI();
    };
}
