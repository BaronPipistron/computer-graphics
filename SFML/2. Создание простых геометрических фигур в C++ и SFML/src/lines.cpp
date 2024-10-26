#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(300.f, 300.f), "Lines");

    // line with width
    sf::RectangleShape line_with_width(sf::Vector2f(130.f, 5.f));
    line_with_width.rotate(135.f);
    line_with_width.setFillColor(sf::Color::Black);
    line_with_width.move(150.f, 50.f);

    // line without width
    // создаем как массив вершин типа Vertex
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(170.f, 20.f)),
        sf::Vertex(sf::Vector2f(250.f, 70.f))
    };

    line->color = sf::Color::Cyan;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(250, 220, 100, 0));
        window.draw(line_with_width);
        window.draw(line, 2, sf::Lines);
        window.display();
    }

    return 0;
}