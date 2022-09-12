//#ifndef POINT_HPP
//#define POINT_HPP
#pragma once

template <typename T>
class Vector3D
{
public:
    T x, y, z;
    Vector3D(T x_, T y_, T z_): x(x_), y(y_), z(z_){};
    Vector3D(const Vector3D<T>&) = default;
    ~Vector3D(){};
    void point_print() const;
    Vector3D& operator+=(const Vector3D<T>& p);
    Vector3D operator-() const;
    template <typename D> friend Vector3D<D> operator+(const Vector3D<D>& lhv, const Vector3D<D>& rhv);
    template <typename D> friend Vector3D<D> operator-(const Vector3D<D>& lhv, const Vector3D<D>& rhv);
    template <typename D> friend double operator*(const Vector3D<D>& lhv, const Vector3D<D>& rhv);
    template <typename D> friend Vector3D<D> operator^(const Vector3D<D>& lhv, const Vector3D<D>& rhv);
};
template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector3D<T>& p);

template<typename T> Vector3D<T> operator+(const Vector3D<T>& lhv, const Vector3D<T>& rhv);
template<typename T> Vector3D<T> operator-(const Vector3D<T>& lhv, const Vector3D<T>& rhv);
template<typename T> double operator*(const Vector3D<T>& lhv, const Vector3D<T>& rhv);
template<typename T> Vector3D<T> operator^(const Vector3D<T>& lhv, const Vector3D<T>& rhv);
#include "../src/vector3d.inl"

//#endif