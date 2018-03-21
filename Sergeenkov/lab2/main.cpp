#include <iostream>
#include "rectanglefactory.h"
#include "shapefactory.h"
#include "parallelogramfactory.h"
#include "hexagonfactory.h"
#include "point.h"

int main()
{
    // Создаём фабрики
    RectangleFactory rec_factory;
    ParallelogramFactory par_factory;
    HexagonFactory hex_factory;

    // С помощью фабрик создаём объекты
    // Нам не нужно беспокоиться об освобождении памяти, занимаемой объектами,
    // так как фабрика при своём уничтожении освобождает память за своими объектами
    Shape* rec = rec_factory.create(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10), "purple");
    Shape* hex = hex_factory.create(Point(0, 0), 10, "red");
    Shape* par = par_factory.create(Point(100, 100), Point(200, 100), Point(150, 50), Point(50, 50), "blue");

    // Test Ractangle

    std::cout << "***Test Rectangle***" << std::endl;

    std::cout << *rec << std::endl;

    std::cout << "Coloring..." << std::endl;
    rec->setColor("green");
    std::cout << *rec << std::endl;

    std::cout << "Moving..." << std::endl;
    rec->move(Point(30, 31));
    std::cout << *rec << std::endl;

    std::cout << "Scaling..." << std::endl;
    rec->scale(2);
    std::cout << *rec << std::endl;

    std::cout << "Rotating..." << std::endl;
    rec->rotate(6.28);
    std::cout << *rec << std::endl;

    // Test Parallelogram

    std::cout << "***Test Parallelogram***" << std::endl;

    std::cout << *par << std::endl;

    std::cout << "Coloring..." << std::endl;
    par->setColor("green");
    std::cout << *par << std::endl;

    std::cout << "Moving..." << std::endl;
    par->move(Point(30, 31));
    std::cout << *par << std::endl;

    std::cout << "Scaling..." << std::endl;
    par->scale(2);
    std::cout << *par << std::endl;

    std::cout << "Rotating..." << std::endl;
    par->rotate(6.28);
    std::cout << *par << std::endl;

    // Test Hexagon

    std::cout << "***Test Hexagon***" << std::endl;

    std::cout << *hex << std::endl;

    std::cout << "Coloring..." << std::endl;
    hex->setColor("green");
    std::cout << *hex << std::endl;

    std::cout << "Moving..." << std::endl;
    hex->move(Point(30, 31));
    std::cout << *hex << std::endl;

    std::cout << "Scaling..." << std::endl;
    hex->scale(2);
    std::cout << *hex << std::endl;

    std::cout << "Rotating..." << std::endl;
    hex->rotate(6.28);
    std::cout << *hex << std::endl;

    ShapeFactory factory;

    return 0;
}
