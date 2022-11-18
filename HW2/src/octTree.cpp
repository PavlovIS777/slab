#include <algorithm>
#include "octTree.h"

parallelepiped::parallelepiped(const Point3D &left_diag_point, const Point3D &right_diag_point)
{
    lower_bound = left_diag_point;
    higher_bound = right_diag_point;
    center = (left_diag_point + right_diag_point) / 2;
}

parallelepiped::parallelepiped(const Triangle3D &t)
{
    lower_bound = Vector3D(std::min(t.p1.x, std::min(t.p2.x, t.p3.x)), std::min(t.p1.y, std::min(t.p2.y, t.p3.y)),
                           std::min(t.p1.z, std::min(t.p2.z, t.p3.z)));
    higher_bound = Vector3D(std::max(t.p1.x, std::max(t.p2.x, t.p3.x)), std::max(t.p1.y, std::max(t.p2.y, t.p3.y)),
                            std::max(t.p1.z, std::max(t.p2.z, t.p3.z)));
    center = (higher_bound + lower_bound) / 2;
}

bool parallelepiped::is_parallelepiped_inside(const parallelepiped &other) const
{
    return lower_bound.x < other.lower_bound.x && lower_bound.y < other.lower_bound.y &&
           lower_bound.z < other.lower_bound.z && higher_bound.x > other.higher_bound.x &&
           higher_bound.y > other.higher_bound.y && higher_bound.z > other.higher_bound.z;
}

bool parallelepiped::is_point_inside(const Point3D &point) const
{
    return ((point >= lower_bound) and (point <= higher_bound));
}

bool parallelepiped::is_triangle_intesect(const Triangle3D &tr) const
{
    if (is_point_inside(tr.p1) and (!is_point_inside(tr.p2) || !is_point_inside(tr.p3))) {
        return true;
    }
    if (is_point_inside(tr.p2) and (!is_point_inside(tr.p1) || !is_point_inside(tr.p3))) {
        return true;
    }
    if (is_point_inside(tr.p3) and (!is_point_inside(tr.p2) || !is_point_inside(tr.p1))) {
        return true;
    }
    return false;
}

bool parallelepiped::is_triangle_inside(const Triangle3D &tr) const
{
    return (is_point_inside(tr.p1) and is_point_inside(tr.p2) and is_point_inside(tr.p3));
}

bool parallelepiped::operator==(const parallelepiped &rhv)
{
    return (lower_bound == rhv.lower_bound and higher_bound == rhv.higher_bound);
}
bool parallelepiped::operator!=(const parallelepiped &rhv)
{
    return (lower_bound != rhv.lower_bound and higher_bound != rhv.higher_bound);
}

octTreeNode::octTreeNode(octTreeNode *parent, Point3D lower_point, Point3D higher_point)
    : parent(parent), bound_box(lower_point, higher_point)
{
}

void octTreeNode::push(octTreeNode child)
{
    children.push_back(child);
}

octTreeNode &octTreeNode::operator=(const octTreeNode &other)
{
    if (this == &other) {
        return *this;
    }
    parent = other.parent;
    bound_box = other.bound_box;
    children = other.children;
    objects = other.objects;
    has_children = other.has_children;
    return *this;
}

octTreeNode::octTreeNode(const octTreeNode &other)
{
    parent = other.parent;
    bound_box = other.bound_box;
    children = other.children;
    objects = other.objects;
    has_children = other.has_children;
}

octTree::octTree(double width)
    : COORDINATES_BOUND(width), root(nullptr, Point3D(-width, -width, -width), Point3D(width, width, width))
{
    root.init_children(Point3D(0, 0, 0), width);
}

parallelepiped octTreeNode::get_bound() const
{
    return bound_box;
}

