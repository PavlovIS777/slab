#pragma once
#include "vector3d.hpp"
#include <vector>
template <typename T>
class Line3D
{
public:
	std::vector<T> strainingVector(3);
	Vector3D<T> strainingVec;
	Vector3D<T> startingPoint;
	Line3D(Vector3D<T> start, Vector3D<T> end, Vector3D<T> x_0);

	Vector3D<T>& Vector3D<T>::operator+=(const Vector3D<T>& p);
	~Line3D();
};

#include "../src/line3d.inl"