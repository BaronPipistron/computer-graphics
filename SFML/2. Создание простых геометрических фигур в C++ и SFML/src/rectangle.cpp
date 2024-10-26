#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(300.f, 300.f), "Rectangle");

    //rectangle
    sf::RectangleShape rectangle(sf::Vector2f(140.f, 70.f));
    rectangle.setOutlineThickness(15.f);
    rectangle.setOutlineColor(sf::Color::Magenta);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.move(50.f, 50.f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(250, 220, 100, 0));
        window.draw(rectangle);
        window.display();
    }

    return 0;
}