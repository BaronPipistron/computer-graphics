#include <cmath>

#include <SFML/Graphics.hpp>
#include "include/TextInputField.h"

const uint32_t APP_WINDOW_WIDTH = 1440;
const uint32_t APP_WINDOW_HEIGHT = 800;

const uint32_t WINDOW_LEFT_SIDE_WIDTH = 300;
const uint32_t WINDOW_RIGHT_SIDE_WIDTH = APP_WINDOW_WIDTH - WINDOW_LEFT_SIDE_WIDTH;

struct Position {
    int x;
    int y;
};

int main() {
    sf::RenderWindow appWindow({APP_WINDOW_WIDTH, APP_WINDOW_HEIGHT}, "Line Drawer");

    sf::RectangleShape leftSide(sf::Vector2f(WINDOW_LEFT_SIDE_WIDTH, APP_WINDOW_HEIGHT));
    leftSide.setFillColor(sf::Color::White);

    sf::RectangleShape rightSide(sf::Vector2f(WINDOW_RIGHT_SIDE_WIDTH, APP_WINDOW_HEIGHT));
    rightSide.setFillColor(sf::Color::Black);

    sf::Font font;
    font.loadFromFile("./common/fonts/arial/arialmt.ttf");

    TextInputField x1_input(1150, 20, 5, "x_1", font);
    TextInputField y1_input(1150, 50, 5, "y_1", font);

    TextInputField x2_input(1300, 20, 5, "x_2", font);
    TextInputField y2_input(1300, 50, 5, "y_2", font);

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(0.f, 0.f)),
        sf::Vertex(sf::Vector2f(0.f, 0.f))
    };

    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;

    sf::CircleShape circle1(7.f);
    circle1.setFillColor(sf::Color::Black);
    circle1.move(100.f, 200.f);

    sf::CircleShape circle2(7.f);
    circle2.setFillColor(sf::Color::Black);
    circle2.move(400.f, 500.f);

    sf::CircleShape* selected1 = nullptr;
    sf::CircleShape* selected2 = nullptr;

    Position oldMouseCords = {0 , 0};

    sf::Text inclinationAngleLabel("Inclination Angle", font, 20);
    sf::Text inclinationAngle("0", font, 20);

    inclinationAngleLabel.setPosition(1150, 90);
    inclinationAngleLabel.setFillColor(sf::Color::Black);

    inclinationAngle.setPosition(1330, 90);
    inclinationAngle.setFillColor(sf::Color::Black);

    sf::Clock clock;
    
    sf::Text clockText("", font, 20);
    clockText.setPosition(1150, 120);
    clockText.setFillColor(sf::Color::Black);

    while (appWindow.isOpen()) {

        for (sf::Event event; appWindow.pollEvent(event); ) {
            if (event.type == sf::Event::Closed) {
                appWindow.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto mouseButton = event.mouseButton;

                    if (selected1 == nullptr) {
                        if (circle1.getGlobalBounds().contains(mouseButton.x, mouseButton.y)) {
                            oldMouseCords = {mouseButton.x, mouseButton.y};
                            selected1 = &circle1;
                        }
                    } 
                    
                    if (selected2 == nullptr) {
                        if (circle2.getGlobalBounds().contains(mouseButton.x, mouseButton.y)) {
                            oldMouseCords = {mouseButton.x, mouseButton.y};
                            selected2 = &circle2;
                        }
                    }
                }
            } else if (event.type == sf::Event::MouseButtonReleased) {
                auto mousePosition = sf::Mouse::getPosition(appWindow);

                x1_input.setFocus(false);
                y1_input.setFocus(false);

                x2_input.setFocus(false);
                y2_input.setFocus(false);

                if (x1_input.contains(sf::Vector2f(mousePosition))) {
                    x1_input.setFocus(true);
                } else if (y1_input.contains(sf::Vector2f(mousePosition))) {
                    y1_input.setFocus(true);
                } else if (x2_input.contains(sf::Vector2f(mousePosition))) {
                    x2_input.setFocus(true);
                } else if (y2_input.contains(sf::Vector2f(mousePosition))) {
                    y2_input.setFocus(true);
                }

                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (selected1) {
                        selected1 = nullptr;
                    } else if (selected2) {
                        selected2 = nullptr;
                    }
                }
            } else if (event.type == sf::Event::MouseMoved) {
                auto mouseMoved = event.mouseMove;

                if (circle1.getGlobalBounds().contains(mouseMoved.x, mouseMoved.y)) {
                    circle1.setFillColor(sf::Color::Red);
                } else if (circle2.getGlobalBounds().contains(mouseMoved.x, mouseMoved.y)) {
                    circle2.setFillColor(sf::Color::Red);
                } else {
                    circle1.setFillColor(sf::Color::Black);
                    circle2.setFillColor(sf::Color::Black);
                }

                Position diff = {
                    mouseMoved.x - oldMouseCords.x,
                    mouseMoved.y - oldMouseCords.y
                };

                oldMouseCords = {
                    mouseMoved.x,
                    mouseMoved.y
                };

                if (5 < mouseMoved.x && mouseMoved.x < WINDOW_RIGHT_SIDE_WIDTH - 10 &&
                    5 < mouseMoved.y && mouseMoved.y < APP_WINDOW_HEIGHT - 10) {

                    if (selected1) {
                        selected1->move(diff.x, diff.y);
                        line[0] = sf::Vertex(circle1.getPosition());
                        line[0].color = sf::Color::Red;

                        x1_input.setInput(
                            std::to_string(
                                static_cast<uint32_t>(circle1.getPosition().x)
                            ));

                        y1_input.setInput(
                            std::to_string(
                                static_cast<uint32_t>(circle1.getPosition().y)
                            ));
                    } else if (selected2) {
                        selected2->move(diff.x, diff.y);
                        line[1] = sf::Vertex(circle2.getPosition());
                        line[1].color = sf::Color::Red;

                        x2_input.setInput(
                            std::to_string(
                                static_cast<uint32_t>(circle2.getPosition().x)
                            ));

                        y2_input.setInput(
                            std::to_string(
                                static_cast<uint32_t>(circle2.getPosition().y)
                            ));
                    }    


                    int incliationAngleDegrees = (line[0].position.x == line[1].position.x) ?
                                                   0 : std::atan(
                                                            (line[1].position.y - line[0].position.y) /
                                                            (line[1].position.x - line[0].position.x)
                                                        ) * (180 / M_PI);

                    inclinationAngle.setString(std::to_string(incliationAngleDegrees));
                }  
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    float x1, y1;
                    float x2, y2;

                    try {
                        x1 = std::stoi(x1_input.getInput());
                        y1 = std::stoi(y1_input.getInput());

                        x2 = std::stoi(x2_input.getInput());
                        y2 = std::stoi(y2_input.getInput());

                        if (1 < x1 && x1 < WINDOW_RIGHT_SIDE_WIDTH - 1 &&
                            1 < x2 && x2 < WINDOW_RIGHT_SIDE_WIDTH - 1 &&
                            1 < y1 && y1 < APP_WINDOW_HEIGHT - 1 &&
                            1 < y2 && y2 < APP_WINDOW_HEIGHT - 1) {

                            line[0] = sf::Vertex({x1, y1});
                            line[0].color = sf::Color::Red;

                            line[1] = sf::Vertex({x2, y2});
                            line[1].color = sf::Color::Red;

                            sf::Vector2f circle1_old_pos = circle1.getPosition();
                            sf::Vector2f circle2_old_pos = circle2.getPosition();

                            circle1.setPosition(x1, y1);
                            circle1.setFillColor(sf::Color::Green);

                            circle2.setPosition(x2, y2);
                            circle2.setFillColor(sf::Color::Green);

                            int incliationAngleDegrees = (x1 == x2) ?
                                                            0 : std::atan((y2 - y1) / (x2 - x1)) * (180 / M_PI);

                            inclinationAngle.setString(std::to_string(incliationAngleDegrees));
                        }
                    } catch (...) {
                        // do noothing, to ignore incorrect input
                    }
                }
            }

            x1_input.handleInput(event);
            y1_input.handleInput(event);

            x2_input.handleInput(event);
            y2_input.handleInput(event);
        }

        float elapsedTime = clock.getElapsedTime().asSeconds();
        clockText.setString("Time of work " + std::to_string(static_cast<int>(elapsedTime)) + " seconds");

        appWindow.clear(sf::Color::White);

        appWindow.draw(leftSide);
        appWindow.draw(rightSide);

        appWindow.draw(x1_input);
        appWindow.draw(y1_input);

        appWindow.draw(x2_input);
        appWindow.draw(y2_input);

        appWindow.draw(line, 2, sf::Lines);
        appWindow.draw(circle1);
        appWindow.draw(circle2);

        appWindow.draw(inclinationAngleLabel);
        appWindow.draw(inclinationAngle);

        appWindow.draw(clockText);

        appWindow.display();
    }

    return 0;
}