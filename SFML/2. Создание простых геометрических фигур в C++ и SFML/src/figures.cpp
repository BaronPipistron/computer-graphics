#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 400), "Figures");

    // circle
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);
    circle.move(15.f, 15.f);

    // triangle
    sf::CircleShape triangle(50.f, 3);
    triangle.setPosition(125.f, 15.f);
    triangle.setFillColor(sf::Color::Black);

    // square
    sf::CircleShape square(50.f, 4);
    square.setPosition(250.f, 15.f);
    square.setFillColor(sf::Color::Red);

    // pentagon
    sf::CircleShape pentagon(50.f, 5);
    pentagon.setPosition(375.f, 15.f);
    pentagon.setFillColor(sf::Color::Cyan);

    // octagon
    sf::CircleShape octagon(50.f, 8);
    octagon.setPosition(500.f, 15.f);
    octagon.setFillColor(sf::Color::Magenta);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(250, 220, 100, 0));

        window.draw(circle);
        window.draw(triangle);
        window.draw(square);
        window.draw(pentagon);
        window.draw(octagon);

        window.display();
    }

    return 0;
}