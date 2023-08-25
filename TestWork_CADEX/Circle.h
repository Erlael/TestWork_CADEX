#pragma once

#include "Curve.h"

class Circle : public Curve {
public:
    Circle(double radius) : mRadius(radius) {}
    Vector3D point(double t) const override {
        return Vector3D(mRadius * std::cos(t), mRadius * std::sin(t), 0.0);
    }
    Vector3D derivative(double t) const override {
        return Vector3D(-mRadius * std::sin(t), mRadius * std::cos(t), 0.0);
    }
    double getRadius() const { return mRadius; }
private:
    double mRadius;
};
