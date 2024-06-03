#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

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
} // namespace CruZ

#include "CruZPlus/Instances.h"
