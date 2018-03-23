#include <string>
#include <iostream>
#include "point.h"

#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
public:
    virtual void move(Point point) = 0;
    virtual void rotate(double angle) = 0;
    virtual void scale(double factor) = 0;
    virtual void print(std::ostream& os);
    virtual Point getCenter() = 0;

    virtual void affineTransformation(double affineMatrix[2][2]) = 0;

    static int count;

    friend std::ostream& operator<<(std::ostream& os, Shape& shape);

    void setColor(std::string color);
    std::string getColor();

    // Виртуальный деструктор для предотвращения undefined behaviour
    virtual ~Shape() { std::cout << "Shape destroyed" << std::endl; };

protected:
    std::string m_color;
    int id;
};

#endif // SHAPE_H
