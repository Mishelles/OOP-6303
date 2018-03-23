#include <iostream>
#include <cmath>

#include "rectangle.h"

Rectangle::Rectangle(Point point1, Point point2, Point point3, Point point4, std::string color)
    : m_point1(point1)
    , m_point2(point2)
    , m_point3(point3)
    , m_point4(point4)
{
    m_color = color;
    std::cout << "Rectangle created" << std::endl;
    id = ++count;
}

Rectangle::Rectangle(Point point, double width, double height, std::string color)
    : m_point1(point)
{
    m_color = color;

    m_point2.setX(m_point1.X() + width);
    m_point2.setY(m_point1.Y());

    m_point3.setX(m_point2.X());
    m_point3.setY(m_point2.Y() + height);

    m_point4.setX(m_point1.X());
    m_point4.setY(m_point1.Y() + height);

    std::cout << "Rectangle created" << std::endl;
    id = ++count;
}

Point Rectangle::getCenter()
{

    double x = (m_point3.X() + m_point1.X()) / 2;
    double y = (m_point3.Y() + m_point1.Y()) / 2;

    return Point(x, y);
}

void Rectangle::move(Point point)
{
    Point center = this->getCenter();

    Point move_point(point.X() - center.X(), point.Y() - center.Y());

    m_point1.move(move_point);
    m_point2.move(move_point);
    m_point3.move(move_point);
    m_point4.move(move_point);

}

void Rectangle::rotate(double angle)
{
    Point center = this->getCenter();

    m_point1.rotate(angle, center);
    m_point2.rotate(angle, center);
    m_point3.rotate(angle, center);
    m_point4.rotate(angle, center);
}

void Rectangle::scale(double factor)
{
    Point center = this->getCenter();

    m_point1.scale(factor, center);
    m_point2.scale(factor, center);
    m_point3.scale(factor, center);
    m_point4.scale(factor, center);
}

void Rectangle::print(std::ostream& os)
{
    Point center = this->getCenter();
    os << "-------------------------------------------" << std::endl;
    os << "My type is: Rectangle" << std::endl;
    os << "My coordinates are:" << std::endl;
    os << m_point1 << "\t" << m_point2 << std::endl;
    os << m_point3 << "\t" << m_point4 << std::endl;
    os << "My center is: " << center << std::endl;
    os << "My ID is: " << id << std::endl;
    os << "My color is: " << m_color << std::endl;
    os << "-------------------------------------------" << std::endl;

}

void Rectangle::affineTransformation(double affineMatrix[][2])
{
    Point center = this->getCenter();

    m_point1.affineTransformation(affineMatrix, center);
    m_point2.affineTransformation(affineMatrix, center);
    m_point3.affineTransformation(affineMatrix, center);
    m_point4.affineTransformation(affineMatrix, center);
}
