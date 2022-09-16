#pragma once
#include "vector3d.hpp"
#include <vector>

enum class linesIntersection {
	INTERSECT = 0,
	EQUAL = 1,
	NOINTERSECTION = -1
};

template <typename T>
class Line3D
{
public:
	Vector3D<T> strainingVec;
	Vector3D<T> startingPoint;
	Line3D(Vector3D<T> start, Vector3D<T> end, Vector3D<T> x_0): strainingVec(end-start), startingPoint(x_0){};
	Line3D(Vector3D<T> strainingVec, Vector3D<T> x_0): strainingVec(strainingVec), startingPoint(startingPoint){};
	Line3D(Vector3D<T> strainingVec, T x_0): strainingVec(strainingVec), startingPoint(x_0){};
	Line3D(const Line3D<T>& l) {this->startingPoint = l.startingPoint; this->strainingVec = l.strainingVec;}
	~Line3D() = default;
	template <typename D> friend linesIntersection intersect(const Line3D<D> &lhv, const Line3D<D> &rhv);
};

template<typename T> linesIntersection intersect(const Line3D<T> &lhv, const Line3D<T> &rhv);
#include "../src/line3d.inl"
