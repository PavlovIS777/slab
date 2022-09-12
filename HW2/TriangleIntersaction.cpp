// Triangle Intersaction.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "./inc/Triangle Intersaction.h"
#include "./inc/vector3d.hpp"

int main()
{
	Vector3D<double> test(11, 4, 3);
	Vector3D<double> test2(1, 2, 3);
	Vector3D<double> test3 = -test2+test;
	test.point_print();	
	double scalar = test*test2;
	test3 = test^test2;
	std::cout << test3;
	std::cout << scalar;
	//std::cout << "Hello CMake." << std::endl;
	return 0;
}
