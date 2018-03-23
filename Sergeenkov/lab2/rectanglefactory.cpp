#include <cmath>
#include "rectanglefactory.h"

Shape* RectangleFactory::create(Point point1, Point point2, Point point3, Point point4, std::string color)
{
    // Проверка на равенство диагоналей
    double d1 = sqrt(pow((point2.X() - point4.X()), 2) + pow((point2.Y() - point4.Y()), 2));
    double d2 = sqrt(pow((point1.X() - point3.X()), 2) + pow((point1.Y() - point3.Y()), 2));

    if ((d1 != d2) || (d1 == 0)) {
        std::cout << "По заданным точкам невозможно построить прямоугольник" << std::endl;
        return nullptr;
    }

    Shape* rectangle = new Rectangle(point1, point2, point3, point4, color);
    m_objects.push_back(rectangle);
    return rectangle;
}

Shape* RectangleFactory::create(Point point, double width, double height, std::string color)
{
    if ((width == 0) || (height == 0)) {
        std::cout << "Задана нулевая ширина или высота" << std::endl;
        return nullptr;
    }

    Shape* rectangle = new Rectangle(point, width, height, color);
    m_objects.push_back(rectangle);
    return rectangle;
}

int Shape::count = 0;
