#pragma once
#include "../inc/line3d.hpp"

// template <typename T> Line3D<T>::Line3D(Vector3D<T> start, Vector3D<T> end, Vector3D<T> x_0) {
// 	this->strainingVec = end - start;
// 	this->startingPoint = x_0;
// }

// template <typename T> Line3D<T>::Line3D(Vector3D<T> strainingVec, Vector3D<T> x_0) {
// 	this->strainingVec = strainingVec;
// 	this->startingPoint = x_0;
// }

// template <typename T> Line3D<T>::Line3D(Vector3D<T> strainingVec, T x_) {
// 	this->strainingVec = strainingVec;
// 	Vector3D<T> sPoint(x_);
// 	this->startingPoint = sPoint;
// }

template<typename T> linesIntersection intersect(const Line3D<T> &lhv, const Line3D<T> &rhv) {
	Vector3D<T> vecMult = lhv.strainingVec^rhv.strainingVec; 
	double square = vecMult.abs();
	if (doubleCmp(square, 0))
		return linesIntersection::EQUAL;
	double volume = tripleProduct(lhv.strainingVec, rhv.strainingVec, lhv.startingPoint-rhv.startingPoint);
	if (doubleCmp(volume/square, 0))
		return linesIntersection::INTERSECT;
	return linesIntersection::NOINTERSECTION;
}