#include <SFML/Graphics.hpp>
#include "../Header Files/CustomShape.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(150, 50, 250));

    sfcustom::CustomShape custom(sf::Vector2f (0,0));

    // set a 10-pixel wide orange outline
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        //window.draw(shape);
        window.draw(custom);

        // end the current frame
        window.display();
    }

    return 0;
}