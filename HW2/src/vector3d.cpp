#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "vector3d.h"
#include "mathlib.h"

Vector3D::Vector3D(const Vector3D &src)
{
    x = src.x;
    y = src.y;
    z = src.z;
}

void Vector3D::point_print() const
{
    std::cout << "{" << x << ", " << y << ", " << z << "}" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Vector3D &p)
{
    out << "{" << p.x << ", " << p.y << ", " << p.z << "}";
    return out;
}

Vector3D &Vector3D::operator+=(const Vector3D &p)
{
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}

Vector3D operator+(const Vector3D &lhv, const Vector3D &rhv)
{
    return Vector3D(lhv.x + rhv.x, lhv.y + rhv.y, lhv.z + rhv.z);
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
    ;
}

Vector3D operator-(const Vector3D &lhv, const Vector3D &rhv)
{
    Vector3D minusRhv = -rhv;
    Vector3D value = lhv + minusRhv;
    return value;
}

double operator|(const Vector3D &lhv, const Vector3D &rhv)  // Scalar multiplication
{
    return lhv.x * rhv.x + lhv.y * rhv.y + lhv.z * rhv.z;
}

Vector3D operator*(const Vector3D &lhv, const double &rhv)
{
    return Vector3D(lhv.x * rhv, lhv.y * rhv, lhv.z * rhv);
}

Vector3D operator*(const double &lhv, const Vector3D &rhv)  // Vector multiplication
{
    return rhv * lhv;
}

Vector3D operator^(const Vector3D &lhv, const Vector3D &rhv)
{
    Vector3D value(lhv.y * rhv.z - lhv.z * rhv.y, lhv.z * rhv.x - lhv.x * rhv.z, lhv.x * rhv.y - lhv.y * rhv.x);
    return value;
}

double Vector3D::abs() const
{
    return std::sqrt((*this) | (*this));
}

double tripleProduct(const Vector3D &first, const Vector3D &second, const Vector3D &third)
{
    return first.x * second.y * third.z + first.y * second.z * third.x + first.z * second.x * third.y -
           first.z * second.y * third.x - first.y * second.x * third.z - first.x * second.z * third.y;
}

double &Vector3D::operator[](int pos)
{
    switch (pos) {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            throw std::out_of_range("Segmentation fault");
            break;
    }
}

double Vector3D::operator[](int pos) const
{
    switch (pos) {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            throw std::out_of_range("Segmentation fault");
            break;
    }
}

Vector3D &Vector3D::operator*=(double rhv)
{
    x *= rhv;
    y *= rhv;
    z *= rhv;
    return *this;
}

bool Vector3D::operator==(const Vector3D &rhv) const
{
    if (MathLib::doubleCmp(x, rhv.x) && MathLib::doubleCmp(y, rhv.y) && MathLib::doubleCmp(z, rhv.z)) {
        return true;
    }
    return false;
}

bool Vector3D::operator!=(const Vector3D &rhv) const
{
    return !(*this == rhv);
}

bool isCollinear(Vector3D first, Vector3D second)
{
    double mult = first.get_collinear_mult(second);
    second *= mult;
    return first == second;
}

Vector3D operator/(const Vector3D &lhv, const double &rhv)
{
    return lhv * (1 / rhv);
}

double Vector3D::get_collinear_mult(const Vector3D &other) const
{
    double mult = 0;

    if (!MathLib::doubleCmp(other.x, 0)) {
        mult = x / other.x;
    } else if (!MathLib::doubleCmp(other.y, 0)) {
        mult = y / other.y;
    } else if (!MathLib::doubleCmp(other.z, 0)) {
        mult = z / other.z;
    }

    return mult;
}

bool Vector3D::operator<=(const Vector3D &other) const
{
    return (x <= other.x) and (y <= other.y) and (z <= other.z);
}

bool Vector3D::operator<(const Vector3D &other) const
{
    return (x < other.x) and (y < other.y) and (z < other.z);
}

bool Vector3D::operator>=(const Vector3D &other) const
{
    return other <= *this;
}

bool Vector3D::operator>(const Vector3D &other) const
{
    return other < *this;
}