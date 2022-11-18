#ifndef LINE3D_H
#define LINE3D_H

#include "vector3d.h"
#include "mathlib.h"
#include <vector>

class Line3D {
public:
    Vector3D strainingVec;
    Vector3D startingPoint;
    Line3D() = default;
    Line3D(Vector3D start, Vector3D end, Vector3D x_0) : strainingVec(end - start), startingPoint(x_0) {};
    Line3D(Vector3D strainingVec, Vector3D point_0) : strainingVec(strainingVec), startingPoint(point_0) {};
    Line3D(Vector3D strainingVec, double x_0) : strainingVec(strainingVec), startingPoint(x_0) {};
    Line3D(const Line3D &l)
    {
        startingPoint = l.startingPoint;
        strainingVec = l.strainingVec;
    }
    bool is_point_inside(const Vector3D &point) const;
};

MathLib::Geometry::intersection_type isIntersect(const Line3D &lhv, const Line3D &rhv);

// returns intersection point of two lines. DOESNT CHECK INTERSECTION OF ARGS.
Vector3D get_line_intersection_point(const Line3D &l1, const Line3D &l2);

#endif