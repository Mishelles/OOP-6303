#include "parallelogramfactory.h"
#include <cmath>

Shape* ParallelogramFactory::create(Point point1, Point point2, Point point3, Point point4, std::string color)
{
    // Считаем прямые параллельными, если равны тангенсы углов наклона

    double k1 = abs((point1.Y() - point2.Y()) / (point1.X() - point2.X()));
    double k2 = abs((point4.Y() - point3.Y()) / (point4.X() - point3.X()));
    double k3 = abs((point1.Y() - point4.Y()) / (point1.X() - point4.X()));
    double k4 = abs((point3.Y() - point2.Y()) / (point3.X() - point2.X()));

    if ((k1 != k2) || (k3 != k4)) {
        std::cout << "По заданным точкам невозможно построить параллелограмм!" << std::endl;
        return nullptr;
    }

    Shape* parallelogram = new Parallelogram(point1, point2, point3, point4, color);
    m_objects.push_back(parallelogram);
    return parallelogram;
}
