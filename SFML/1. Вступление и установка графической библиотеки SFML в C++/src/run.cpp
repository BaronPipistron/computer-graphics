#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Hello, SFML!");
    sf::RectangleShape shape(sf::Vector2f(500.f, 250.f));
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(250, 220, 100, 0));
        window.draw(shape);
        window.display();
    }

    return 0;
}