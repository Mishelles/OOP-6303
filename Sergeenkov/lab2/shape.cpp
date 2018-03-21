#include "shape.h"
#include <typeinfo>

std::string Shape::getColor()
{
    return m_color;
}

void Shape::setColor(std::string color)
{
    m_color = color;
}

void Shape::print(std::ostream &os)
{
    os << "My type is: " << typeid(this).name() << std::endl;
}

std::ostream& operator<<(std::ostream& os, Shape& shape)
{
    shape.print(os);
    return os;
}
