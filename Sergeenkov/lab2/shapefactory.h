#include "shape.h"
#include <vector>

#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H


class ShapeFactory
{
public:
    ShapeFactory() { std::cout << "Factory created" << std::endl; }
    ~ShapeFactory();
protected:
    std::vector<Shape*> m_objects;
};

#endif // SHAPEFACTORY_H
