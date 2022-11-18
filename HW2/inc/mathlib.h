#pragma once
#include <vector>
#include <cassert>
#include <algorithm>

namespace MathLib {

bool doubleCmp(const double &lhv, const double &rhv);

namespace Matrix {

void swap_rows(double *const *mat, int width, int firsttRow, int secondRow);

void mul_row(double *const *mat, int width, int row, double mult);

int find_non_zero(const double *const *mat, int width, int row);

// void gaus_elemination_forward(double** mat, int width, int pivot)

std::pair<int, double **> gaus_elemination(double **mat, int n);

void print(double *const *mat, int n);

}  // namespace Matrix

namespace Geometry {
enum class intersection_type { INTERSECT = 0, EQUAL = 1, NOINTERSECTION = -1 };
}

}  // namespace MathLib