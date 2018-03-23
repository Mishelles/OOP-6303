#include "point.h"
#include <iostream>
#include <cmath>

Point::Point(double x, double y)
    : m_x(x)
    , m_y(y)
{
//    std::cout << "New point object created. Coordinates: " << m_x << ":" << m_y << std::endl;
}

double Point::X()
{
    return m_x;
}

double Point::Y()
{
    return m_y;
}

void Point::setX(double x)
{
    m_x = x;
}

void Point::setY(double y)
{
    m_y = y;
}

void Point::move(Point point)
{
    m_x += point.X();
    m_y += point.Y();
}

void Point::rotate(double angle, Point center)
{
    m_x = center.X() + (m_x - center.X()) * cos(angle) - (m_y - center.Y()) * sin(angle);
    m_y = center.Y() + (m_y - center.Y()) * cos(angle) + (m_x - center.Y()) * sin(angle);
}

void Point::scale(double factor, Point center)
{
    m_x = m_x * factor + (1 - factor) * center.X();
    m_y = m_y * factor + (1 - factor) * center.Y();
}

std::ostream& operator<<(std::ostream& os, Point& point)
{
    os << "(" << point.X() << " ; " << point.Y() << ")";
    return os;
}

void Point::affineTransformation(double affineMatrix[][2], Point center)
{
    if(this->checkAffineMatrix(affineMatrix)) {
        m_x = m_x * affineMatrix[0][0] + m_y * affineMatrix[0][1] + center.X();
        m_y = m_x * affineMatrix[1][0] + m_y * affineMatrix[1][1] + center.Y();
    } else {
        std::cout << "Invalid Affine Matrix: Determinant == 0" << std::endl;
    }

}

bool Point::checkAffineMatrix(double matrix[][2])
{
    double det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    return (det != 0);
}
