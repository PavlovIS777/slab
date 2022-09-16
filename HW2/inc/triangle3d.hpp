#pragma once
#include "vector3d.hpp"
#include "line3d.hpp"

template <typename T>
class Triangle3D
{
public:
    Vector3D<T> p1_;
    Vector3D<T> p2_;
    Vector3D<T> p3_;
    Vector3D<T> center_;
    Triangle3D() {};
    Triangle3D(T x1, T y1, T z1, T x2, T y2, T z2, T x3, T y3, T z3);
    Triangle3D(const Triangle3D<T>& tr);
    circleSort();
    ~Triangle();
};
