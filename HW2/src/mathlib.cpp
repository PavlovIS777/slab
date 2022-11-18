#include <limits>
#include <cmath>
#include <vector>
#include <iostream>
#include "mathlib.h"

using namespace MathLib;

const double DOUBLE_COMPARE_EPSILON = 10e-10;

bool MathLib::doubleCmp(const double &lhv, const double &rhv)
{
    if (std::abs(lhv - rhv) < DOUBLE_COMPARE_EPSILON)
        return true;
    else
        return false;
}

void Matrix::swap_rows(double *const *mat, int width, int firsttRow, int secondRow)
{
    for (int j = 0; j < width; ++j) {
        std::swap(mat[firsttRow][j], mat[secondRow][j]);
    }
}

int Matrix::find_non_zero(const double *const *mat, int width, int row)
{
    int i = 0;
    while (i < width and doubleCmp(mat[row][i], 0)) {
        ++i;
    }

    return i == width ? INT32_MAX : i;
}

void Matrix::print(double *const *mat, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::mul_row(double *const *mat, int width, int row, double mult)
{
    for (int i = 0; i < width; ++i) {
        mat[row][i] *= mult;
    }
}

std::pair<int, double **> Matrix::gaus_elemination(double **mat, int n)
{
    for (int i = 0; i < n; ++i) {
        int index = i;
        std::cout << std::endl;
        int non_zero_i = Matrix::find_non_zero(mat, n + 1, index);
        int non_zero_k = non_zero_i;
        for (int k = i; k < n; ++k) {
            non_zero_k = std::min(non_zero_k, Matrix::find_non_zero(mat, n + 1, k));
            if (non_zero_k != non_zero_i) {
                index = k;
            }
        }
        if (non_zero_i == INT32_MAX) {
            break;
        }

        if (index != i) {
            Matrix::swap_rows(mat, n + 1, index, i);
            non_zero_i = non_zero_k;
        }

        for (int k = i + 1; k < n; ++k) {
            double mult = mat[k][non_zero_i] / mat[i][non_zero_i];
            for (int j = non_zero_i; j < n + 1; ++j) {
                mat[k][j] -= mat[i][j] * mult;
            }
        }
    }

    for (int i = n - 1; i > 0; --i) {
        int j = find_non_zero(mat, n + 1, i);
        if (j != INT32_MAX) {
            double mult = mat[i - 1][j] / mat[i][j];
            for (int k = j; k < n + 1; ++k) {
                mat[i - 1][k] -= mat[i][k] * mult;
            }
        }
    }

    int rank = n;
    for (int i = n - 1; i >= 0; --i) {
        int j = 0;
        while (j <= n && doubleCmp(mat[i][j], 0)) {
            ++j;
        }
        if (j == n + 1) {
            --rank;
        } else if (j == n) {
            return {0, nullptr};
        } else {
            break;
        }
    }

    if (rank == n) {
        double **result = new double *[2];
        result[0] = new double[n];
        for (int i = 0; i < n; ++i) {
            result[0][i] = mat[i][n] / mat[i][i];
        }
        return {n, result};
    }
    for (int k = 0; k < rank; ++k) {
        double mult = 1 / mat[k][k];
        Matrix::mul_row(mat, n + 1, k, mult);
    }

    double **result = new double *[n];
    for (int i = 0; i < n; ++i) {
        result[i] = new double[n - rank + 1] {0};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - rank - 1; j >= 0; --j) {
            result[i][n - rank - 1 - j] = i < rank ? -mat[i][n - j - 1] : (i - rank) == j ? 1 : 0;
        }
    }
    for (int i = 0; i < rank; ++i) {
        result[i][n - rank] = mat[i][n] / mat[i][i];
    }
    return {rank, result};
}
