#include "Board.h"

Board::Board(/* args */)
{
}

void Board::render(sf::RenderWindow& window)
{
    sf::Vertex line[2];
    line[0].position = {0, 0};
    line[0].color = sf::Color::White;
    line[1].position = {100, 100};
    line[1].color = sf::Color::White;
    window.draw(line, 2, sf::PrimitiveType::Lines);
}

Board::~Board()
{
}