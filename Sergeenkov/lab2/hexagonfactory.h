#ifndef HEXAGONFACTORY_H
#define HEXAGONFACTORY_H

#include "shape.h"
#include "shapefactory.h"
#include "hexagon.h"
#include <vector>

class HexagonFactory : public ShapeFactory
{
public:
    Shape* create(Point poin1, Point point2, Point point3, Point point4, Point point5, Point point6, std::string color);
    Shape* create(Point center, double distance, std::string color);
};

#endif // HEXAGONFACTORY_H
