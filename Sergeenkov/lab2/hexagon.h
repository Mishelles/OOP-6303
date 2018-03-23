#include "shape.h"
#include "point.h"

#ifndef HEXAGON_H
#define HEXAGON_H

class Hexagon : public Shape
{
public:

    // Шестиугольник по 6 точкам
    Hexagon(Point point1, Point point2, Point point3, Point point4, Point point5, Point point6, std::string color);

    // Шестиугольник по центральной точке и расстоянию до вершин
    Hexagon(Point center, double distance, std::string color);

    void move(Point point);
    void rotate(double angle);
    void scale(double factor);
    void print(std::ostream& os);
    Point getCenter();

    void affineTransformation(double affineMatrix[][2]);

    virtual ~Hexagon() { std::cout << "Hexagon destroyed" << std::endl; };

protected:
    Point m_point1;
    Point m_point2;
    Point m_point3;
    Point m_point4;
    Point m_point5;
    Point m_point6;
};

#endif // HEXAGON_H
