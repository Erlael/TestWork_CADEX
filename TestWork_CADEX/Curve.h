#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>
const double M_PI = 3.14;

class Vector3D {
public:
    double x, y, z;
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    Vector3D operator +(const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }
    Vector3D operator *(double s) const {
        return Vector3D(x * s, y * s, z * s);
    }
    void operator +=(const Vector3D& v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }
};

class Curve {
public:
    virtual ~Curve() {}
    virtual Vector3D point(double t) const = 0;
    virtual Vector3D derivative(double t) const = 0;
};

