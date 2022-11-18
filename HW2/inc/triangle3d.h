#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H

#include "vector3d.h"
#include "line3d.h"
#include "mathlib.h"

class Triangle3D {
public:
    Vector3D p1;
    Vector3D p2;
    Vector3D p3;
    Vector3D center;
    double area;

    Triangle3D() = default;
    Triangle3D(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
    Triangle3D(Vector3D p1_, Vector3D p2_, Vector3D p3_);
    Triangle3D(const Triangle3D &tr);

    Vector3D &operator[](int pos);
    const Vector3D &operator[](int pos) const;
    bool is_point_inside(const Vector3D &point) const;
    static bool is_triangle(const Vector3D &first_side, const Vector3D &second_side, const Vector3D &third_side);
    static bool is_triangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3,
                            double z3);
    double get_width() const;
    static Triangle3D generate_triangle();
    
};

MathLib::Geometry::intersection_type triangleIntersection(const Triangle3D &tr1, const Triangle3D &tr2);

#endif