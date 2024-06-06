#pragma once

#include <chrono>
#include <vector>

namespace sf
{
class View;
class RenderWindow;
}

class b2World;

namespace CruZ
{
class EntityWorld;
class Input;
class TextureManager;
class BodyFactory;
class DebugDraw;
class ContactListenerHandler;

class Game
{
  public:
    Game();
    ~Game();

    void run();
    
    b2World *getB2World();
    EntityWorld *getEntityWorld();
    sf::View *getView();

  private:
    sf::RenderWindow *m_window{};
    sf::View *m_view{};
    TextureManager *m_textureManager{};
    BodyFactory *m_bodyFactory{};
    EntityWorld *m_entityWorld{};
    b2World *m_b2World{};
    Input *m_input{};
    DebugDraw *m_debugDraw{};
    ContactListenerHandler *m_contactListener;
};
} // namespace CruZ

#include "Instances.h"