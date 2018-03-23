#include "shape.h"
#include "point.h"

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H


class Parallelogram : public Shape
{
public:

    // Параллелограм по четырём точкам
    Parallelogram(Point point1, Point point2, Point point3, Point point4, std::string color);

    void move(Point point);
    void rotate(double angle);
    void scale(double factor);
    void print(std::ostream& os);
    Point getCenter();

    void affineTransformation(double affineMatrix[][2]);

    virtual ~Parallelogram() { std::cout << "Parallelogram destroyed" << std::endl; };

protected:

    Point m_point1;
    Point m_point2;
    Point m_point3;
    Point m_point4;
};

#endif // PARALLELOGRAM_H
