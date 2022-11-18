#ifndef OCTTREE_H
#define OCTTREE_H

#include <vector>
#include <set>
#include "vector3d.h"
#include "triangle3d.h"

const uint8_t MAX_CHILDREN_CNT = 8;

class parallelepiped {
public:
    Point3D lower_bound;
    Point3D higher_bound;
    Point3D center;
    parallelepiped() = default;
    parallelepiped(const Triangle3D &t);
    parallelepiped(const Point3D &left_diag_point, const Point3D &right_diag_point);
    ~parallelepiped() = default;
    bool is_point_inside(const Point3D &point) const;
    bool is_parallelepiped_inside(const parallelepiped &other) const;
    bool is_triangle_intesect(const Triangle3D &tr) const;
    bool is_triangle_inside(const Triangle3D &tr) const;
    bool operator==(const parallelepiped &rhv);
    bool operator!=(const parallelepiped &rhv);
};

class octTreeNode {
private:
    const octTreeNode *parent;
    parallelepiped bound_box;
    std::vector<octTreeNode> children;
    double width;
    void push(octTreeNode child);

public:
    std::vector<std::pair<int, Triangle3D>> objects;
    octTreeNode(const octTreeNode &other);
    octTreeNode &operator=(const octTreeNode &other);
    octTreeNode(octTreeNode *parent, Point3D lower_point, Point3D higher_point);
    parallelepiped get_bound() const;
    void init_children(Point3D center, double width);
    const octTreeNode &get_child(int index) const;
    bool has_children = false;
    double get_width() const;
    std::vector<Point3D> get_new_centers() const;
    bool is_triangle_inside_box(const Triangle3D &tr) const;
    bool is_triangle_intesect_box(const Triangle3D &tr) const;
    void objects_inersetion(std::set<int> &res);
};

class octTree {
private:
    octTreeNode root;
    // std::vector<Triangle3D> &data;

public:
    static constexpr int subboxes_cnt = 8;
    static constexpr double MIN_BOX_WIDTH = 0.2;
    static constexpr double LOWER_COORD = -MIN_BOX_WIDTH / 2;
    static constexpr double HIGHER_COORD = MIN_BOX_WIDTH / 2;
    const parallelepiped MIN_BOX = parallelepiped(Point3D(LOWER_COORD), Point3D(HIGHER_COORD));
    const double COORDINATES_BOUND = -1000;
    octTree(double width);
    ~octTree();
    void insert_data(const Triangle3D &data, int index);
    std::set<int> find_collisions(octTreeNode curnode, std::set<int> &result) const;
};

#endif