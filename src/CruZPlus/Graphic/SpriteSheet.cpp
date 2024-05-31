#include "SpriteSheet.h"

#include <SFML/System/Vector2.hpp>

#include "CruZPlus/TextureManager.h"

namespace CruZ
{
SpriteSheet::SpriteSheet(sf::Sprite &sprite, int sliceW, int sliceH) : m_sliceW(sliceW), m_sliceH(sliceH)
{
    m_sprite = &sprite;
    m_rect = sprite.getTextureRect();
}

void SpriteSheet::slice(int index)
{
    sf::Vector2i location{};
    sf::Vector2i size{};

    size.x = m_sprite->getTextureRect().width / m_sliceW;
    size.y = m_sprite->getTextureRect().height / m_sliceH;

    location.x = index % m_sliceW * size.x;
    location.y = index / m_sliceW * size.y;

    m_rect = {location, size};
}

void SpriteSheet::render(sf::RenderWindow &window, const sf::Vector2f &coord)
{
    auto old_origin = m_sprite->getOrigin();
    auto old_rect = m_sprite->getTextureRect();
    auto old_position = m_sprite->getPosition();
    {
        m_sprite->setOrigin({m_rect.width / 2.0f, m_rect.height / 2.0f});
        m_sprite->setTextureRect(m_rect);
        m_sprite->setPosition({coord.x, -coord.y});

        window.draw(*m_sprite);
    }
    m_sprite->setPosition(old_position);
    m_sprite->setOrigin(old_origin);
    m_sprite->setTextureRect(old_rect);
}

sf::Sprite *SpriteSheet::getSprite()
{
    return m_sprite;
}
} // namespace CruZ
