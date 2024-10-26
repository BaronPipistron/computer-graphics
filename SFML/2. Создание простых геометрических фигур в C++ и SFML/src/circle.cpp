#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Circle");

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(230, 0, 220));

    // добавляем контур нашему кругу
    circle.setOutlineThickness(15.f);
    circle.setOutlineColor(sf::Color(80, 220, 50, 100));

    // двигаем наш круг, чтобы он не выходил за границы окна
    circle.move(200.f, 200.f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(250, 220, 100, 0));
        window.draw(circle);
        window.display();
    }

    return 0;
}