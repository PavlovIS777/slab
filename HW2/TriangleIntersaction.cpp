#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "mathlib.h"
#include "vector3d.h"
#include "plane.h"
#include "line3d.h"

double** initMat(int size) {
    srand(time(nullptr));
    double** mat = new double*[size];
    for (int i = 0; i < size; ++i) {
        mat[i] = new double[size + 1];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size + 1; ++j) {
            std::cin >> mat[i][j];
            //mat[i][j] = std::abs(rand() % 10);
        }
    }
    return mat;
}

void print_Gaus_answ(std::pair<int, double**> res, int size) {
    int rank = res.first;
    double** mat = res.second;
    std::setprecision(5);
    if (rank == size) {
        for (int i = 0; i < size; ++i) {
            std::cout << mat[0][i] << std::endl;
        }
    }
    else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size - rank + 1; ++j) {
                if (j < size - rank) {
                    std::cout << mat[i][j] << " ";
                } else {
                    std::cout << "   " << mat[i][j];
                }
            }
            std::cout << std::endl;
        }
    }
}

int main()
{
    return 0;
}
