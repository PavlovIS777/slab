#include "triangle3d.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(trIntersection, test_2Dem_1)
{
    Triangle3D tr1(0, 0, 0, 0, 1, 0, 1, 0, 0);
    Triangle3D tr2(0, 0, 0, 1, 1, 0, 1, 0, 0);
    ASSERT_EQ(MathLib::Geometry::intersection_type::INTERSECT, triangleIntersection(tr1, tr2));
}

TEST(trIntersection, test_2Dem_2)
{
    Triangle3D tr1(0, 0, 0, 0, 1, 0, 1, 0, 0);
    Triangle3D tr2(1, -1, 0, 1, 0.5, 0, 0.5, 0.5, 0);
    ASSERT_EQ(MathLib::Geometry::intersection_type::INTERSECT, triangleIntersection(tr1, tr2));
}

TEST(trIntersection, test_2Dem_3)
{
    Triangle3D tr1(0, 0, 0, 0, 1, 0, 0, 1, 0);
    Triangle3D tr2(1, -1, 0, 1, 0.5, 0, 2, 0.5, 0);
    ASSERT_NE(MathLib::Geometry::intersection_type::INTERSECT, triangleIntersection(tr1, tr2));
}

TEST(trIntersection, test_3Dem_1)
{
    Triangle3D tr1(6, 0, 0, 0, 8, 0, 0, 0, 5);
    Triangle3D tr2(3, 8, 0, 0, 0, 3, 0, 0, -4);
    ASSERT_EQ(MathLib::Geometry::intersection_type::INTERSECT, triangleIntersection(tr1, tr2));
}

TEST(trIntersection, test_3Dem_2)
{
    Triangle3D tr1(6, 0, 0, 0, 8, 0, 0, 0, 5);
    Triangle3D tr2(1, 2, 0, 0, 0, 3, 0, 0, -4);
    ASSERT_NE(MathLib::Geometry::intersection_type::INTERSECT, triangleIntersection(tr1, tr2));
}