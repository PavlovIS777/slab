#include <vector>
#include <cmath>
#include <stdexcept>
#include <random>
#include <cmath>
#include <ctime>
#include "triangle3d.h"
#include "plane.h"

bool Triangle3D::is_triangle(const Vector3D &first_side, const Vector3D &second_side, const Vector3D &third_side)
{
    return (first_side.abs() + second_side.abs() < third_side.abs() &&
            first_side.abs() + third_side.abs() < second_side.abs() &&
            third_side.abs() + second_side.abs() < first_side.abs());
}

bool Triangle3D::is_triangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3,
                             double z3)
{
    Vector3D first_side(x1 - x2, y1 - y2, z1 - z2);
    Vector3D second_side(x1 - x3, y1 - y3, z1 - z3);
    Vector3D third_side(x3 - x2, y3 - y2, z3 - z2);
    return Triangle3D::is_triangle(first_side, second_side, third_side);
}

Triangle3D::Triangle3D(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3,
                       double z3)
{
    p1 = Vector3D(x1, y1, z1);
    p2 = Vector3D(x2, y2, z2);
    p3 = Vector3D(x3, y3, z3);
    center = Vector3D((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, (z1 + z2 + z3) / 3);
    area = ((p1 - p2) ^ (p1 - p3)).abs() / 2;
}
Triangle3D::Triangle3D(const Triangle3D &tr)
{
    p1 = tr.p1;
    p2 = tr.p2;
    p3 = tr.p3;
    center = tr.center;
    area = tr.area;
}

Triangle3D::Triangle3D(Vector3D p1_, Vector3D p2_, Vector3D p3_)
{
    p1 = p1_;
    p2 = p2_;
    p3 = p3_;
    center = (p1 + p2 + p3) / 3;
    area = ((p1 - p2) ^ (p1 - p3)).abs() / 2;
}

Vector3D &Triangle3D::operator[](int pos)
{
    switch (pos) {
        case 0:
            return p1;
            break;
        case 1:
            return p2;
            break;
        case 2:
            return p3;
            break;
    }
    throw std::out_of_range("Out of range\n");
}

const Vector3D &Triangle3D::operator[](int pos) const
{
    switch (pos) {
        case 0:
            return p1;
            break;
        case 1:
            return p2;
            break;
        case 2:
            return p3;
            break;
    }
    std::cout << "pizda";
    throw std::out_of_range("Out of range\n");
}

bool Triangle3D::is_point_inside(const Vector3D &point) const
{
    double p_area = (((point - p1) ^ (point - p2)).abs() + ((point - p1) ^ (point - p3)).abs() +
                     ((point - p2) ^ (point - p3)).abs()) /
                    2;
    return MathLib::doubleCmp(p_area, area);
}

MathLib::Geometry::intersection_type triangleIntersection(const Triangle3D &tr1, const Triangle3D &tr2)
{
    Plane pl1(tr1.p1 - tr1.p2, tr1.p1 - tr1.p3, tr1.p1);
    Plane pl2(tr2.p1 - tr2.p2, tr2.p1 - tr2.p3, tr2.p1);
    auto intersection = pl1 ^ pl2;
    if (intersection.first == MathLib::Geometry::intersection_type::NOINTERSECTION) {
        return MathLib::Geometry::intersection_type::NOINTERSECTION;
    }
    Line3D plane_intersection_line = intersection.first == MathLib::Geometry::intersection_type::EQUAL
                                         ? Line3D(tr2.p2 - tr2.p1, tr2.p1)
                                         : intersection.second;
    std::vector<Vector3D> intersection_points_tr1;
    std::vector<Vector3D> intersection_points_tr2;
    for (int i = 0; i < 3; ++i) {
        Line3D side(tr1[(i + 1) % 3] - tr1[i], tr1[i]);
        MathLib::Geometry::intersection_type tr_side_intersection = isIntersect(plane_intersection_line, side);
        if (tr_side_intersection == MathLib::Geometry::intersection_type::EQUAL) {
            return MathLib::Geometry::intersection_type::INTERSECT;
        } else if (tr_side_intersection == MathLib::Geometry::intersection_type::INTERSECT) {
            intersection_points_tr1.push_back(get_line_intersection_point(side, plane_intersection_line));
        }
    }

    for (auto &point : intersection_points_tr1) {
        if (tr2.is_point_inside(point)) {
            return MathLib::Geometry::intersection_type::INTERSECT;
        }
    }
    return MathLib::Geometry::intersection_type::NOINTERSECTION;
}

Triangle3D Triangle3D::generate_triangle()
{
    Triangle3D triangle;
    for (int i = 0; i < 3; ++i) {
        double theta = (static_cast<double>(rand()) / static_cast<double>(INT32_MAX)) * M_PI * 2;
        double phi = (static_cast<double>(rand()) / static_cast<double>(INT32_MAX)) * M_PI * 2;
        double rho = 0.3 + std::abs((static_cast<double>(rand()) / static_cast<double>(INT32_MAX))) * 10;
        triangle[i] = Point3D(rho * sin(theta) * cos(theta), rho * sin(theta) * sin(phi), rho * cos(theta));
    }
    return triangle;
}

double Triangle3D::get_width() const
{
    return std::max({std::abs(p1.x - p2.x), std::abs(p1.y - p2.y), std::abs(p1.z - p2.z), std::abs(p1.x - p3.x),
                     std::abs(p1.y - p3.y), std::abs(p1.z - p3.z), std::abs(p2.x - p3.x), std::abs(p2.y - p3.y),
                     std::abs(p2.z - p3.z)});
}