#ifndef CMAKESFMLPROJECT_CUSTOMSHAPE_HPP
#define CMAKESFMLPROJECT_CUSTOMSHAPE_HPP

#include <SFML/Graphics/Shape.hpp>
#include <vector>


namespace sfcustom
{
    class CustomShape : public sf::Shape
    {
        private:
            std::vector <sf::Vector2f> positions;



        public:
            CustomShape(sf::Vector2f);

            void setPoint(sf::Vector2f position);

            std::size_t getPointCount() const;
            sf::Vector2f getPoint(std::size_t index) const;
    };
}


#endif //CMAKESFMLPROJECT_CUSTOMSHAPE_HPP
