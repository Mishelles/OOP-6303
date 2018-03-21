#include "shape.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle : public Shape
{
public:
    // Конструктор по четырём точкам
    Rectangle(Point point1, Point point2, Point point3, Point point4, std::string color);

    // Конструктор по точке, ширине и высоте
    Rectangle(Point point, double width, double height, std::string color);

    void move(Point point);
    void rotate(double angle);
    void scale(double factor);
    void print(std::ostream& os);
    Point getCenter();

    virtual ~Rectangle() { std::cout << "Rectangle destroyed" << std::endl; };

protected:
    Point m_point1;
    Point m_point2;
    Point m_point3;
    Point m_point4;
};

#endif // RECTANGLE_H
