#include "EditorUI.h"

namespace CruZ
{
EditorUI::EditorUI(/* args */)
{
}

void EditorUI::render(sf::RenderWindow &window)
{
    sf::Vertex line[2];
    line[0].position = {0, 10};
    line[0].color = sf::Color::White;
    line[1].position = {0, -10};
    line[1].color = sf::Color::White;
    window.draw(line, 2, sf::PrimitiveType::Lines);
    line[0].position = {10, 0};
    line[0].color = sf::Color::White;
    line[1].position = {-10, 0};
    line[1].color = sf::Color::White;
    window.draw(line, 2, sf::PrimitiveType::Lines);
}

EditorUI::~EditorUI()
{
}
} // namespace CruZ