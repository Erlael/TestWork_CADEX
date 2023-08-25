#include "Circle.h"
#include <cmath>

Circle::Circle(double cx, double cy, double r) :
    cx(cx), cy(cy), r(r) {}

std::pair<double, double> Circle::evaluate(double t) const {
    double x = cx + r * cos(t);
    double y = cy + r * sin(t);
    double dx = -r * sin(t);
    double dy = r * cos(t);
    return { x, y};
    //добавить вывод dx dy
}

double Circle::getRadius() const {
    return r;
}
