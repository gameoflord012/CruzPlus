#pragma once

#include "Instances.h"
#include <SFML/Window/Keyboard.hpp>

namespace sf
{
class Event;
}

namespace CruZ
{
class Input
{
  public:
    void processEvent(sf::Event &);
    void updateInput();
    bool isKeyJustPressed(sf::Keyboard::Key);
    bool isKeyPressed(sf::Keyboard::Key);

  private:
    bool m_keyStateChanged{};
    bool m_keyState[sf::Keyboard::KeyCount]{};
    bool m_lastKeyState[sf::Keyboard::KeyCount]{};
};
} // namespace CruZ