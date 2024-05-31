#include "AnimatedSprite.h"

#include "SpriteSheet.h"

namespace CruZ
{
AnimatedSprite::AnimatedSprite(SpriteSheet &spriteSheet) : m_spriteSheet(&spriteSheet)
{
}

void AnimatedSprite::update(float deltaTime)
{
    if(m_totalTime <= 0) return;

    m_currentTime += deltaTime;
    if(m_currentTime > m_totalTime) m_currentTime -= m_totalTime;
    float ratio = m_currentTime / m_totalTime;
    
    m_spriteSheet->slice(int(m_spriteSheet->m_sliceW * m_spriteSheet->m_sliceH * ratio));
}

void AnimatedSprite::render(sf::RenderWindow &window, const sf::Vector2f &coord)
{
    m_spriteSheet->render(window, coord);
}

void AnimatedSprite::setTotalTime(float totalTime)
{
    m_totalTime = totalTime;
}
} // namespace CruZ