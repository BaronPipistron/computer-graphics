#include <SFML/Graphics.hpp>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800.f, 800.f), "Anti-Aliasing");

    // circle
    sf::CircleShape circle(75.f);
    circle.setFillColor(sf::Color::Blue);
    circle.move(15.f, 15.f);

    // triangle
    sf::CircleShape triangle(75.f, 3);
    triangle.setPosition(150.f, 15.f);
    triangle.setFillColor(sf::Color::Black);

    // square
    sf::CircleShape square(75.f, 4);
    square.setPosition(300.f, 15.f);
    square.setFillColor(sf::Color::Red);

    // pentagon
    sf::CircleShape pentagon(75.f, 5);
    pentagon.setPosition(450.f, 15.f);
    pentagon.setFillColor(sf::Color::Cyan);

    // octagon
    sf::CircleShape octagon(75.f, 8);
    octagon.setPosition(600.f, 15.f);
    octagon.setFillColor(sf::Color::Magenta);

    //rectangle
    sf::RectangleShape rectangle(sf::Vector2f(140.f, 70.f));
    rectangle.setOutlineThickness(15.f);
    rectangle.setOutlineColor(sf::Color::Magenta);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.move(15.f, 180.f);

    // convex polygon
    sf::ConvexShape convex_polygon;
    convex_polygon.setPointCount(5);

    convex_polygon.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex_polygon.setPoint(1, sf::Vector2f(150.f, 15.f));
    convex_polygon.setPoint(2, sf::Vector2f(130.f, 100.f));
    convex_polygon.setPoint(3, sf::Vector2f(30.f, 110.f));
    convex_polygon.setPoint(4, sf::Vector2f(10.f, 45.f));

    convex_polygon.move(170.f, 180.f);

    // line with width
    sf::RectangleShape line_with_width(sf::Vector2f(130.f, 5.f));
    line_with_width.rotate(135.f);
    line_with_width.setFillColor(sf::Color::Black);
    line_with_width.move(500.f, 300.f);

    // line without width
    // создаем как массив вершин типа Vertex
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(400.f, 150.f)),
        sf::Vertex(sf::Vector2f(650.f, 350.f))
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

        window.draw(circle);
        window.draw(triangle);
        window.draw(square);
        window.draw(pentagon);
        window.draw(octagon);

        window.draw(rectangle);

        window.draw(convex_polygon);

        window.draw(line_with_width);
        window.draw(line, 2, sf::Lines);

        window.display();
    }

    return 0;
}