#include "shapefactory.h"

ShapeFactory::~ShapeFactory()
{
    for(unsigned i = 0; i < m_objects.size(); i++)
    {
        delete m_objects[i];
    }

    m_objects.clear();

    std::cout << "Factory destroyed" << std::endl;
}
