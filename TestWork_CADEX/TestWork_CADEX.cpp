#include <iostream>
#include <stdlib.h>
#include"Circle.h"
#include"Ellipse.h"
#include"Spiral.h"

int main() {

    srand(time(NULL));

    // Создание контейнера с кривыми
    std::vector<std::unique_ptr<Curve>> curves;

    for (int i = 0; i < 10; i++)
    {
        int random = rand() % 3;
        switch (random)
        {
            case 0:
                curves.push_back(std::make_unique<Circle>(rand() % 10));
                break;
            case 1:
                curves.push_back(std::make_unique<Ellipse>(rand() % 3, rand() % 3));
                break;
            case 2:
                curves.push_back(std::make_unique<Spiral>(rand() % 6, rand() % 3));
                break;  
            default:
                break;
        }
    }


    // Вывод координат точек и производных всех кривых в контейнере при t=PI/4
    const double t = M_PI / 4.0;
    for (const auto& curve : curves) {
        Vector3D point = curve->point(t);
        Vector3D derivative = curve->derivative(t);
        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
        std::cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << std::endl;
        std::cout << std::endl;
    }

    // Создание отдельного контейнера только для кругов
    std::vector<const Circle*> circles;
    for (const auto& curve : curves) {
        if (const Circle* circle = dynamic_cast<const Circle*>(curve.get())) {
            circles.push_back(circle);
        }
    }

    // Сортировка контейнера по увеличению радиусов окружностей
    std::sort(circles.begin(), circles.end(), [](const Circle* lhs, const Circle* rhs) {
        return lhs->getRadius() < rhs->getRadius();
    });

    // Вычисление общей суммы радиусов всех кругов в контейнере
    double sumOfRadii = 0.0;
    for (const auto& circle : circles) {
        sumOfRadii += circle->getRadius();
    }

    std::cout << "Sum of radii: " << sumOfRadii << std::endl;

    return 0;
}