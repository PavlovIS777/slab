#include "plane.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(palneIntersect, test1)
{
    Plane pl1(1, 2, -3, -2);
    Plane pl2(1, 0, -1, 4);
    auto result = pl1 ^ pl2;
    Line3D line = result.second;
    Vector3D expectedStrVect(-2, -2, -2);
    if (!isCollinear(expectedStrVect, line.strainingVec)) {
        std::cout << "not collinear";
        FAIL();
    }
    if (!pl1.is_point_inside(line.startingPoint)) {
        std::cout << "sPoint no in first plane";
        FAIL();
    }
    if (!pl2.is_point_inside(line.startingPoint)) {
        std::cout << "sPoint no in second plane";
        FAIL();
    }
    SUCCEED();
}

TEST(palneIntersect, test2)
{
    Plane pl1(2, 1, -1, -1);
    Plane pl2(1, 3, -2, 0);
    auto result = pl1 ^ pl2;
    Line3D line = result.second;
    Vector3D expectedStrVect(1, 3, 5);
    if (!isCollinear(expectedStrVect, line.strainingVec)) {
        std::cout << "not collinear";
        FAIL();
    }
    if (!pl1.is_point_inside(line.startingPoint)) {
        std::cout << "sPoint no in first plane";
        FAIL();
    }
    if (!pl2.is_point_inside(line.startingPoint)) {
        std::cout << "sPoint no in second plane";
        FAIL();
    }
    SUCCEED();
}