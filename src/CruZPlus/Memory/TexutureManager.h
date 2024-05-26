#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

namespace CruZ
{
    class TextureManager
    {
    public:
        sf::Texture *get(const char *);
        ~TextureManager();

    private:
        std::unordered_map<std::string, sf::Texture *> m_textures;
    };
}