void octTreeNode::init_children(Point3D center, double width)
{
    push(octTreeNode(this, Point3D(-width, -width, -width), Point3D(center.x, center.y, center.z)));
    push(octTreeNode(this, Point3D(center.x, -width, -width), Point3D(center.x, center.y, width)));
    push(octTreeNode(this, Point3D(center.x, center.y, -width), Point3D(width, width, center.z)));
    push(octTreeNode(this, Point3D(-width, center.y, -width), Point3D(center.x, width, center.z)));
    push(octTreeNode(this, Point3D(-width, -width, center.z), Point3D(center.x, center.y, width)));
    push(octTreeNode(this, Point3D(center.x, -width, center.z), Point3D(width, center.y, width)));
    push(octTreeNode(this, Point3D(center.x, center.y, center.z), Point3D(width, width, width)));
    push(octTreeNode(this, Point3D(-width, center.y, center.z), Point3D(center.x, width, width)));
    has_children = true;
}

const octTreeNode &octTreeNode::get_child(int index) const
{
    return children[index];
}

std::vector<Point3D> octTreeNode::get_new_centers() const
{
    std::vector<Point3D> new_centers;
    double new_width = width / 2;
    Point3D cur_center = bound_box.center;
    new_centers.push_back(cur_center + Point3D(new_width, -new_width, -new_width));
    new_centers.push_back(cur_center + Point3D(new_width, new_width, -new_width));
    new_centers.push_back(cur_center + Point3D(-new_width, new_width, -new_width));
    new_centers.push_back(cur_center + Point3D(-new_width, -new_width, -new_width));
    new_centers.push_back(cur_center + Point3D(new_width, -new_width, new_width));
    new_centers.push_back(cur_center + Point3D(new_width, new_width, new_width));
    new_centers.push_back(cur_center + Point3D(-new_width, new_width, new_width));
    new_centers.push_back(cur_center + Point3D(-new_width, -new_width, new_width));
    return new_centers;
}

double octTreeNode::get_width() const
{
    return width;
}

bool octTreeNode::is_triangle_inside_box(const Triangle3D &tr) const
{
    return bound_box.is_triangle_inside(tr);
}

bool octTreeNode::is_triangle_intesect_box(const Triangle3D &tr) const
{
    return bound_box.is_triangle_intesect(tr);
}

void octTree::insert_data(const Triangle3D &triangle, int index)
{
    auto prev_node = root;
    auto cur_node = root;
    auto new_centers = root.get_new_centers();
    int triangle_boxes_intersect_cnt = 0;
    bool end_of_search = false;
    for (int i = 0; !end_of_search || i < subboxes_cnt; ++i) {
        cur_node = prev_node.get_child(i);
        auto cur_parall = cur_node.get_bound();
        if (cur_parall.lower_bound == MIN_BOX.lower_bound) {
            end_of_search = true;
        }
        if (cur_node.has_children == false) {
            cur_node.init_children(new_centers[i], root.get_width() / 2);
        }
        if (end_of_search == false && cur_node.is_triangle_inside_box(triangle)) {
            i = 0;
            new_centers = prev_node.get_new_centers();
            prev_node = cur_node;
            continue;
        } else if (cur_node.is_triangle_intesect_box(triangle)) {
            end_of_search = true;
            cur_node.objects.push_back({index, triangle});
        }
    }
}

void octTreeNode::objects_inersetion(std::set<int> &res)
{
    for (int i = 0; i < this->objects.size(); ++i) {
        for (int j = i; j < this->objects.size(); ++j) {
            auto intersection = triangleIntersection(this->objects[i].second, this->objects[j].second);
            if (intersection == MathLib::Geometry::intersection_type::INTERSECT ||
                intersection == MathLib::Geometry::intersection_type::EQUAL) {
                res.emplace(this->objects[i].first);
                res.emplace(this->objects[j].first);
            }
        }
    }
}

std::set<int> octTree::find_collisions(octTreeNode curnode, std::set<int> &result) const
{
    curnode.objects_inersetion(result);
    for (int i = 0; i < 8; ++i) {
        auto cur_child = curnode.get_child(i);
        for (int i = 0; i < curnode.objects.size(); ++i) {
            cur_child.objects.push_back(curnode.objects[i]);
        }
        if (cur_child.get_bound() != MIN_BOX) {
            find_collisions(cur_child, result);
        } else {
            cur_child.objects_inersetion(result);
        }
    }
    return result;
}
