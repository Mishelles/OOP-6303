#include "hexagon.h"
#include <cmath>

Hexagon::Hexagon(Point point1, Point point2, Point point3, Point point4, Point point5, Point point6, std::string color)
    : m_point1(point1)
    , m_point2(point2)
    , m_point3(point3)
    , m_point4(point4)
    , m_point5(point5)
    , m_point6(point6)
{
    m_color = color;
    std::cout << "Hexagon created" << std::endl;
}

Hexagon::Hexagon(Point center, double distance, std::string color)
{
    m_color = color;

    m_point1.setX(center.X() - distance);
    m_point1.setY(center.Y());

    m_point2.setX(m_point1.X() + distance / 2);
    m_point2.setY(m_point1.Y() - distance / 2);

    m_point3.setX(m_point2.X() + distance);
    m_point3.setY(m_point2.Y());

    m_point4.setX(m_point1.X() + distance * 2);
    m_point4.setY(m_point1.Y());

    m_point5.setX(m_point3.X());
    m_point5.setY(m_point3.Y() + distance * 2);

    m_point6.setX(m_point2.X());
    m_point6.setY(m_point2.Y() + distance * 2);

    std::cout << "Hexagon created" << std::endl;
}

void Hexagon::move(Point point)
{
    Point center = this->getCenter();

    Point move_point(point.X() - center.X(), point.Y() - center.Y());

    m_point1.move(move_point);
    m_point2.move(move_point);
    m_point3.move(move_point);
    m_point4.move(move_point);
    m_point5.move(move_point);
    m_point6.move(move_point);
}

void Hexagon::scale(double factor)
{
    Point center = this->getCenter();

    m_point1.scale(factor, center);
    m_point2.scale(factor, center);
    m_point3.scale(factor, center);
    m_point4.scale(factor, center);
    m_point5.scale(factor, center);
    m_point6.scale(factor, center);
}

void Hexagon::rotate(double angle)
{
    Point center = this->getCenter();

    m_point1.rotate(angle, center);
    m_point2.rotate(angle, center);
    m_point3.rotate(angle, center);
    m_point4.rotate(angle, center);
    m_point5.rotate(angle, center);
    m_point6.rotate(angle, center);
}

void Hexagon::print(std::ostream &os)
{
    Point center = this->getCenter();

    os << "-------------------------------------------" << std::endl;
    os << "My type is: Hexagon" << std::endl;
    os << "My color is: " << m_color << std::endl;
    os << "My center is: " << center << std::endl;
    os << "My coordinates are:" << std::endl;
    os << "\t" << m_point2 << "\t" << m_point3 << std::endl;
    os << m_point1 << "\t\t\t" << m_point4 << std::endl;
    os << "\t" << m_point6 << "\t" << m_point5 << std::endl;
    os << "-------------------------------------------" << std::endl;
}

Point Hexagon::getCenter()
{
    double x = (m_point1.X() + m_point4.X()) / 2;
    double y = (m_point1.Y() + m_point4.Y()) / 2;

    return Point(x, y);
}
