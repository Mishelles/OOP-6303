#include "hexagonfactory.h"
#include <cmath>

Shape* HexagonFactory::create(Point point1, Point point2, Point point3, Point point4, Point point5, Point point6, std::string color)
{
    double line1 = sqrt(pow((point2.X() - point1.X()), 2) + pow((point2.Y() - point1.Y()), 2));
    double line2 = sqrt(pow((point3.X() - point2.X()), 2) + pow((point3.Y() - point2.Y()), 2));
    double line3 = sqrt(pow((point4.X() - point3.X()), 2) + pow((point4.Y() - point3.Y()), 2));
    double line4 = sqrt(pow((point5.X() - point4.X()), 2) + pow((point5.Y() - point4.Y()), 2));
    double line5 = sqrt(pow((point6.X() - point5.X()), 2) + pow((point6.Y() - point5.Y()), 2));
    double line6 = sqrt(pow((point1.X() - point6.X()), 2) + pow((point1.Y() - point6.Y()), 2));

    if (!((line1 == line2) &&
          (line1 == line3) &&
          (line1 == line4) &&
          (line1 == line5) &&
          (line1 == line6))) {
        std::cout << "По заданный точкам невозможно построить правильный шестиугольник!" << std::endl;
        return nullptr;
    }
    Shape* hexagon = new Hexagon(point1, point2, point3, point4, point5, point6, color);
    m_objects.push_back(hexagon);
    return hexagon;
}

Shape* HexagonFactory::create(Point center, double distance, std::string color)
{
    if (distance == 0) {
        std::cout << "Задан пустой шестиугольник!" << std::endl;
        return nullptr;
    }
    Shape* hexagon = new Hexagon(center, distance, color);
    m_objects.push_back(hexagon);
    return hexagon;
}
