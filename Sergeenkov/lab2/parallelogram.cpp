#include "parallelogram.h"

Parallelogram::Parallelogram(Point point1, Point point2, Point point3, Point point4, std::string color)
    : m_point1(point1)
    , m_point2(point2)
    , m_point3(point3)
    , m_point4(point4)
{
    m_color = color;
    std::cout << "Parallelogram created" << std::endl;
    id = ++count;
}

void Parallelogram::move(Point point)
{
    Point center = this->getCenter();

    Point move_point(point.X() - center.X(), point.Y() - center.Y());

    m_point1.move(move_point);
    m_point2.move(move_point);
    m_point3.move(move_point);
    m_point4.move(move_point);

}

void Parallelogram::scale(double factor)
{
    Point center = this->getCenter();

    m_point1.scale(factor, center);
    m_point2.scale(factor, center);
    m_point3.scale(factor, center);
    m_point4.scale(factor, center);
}

void Parallelogram::rotate(double angle)
{
    Point center = this->getCenter();

    m_point1.rotate(angle, center);
    m_point2.rotate(angle, center);
    m_point3.rotate(angle, center);
    m_point4.rotate(angle, center);
}

void Parallelogram::print(std::ostream &os)
{
    Point center = this->getCenter();
    os << "-------------------------------------------" << std::endl;
    os << "My type is: Parallelogram" << std::endl;
    os << "My coordinates are:" << std::endl;
    os << m_point1 << "\t" << m_point2 << std::endl;
    os << m_point3 << "\t" << m_point4 << std::endl;
    os << "My ID is: " << id << std::endl;
    os << "My center is: " << center << std::endl;
    os << "My color is: " << m_color << std::endl;
    os << "-------------------------------------------" << std::endl;

}

Point Parallelogram::getCenter()
{
    double x = (m_point1.X() + m_point3.X()) / 2;
    double y = (m_point1.Y() + m_point3.Y()) / 2;

    return Point(x, y);
}

void Parallelogram::affineTransformation(double affineMatrix[][2])
{
    Point center = this->getCenter();

    m_point1.affineTransformation(affineMatrix, center);
    m_point2.affineTransformation(affineMatrix, center);
    m_point3.affineTransformation(affineMatrix, center);
    m_point4.affineTransformation(affineMatrix, center);
}
