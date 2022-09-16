// Triangle Intersaction.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "vector3d.hpp"
#include "line3d.hpp"

int main()
{
	Vector3D<double> test(11, 4, 3);
	Vector3D<double> test2(12, 90, 1);
	Vector3D<double> test3 = test2*0.5+test*2.;
	//test3 = test^test2;
	test3 = test3^test;
	test3.point_print();
	Line3D<double> first(test, 0.);
	Line3D<double> second(test3, 100);
	if (intersect(first, second) == linesIntersection::INTERSECT)
		std::cout << "intersect";
	if (intersect(first, second) == linesIntersection::NOINTERSECTION)
		std::cout << "nointersect";
	if (intersect(first, second) == linesIntersection::EQUAL)
		std::cout << "equal";
	return 0;
}
