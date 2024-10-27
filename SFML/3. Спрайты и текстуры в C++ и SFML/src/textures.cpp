#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Textures");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Texture texture;
        texture.loadFromFile("./kover.png");

        texture.setSmooth(true);

        sf::Sprite sprite(texture);
        sprite.scale(sf::Vector2f(2.5f, 2.5f));
        sprite.setColor(sf::Color::Cyan);

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}