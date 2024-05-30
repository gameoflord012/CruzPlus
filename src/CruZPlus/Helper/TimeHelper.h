#pragma once

#include <SFML/System/Time.hpp>
#include <chrono>

namespace CruZ
{
namespace Helper
{
static constexpr sf::Time convertToTime(float seconds)
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<float>(seconds));
}
} // namespace Helper
} // namespace CruZ