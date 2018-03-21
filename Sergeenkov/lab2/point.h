#include <iostream>

#ifndef POINT_H
#define POINT_H


class Point
{
public:

    Point(double x = 0, double y = 0);

    double X();
    double Y();

    void setX(double x);
    void setY(double y);

    void move(Point point);
    void rotate(double angle, Point center);
    void scale(double factor, Point center);

     friend std::ostream& operator<<(std::ostream& os, Point& point);

private:
    double m_x;
    double m_y;
};

#endif // POINT_H
