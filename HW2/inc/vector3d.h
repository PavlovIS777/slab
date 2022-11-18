#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {
public:
    double x, y, z;
    Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
    explicit Vector3D(double val) : x(val), y(val), z(val) {}
    Vector3D(const Vector3D &src);
    Vector3D() = default;
    void point_print() const;
    Vector3D &operator+=(const Vector3D &p);
    Vector3D &operator*=(double rhv);
    Vector3D operator-() const;
    bool operator==(const Vector3D &rhv) const;
    bool operator!=(const Vector3D &rhv) const;
    double &operator[](int pos);
    double operator[](int pos) const;
    bool operator<=(const Vector3D &other) const;
    bool operator<(const Vector3D &other) const;
    bool operator>(const Vector3D &other) const;
    bool operator>=(const Vector3D &other) const;
    double tripleProduct(const Vector3D &first, const Vector3D &second, const Vector3D &third);
    double abs() const;
    double get_collinear_mult(const Vector3D &other) const;
};

std::ostream &operator<<(std::ostream &out, const Vector3D &p);

Vector3D operator+(const Vector3D &lhv, const Vector3D &rhv);

Vector3D operator-(const Vector3D &lhv, const Vector3D &rhv);

Vector3D operator*(const Vector3D &lhv, const double &rhv);

Vector3D operator/(const Vector3D &lhv, const double &rhv);

Vector3D operator*(const double &lhv, const Vector3D &rhv);

double operator|(const Vector3D &lhv, const Vector3D &rhv);

Vector3D operator^(const Vector3D &lhv, const Vector3D &rhv);

double tripleProduct(const Vector3D &first, const Vector3D &second, const Vector3D &third);

bool isCollinear(Vector3D first, Vector3D second);

using Point3D = Vector3D;

#endif
