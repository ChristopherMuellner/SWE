#include "../Header Files/CustomShape.hpp"


sfcustom::CustomShape::CustomShape(sf::Vector2f position)
{
    positions.push_back(sf::Vector2f(10.0f, 10.0f));
    positions.push_back(sf::Vector2f(15.0f, 105.0f));
    positions.push_back(sf::Vector2f(100.0f, 20.0f));

    update();
}

std::size_t sfcustom::CustomShape::getPointCount() const
{
    return positions.size();
}


sf::Vector2f sfcustom::CustomShape::getPoint(std::size_t index) const
{
    return positions.at(index);
}


void sfcustom::CustomShape::setPoint(sf::Vector2f position)
{
    this->positions.push_back(position);
}