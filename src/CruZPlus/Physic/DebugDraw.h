#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <box2d/box2d.h>
#include <cmath>

namespace CruZ
{
class DebugDraw : public b2Draw
{
  public:
    DebugDraw(sf::RenderWindow &);

    void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);

    void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);

    void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color);

    void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color);

    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color);

    void DrawTransform(const b2Transform &xf);

    void DrawPoint(const b2Vec2 &p, float size, const b2Color &color);

    constexpr static sf::Color GLColorToSFML(const b2Color &color, std::uint8_t alpha = 255)
    {
        return sf::Color(static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255),
                         static_cast<std::uint8_t>(color.b * 255), alpha);
    }

    constexpr static sf::Vector2f B2VecToSFVec(const b2Vec2 &vector, bool scaleToPixels = true)
    {
        return sf::Vector2f(vector.x * (scaleToPixels ? PIXEL_TO_COORD_RATIO : 1.f),
                            -vector.y * (scaleToPixels ? PIXEL_TO_COORD_RATIO : 1.f));
    }

  private:
    static constexpr float PIXEL_TO_COORD_RATIO = 1.f;
    sf::RenderWindow *m_window;
};
} // namespace CruZ