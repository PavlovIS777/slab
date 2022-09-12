#pragma once
#include "../inc/line3d.hpp"

template <typename T> Line3D<T>::Line3D(Vector3D<T> start, Vector3D<T> end, Vector3D<T> x_0) {
	this->strainingVec = end - start;
	this->startingPoint = x_0;
}