## Круги
Для создания кругов используется класс `CircleShape`:
- конструктор данного класса принимает в качестве параметра радиус нашей будущей фигуры (например, `circle(50.f)`)
- закрасить фигуру можно с помощью метода `setFillColor()`, который похож на знакомый нам метод `window.clear()`
- для отображения круга в окне используется метод `window.draw()`

```cpp
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
```

Наша фигура может иметь контур. Для его создания используем метод `setOutlineThickness()`, а для задания цвета контура - `setOutlineColor()`

```cpp
// устанавливаем толщину контура круга
circle.setOutlineThickness(15.f);

// устанавливаем цвет контура и прозрачность
circle.setOutlineColor(sf::Color(80, 220, 50, 150));
```

Наш круг выходит за границы окна, а это не хорошо. Можно его немного подвинуть, в этом нам поможет метод `move()`

```cpp
circle.move(15, 15);
```

## Регулярные полигоны
Теперь можно перейти к отрисовке других фигур. 

На самом деле круг - это не совсем круг, а многоугольник с большим количеством вершин. У конструктора класса `CircleShape` есть еще и второй параметр (помимо радиуса), который отвечает за количество вершин у создаваемой фигуры, и по умолчанию он равен 30. Именно при значениях близких к 30, многоугольник становится мало отличимым от круга. 

Задавая этот параметр самостоятельно, мы можем получить другие геометрические элементы: 3 вершины - треугольник, 4 вершины - квадрат, 5 вершин - пятиугольник и т.д.

```cpp
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
```

## Выпуклые многоугольники
Создать выпуклый многоугольник можно через координаты его вершин. Для работы с такими фигурами имеется класс `ConvexShape`, который содержит методы `setPointCount()` - устанавливает количество вершин будущего многоугольника, и `setPoint()` - устанавливает сами вершины, принимая в качестве параметров порядковый номер (индекс) создаваемой вершины и ее координаты.

```cpp
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
```

Координаты вершин задаются в виде контейнера `Vector2f(a, b)`. *Данный контейнер - это простой шаблонный класс библиотеки SFML*

***Порядок, в котором определяются точки многоугольника очень важен. Все они должны быть определены либо по часовой стрелке, либо против часовой стрелки. Если будем определять их в несогласованном порядке, то форма многоугольника будет построена неправильно***

## Прямоугольники
Для работы с прямоугольниками используется класс `RectangleShape`, параметрами которого являются геометрические размеры фигуры - ширина и высота

```cpp
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
```

## Линии
Специального класса для работы с линиями в SFML нет. *Но он нам и не нужен. Ведь по сути линии - это те же прямоугольники, но не такие широкие.* Поэтому можем использовать ужен знакомый нам класс `RectangleShape`

Создадим линию с заданной толщиной

```cpp
	// line with width
    sf::RectangleShape line_with_width(sf::Vector2f(130.f, 5.f));
    line_with_width.rotate(135.f);
    line_with_width.setFillColor(sf::Color::Black);
    line_with_width.move(150.f, 50.f);
```

А теперь создадим линию с нулевой толщиной

```cpp
	// line without width
    // создаем как массив вершин типа Vertex
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(170.f, 20.f)),
        sf::Vertex(sf::Vector2f(250.f, 70.f))
    };

    line->color = sf::Color::Cyan;

	// ...
	window.draw(line, 2, sf::Lines);
```

## Сглаживание
Заметно, что у фигур очень острые края. Чтобы избавиться от этого дефекта надо включить сглаживание, которое сделает картингу более приятной глазу

В SFML нет возможности включить сглаживание для какой-то одной фигуры. Оно действует глобально для всего окна. При этом стоит учитывать, что возможность использовать сглаживание зависит от характеристик видеокарты и параметров видеодрайвера

```cpp
// устанавливаем 8-й уровень сглаживания
ContextSettings settings;
settings.antialiasingLevel = 8;
```