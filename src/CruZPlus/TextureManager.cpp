#include "TextureManager.h"

#include <cassert>

namespace CruZ
{
    sf::Texture *TextureManager::get(const char * textureFile)
    {
        sf::Texture *texture;

        if(m_textures.find(textureFile) == m_textures.end())
        {
            texture = new sf::Texture;
            assert(texture->loadFromFile(textureFile));
            m_textures[textureFile] = texture;
        }
        else
        {
            texture = m_textures[textureFile];
        }

        return texture;
    }

    TextureManager::~TextureManager()
    {
        for (const auto &it : m_textures)
        {
            delete it.second;
        }
    }
}
