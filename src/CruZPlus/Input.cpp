#include "input.h"

#include <SFML/Window/Event.hpp>

namespace CruZ
{
void Input::processEvent(sf::Event &event)
{
    const auto *keyPressed = event.getIf<sf::Event::KeyPressed>();
    const auto *keyReleased = event.getIf<sf::Event::KeyReleased>();

    m_keyStateChanged |= keyPressed || keyReleased;

    if (keyPressed)
    {
        m_keyState[(size_t)keyPressed->code] = true;
    }

    if (keyReleased)
    {
        m_keyState[(size_t)keyReleased->code] = false;
    }
}

void Input::updateInput()
{
    if(m_keyStateChanged)
    {
        m_keyStateChanged = false;
    }
    else
    {
        memcpy(m_lastKeyState, m_keyState, sizeof m_keyState);
    }
}

bool Input::isKeyJustPressed(sf::Keyboard::Key key)
{
    return m_keyState[(int)key] && !m_lastKeyState[(int)key];
}

bool Input::isKeyPressed(sf::Keyboard::Key key)
{
    return m_keyState[(int)key];
}
} // namespace CruZ