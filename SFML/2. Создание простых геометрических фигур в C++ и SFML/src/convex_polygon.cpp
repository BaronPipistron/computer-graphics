#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500.f, 500.f), "Convex Polygon");

    // convex polygon
    sf::ConvexShape convex_polygon;
    convex_polygon.setPointCount(5);

    convex_polygon.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex_polygon.setPoint(1, sf::Vector2f(150.f, 15.f));
    convex_polygon.setPoint(2, sf::Vector2f(130.f, 120.f));
    convex_polygon.setPoint(3, sf::Vector2f(100.f, 55.f));
    convex_polygon.setPoint(4, sf::Vector2f(10.f, 30.f));

    // convex_polygon.setOutlineThickness(15.f);
    // convex_polygon.setOutlineColor(sf::Color::Red);
    
    convex_polygon.setFillColor(sf::Color::Magenta);

    convex_polygon.move(15.f, 50.f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(250, 220, 100, 0));
        window.draw(convex_polygon);
        window.display();
    }

    return 0;
}