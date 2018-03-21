#include "rectangle.h"
#include "shapefactory.h"
#include <vector>

#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H


class RectangleFactory : public ShapeFactory
{
public:
    Shape* create(Point point1, Point point2, Point point3, Point point4, std::string color);
    Shape* create(Point point, double width, double height, std::string color);
};

#endif // RECTANGLEFACTORY_H
