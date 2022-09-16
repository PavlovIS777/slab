#pragma once
#include "vector3d.hpp"
#include <iostream>
#include <math.h>
#include <limits>

template<typename T> Vector3D<T>::Vector3D(const Vector3D<T> & src) {
	x = src.x;
	y = src.y;
	z = src.z;
}

template<typename T> void Vector3D<T>::point_print() const {
	std::cout << "{" << this->x << ", " << this->y << ", " << this->z << "}" << std::endl;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const Vector3D<T>& p) {
	out << "{" << p.x << ", " << p.y << ", " << p.z << "}" << std::endl;
	return out;
}

template<typename T> Vector3D<T>& Vector3D<T>::operator+=(const Vector3D<T>& p) {
	x += p.x;
	y += p.y;
	z += p.z;
	return *this;
}

template<typename T> Vector3D<T> operator+(const Vector3D<T>& lhv, const Vector3D<T>& rhv) {
	Vector3D<T> value(lhv.x+rhv.x, lhv.y+rhv.y, lhv.z+rhv.z);
	return value;
}

template<typename T> Vector3D<T> Vector3D<T>::operator-() const{
	Vector3D<T> value(-this->x, -this->y, -this->z);
	return value;
}

template<typename T> Vector3D<T> operator-(const Vector3D<T>& lhv, const Vector3D<T>& rhv) {
	Vector3D<T> minusRhv = -rhv;
	Vector3D<T> value = lhv + minusRhv;
	return value;
}

template<typename T> double operator|(const Vector3D<T>& lhv, const Vector3D<T>& rhv) {
	return lhv.x*rhv.x+lhv.y*rhv.y+lhv.z*rhv.z;
}

template<typename T> Vector3D<T> operator*(const Vector3D<T>& lhv, const T& rhv) {
	return Vector3D<T> (lhv.x*rhv, lhv.y*rhv, lhv.z*rhv);
}

template<typename T> Vector3D<T> operator*(const T& lhv, const Vector3D<T>& rhv) {
	return rhv*lhv;
}

template<typename T> Vector3D<T> operator^(const Vector3D<T>& lhv, const Vector3D<T>& rhv) {
	Vector3D<T> value(lhv.y*rhv.z-lhv.z*rhv.y, lhv.z*rhv.x-lhv.x*rhv.z, lhv.x*rhv.y-lhv.y*rhv.x);
	return value;
}

template<typename T> double Vector3D<T>::abs() {
	return std::sqrt((*this)|(*this));
}

bool doubleCmp(const double &lhv, const double &rhv) {
	if (std::abs(lhv-rhv) < std::numeric_limits<double>::epsilon())
		return true;
	else return false;
}

template<typename T> double tripleProduct(const Vector3D<T>& first, const Vector3D<T>& second, const Vector3D<T>& third) {
	return first.x*second.y*third.z+first.y*second.z*third.x+first.z*second.x*third.y-first.z*second.y*third.x-first.y*second.x*third.z -
	first.x*second.z*third.y;
}