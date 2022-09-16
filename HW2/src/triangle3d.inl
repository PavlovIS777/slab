#pragma once

#include "../inc/triangle3d.hpp"

template<typename T> Triangle3D<T>::circleSort() {
    if ()
}

template<typename T> Triangle3D<T>::Triangle3D(T x1, T y1, T z1, T x2, T y2, T z2, T x3, T y3, T z3) {
    p1_ = Vector3D<T>(x1, y1, z1);
    p2_ = Vector3D<T>(x2, y2, z2);
    p3_ = Vector3D<T>(x3, y3, z3);
    center_ = Vector3D<T>((x1+x2+x3)/3, (y1+y2+y3)/3, (z1+z2+z3)/3);
}
template<typename T> Triangle3D<T>::Triangle3D(const Triangle3D<T>& tr) {
    p1_(tr.p1_);
    p2_(tr.p2_);
    p3_(tr.p3_);
    center_(tr.center_);
}