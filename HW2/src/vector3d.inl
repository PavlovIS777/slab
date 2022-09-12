#pragma once
#include "../inc/vector3d.hpp"
#include <iostream>
template<typename T> void Vector3D<T>::point_print() const {
	std::cout << "{" << this->x << ", " << this->y << ", " << this->z << "}" << std::endl;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const Vector3D<T>& p) {
	out << "{" << p.x << ", " << p.y << ", " << p.z << "}" << std::endl;
	return out;
}

template<typename T> Vector3D<T>& Vector3D<T>::operator+=(const Vector3D<T>& p) {
	this->x += p.x;
	this->y += p.y;
	this->z += p.z;
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

template<typename T> double operator*(const Vector3D<T>& lhv, const Vector3D<T>& rhv) {
	return lhv.x*rhv.x+lhv.y*rhv.y+lhv.z*rhv.z;
}

template<typename T> Vector3D<T> operator^(const Vector3D<T>& lhv, const Vector3D<T>& rhv) {
	Vector3D<T> value(lhv.y*rhv.z-lhv.z*rhv.y, lhv.z*rhv.x-lhv.x*rhv.z, lhv.x*rhv.y-lhv.y*rhv.x);
	return value;
}