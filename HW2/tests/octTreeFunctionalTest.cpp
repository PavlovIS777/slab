#include "octTree.h"
#include "triangle3d.h"
#include <vector>
#include <chrono>

std::set<int> triangle_colisions_forehead(std::vector<Triangle3D> &data)
{
    std::set<int> res;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = i + 1; j < data.size(); ++j) {
            auto cond = triangleIntersection(data[i], data[j]);
            if (cond == MathLib::Geometry::intersection_type::INTERSECT ||
                cond == MathLib::Geometry::intersection_type::EQUAL) {
                res.emplace(i);
                res.emplace(j);
            }
        }
    }
    return res;
}

int main()
{
    std::srand(43);
    std::vector<Triangle3D> data;
    double width = 0;
    for (int i = 0; i < 1000; ++i) {
        auto tr = Triangle3D::generate_triangle();
        data.push_back(tr);
        width = std::max(width, tr.get_width());
    }
    width += 100;
    std::set<int> res_forehead = triangle_colisions_forehead(data);
    std::cout << res_forehead.size() << "\n";
    for (auto &it: res_forehead) {
        std::cout << data[it].p1 << " " << data[it].p2 << " " << data[it].p3 << std::endl; 
    }
    // std::set<Triangle3D> res_forehead;
    // octTree tree(width);
}