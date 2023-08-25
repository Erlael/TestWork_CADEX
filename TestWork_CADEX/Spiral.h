#pragma once

#include "Curve.h"

class Spiral : public Curve {
public:
    Spiral(double radius, double step) : mRadius(radius), mStep(step) {}
    Vector3D point(double t) const override {
        return Vector3D(mRadius * std::cos(t), mRadius * std::sin(t), mStep * t / (2.0 * M_PI));
    }
    Vector3D derivative(double t) const override {
        return Vector3D(-mRadius * std::sin(t), mRadius * std::cos(t), mStep / (2.0 * M_PI));
    }
    double getRadius() const { return mRadius; }
    double getStep() const { return mStep; }
private:
    double mRadius, mStep;
};

