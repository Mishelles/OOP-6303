#include "shapefactory.h"
#include "parallelogram.h"
#include <vector>

#ifndef PARALLELOGRAMFACTORY_H
#define PARALLELOGRAMFACTORY_H


class ParallelogramFactory : public ShapeFactory
{
public:
    Shape* create(Point point1, Point point2, Point point3, Point point4, std::string color);
};

#endif // PARALLELOGRAMFACTORY_H
