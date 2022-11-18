#pragma once

#include "vector3d.h"
#include "line3d.h"

class Plane {
public:
    Vector3D n, sPoint;
    double D;
    Plane() = default;
    Plane(Vector3D v1, Vector3D v2, Vector3D sPoint) : n(v1 ^ v2), sPoint(sPoint), D(-n | sPoint) {};
    Plane(double A, double B, double C, double D) : n(Vector3D(A, B, C)), D(D), sPoint(Vector3D(0, 0, -D / C)) {}
    bool is_point_inside(const Vector3D &point) const;
};

std::pair<MathLib::Geometry::intersection_type, Line3D> operator^(const Plane &pl1, const Plane &pl2);