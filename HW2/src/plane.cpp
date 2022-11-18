#ifndef PLANE_H
#define PLANE_H

#include "plane.h"
#include "mathlib.h"

std::pair<MathLib::Geometry::intersection_type, Line3D> operator^(const Plane &pl1, const Plane &pl2)
{
    if (isCollinear(pl1.n, pl2.n)) {
        double mult = pl2.n.get_collinear_mult(pl1.n);
        if (MathLib::doubleCmp(pl1.D, pl2.D * mult)) {
            return {MathLib::Geometry::intersection_type::EQUAL, Line3D()};
        } else {
            return {MathLib::Geometry::intersection_type::NOINTERSECTION, Line3D()};
        }
    }
    double **mat = new double *[3];
    for (int i = 0; i < 3; ++i) {
        mat[i] = new double[4] {0};
    }
    for (int j = 0; j < 3; ++j) {
        mat[0][j] = pl1.n[j];
    }
    for (int j = 0; j < 3; ++j) {
        mat[1][j] = pl2.n[j];
    }
    mat[0][3] = -pl1.D;
    mat[1][3] = -pl2.D;
    auto result = MathLib::Matrix::gaus_elemination(mat, 3);

    Vector3D linePoint(result.second[0][1], result.second[1][1], result.second[2][1]);
    Vector3D strVector(result.second[0][0], result.second[1][0], result.second[2][0]);

    // delete gaussian matrix
    for (int i = 0; i < 3; ++i) {
        delete[] mat[i];
    }
    delete[] mat;

    // delete gaussian result
    for (int i = 0; i < 3; ++i) {
        delete[] result.second[i];
    }
    delete[] result.second;

    return {MathLib::Geometry::intersection_type::INTERSECT, Line3D(strVector, linePoint)};
}

bool Plane::is_point_inside(const Vector3D &point) const
{
    if (MathLib::doubleCmp((point | n) + D, 0)) {
        return true;
    }
    return false;
}

#endif
