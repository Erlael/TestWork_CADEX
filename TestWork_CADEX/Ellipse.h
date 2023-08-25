#pragma once

#include "Curve.h"

class Ellipse : public Curve {
public:
    Ellipse(double radiusX, double radiusY) : mRadiusX(radiusX), mRadiusY(radiusY) {}
    Vector3D point(double t) const override {
        return Vector3D(mRadiusX * std::cos(t), mRadiusY * std::sin(t), 0.0);
    }
    Vector3D derivative(double t) const override {
        return Vector3D(-mRadiusX * std::sin(t), mRadiusY * std::cos(t), 0.0);
    }
    double getRadiusX() const { return mRadiusX; }
    double getRadiusY() const { return mRadiusY; }
private:
    double mRadiusX, mRadiusY;
};

