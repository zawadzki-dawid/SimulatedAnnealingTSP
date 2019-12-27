//
// Created by dawid on 25.11.2019.
//

#ifndef SIMANNEALING_MATRIX_H
#define SIMANNEALING_MATRIX_H

#include <vector>
#include <string>
#include "Matrix.h"
#include "fstream"
#include <iostream>

using namespace::std;

class Matrix{
    string matrixName;

    int matrixSize;

    int** matrix;

    int* shortestPath;


public:
    int* const &operator[] (int) const;

    Matrix(string, string);

    ~Matrix();

    string getName();

    int getMatrixSize() const;

    void printMatrix();

    int pathValue(vector<int>) const;

};

#endif //SIMANNEALING_MATRIX_H
