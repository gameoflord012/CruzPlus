#pragma once

#include <SFML/System/Vector2.hpp>
#include <box2d/b2_math.h>

namespace CruZ
{
constexpr sf::Vector2f convert(const b2Vec2 &v2)
{
    return {v2.x, v2.y};
}
} // namespace CruZ