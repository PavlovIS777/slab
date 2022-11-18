#include "line3d.h"

bool Line3D::is_point_inside(const Vector3D &point) const
{
    Vector3D cmpVec = startingPoint - point;
    return isCollinear(cmpVec, strainingVec);
}

MathLib::Geometry::intersection_type isIntersect(const Line3D &lhv, const Line3D &rhv)
{
    Vector3D vecMult = lhv.strainingVec ^ rhv.strainingVec;
    double square = vecMult.abs();
    if (MathLib::doubleCmp(square, 0) and lhv.is_point_inside(rhv.startingPoint) and
        rhv.is_point_inside(lhv.startingPoint))
        return MathLib::Geometry::intersection_type::EQUAL;
    double volume = tripleProduct(lhv.strainingVec, rhv.strainingVec, lhv.startingPoint - rhv.startingPoint);
    if (MathLib::doubleCmp(volume / square, 0))
        return MathLib::Geometry::intersection_type::INTERSECT;
    return MathLib::Geometry::intersection_type::NOINTERSECTION;
}

Vector3D get_line_intersection_point(const Line3D &l1, const Line3D &l2)
{
    double t = (l2.strainingVec.x * (l1.startingPoint.y - l2.startingPoint.y) -
                l2.strainingVec.y * (l1.startingPoint.x - l2.startingPoint.x)) /
               (l2.strainingVec.y * l1.strainingVec.x - l1.strainingVec.y * l2.strainingVec.x);
    return l1.startingPoint + t * l1.strainingVec;
}
