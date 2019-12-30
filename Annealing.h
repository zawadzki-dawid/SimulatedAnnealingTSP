//
// Created by dawid on 25.11.2019.
//

#ifndef SIMANNEALING_ANNEALING_H
#define SIMANNEALING_ANNEALING_H

#include "Matrix.h"
#include "Solution.h"
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>

using namespace::std;

class Annealing{
public:
    Annealing(const Matrix &matrix);

    int min() const;

    void annealingInvert(vector<int>, double, double, double, int);

    void annealingAcc(vector<int>, double, double, double, int, int);

    void annealingAccAsym(vector<int>, double, double, double, int, int);

private:
    const Matrix& matrix;

    int _min;

    bool accept(int, int, double);

    void invert(vector<int> &, int, int);

    int countSetCost(vector<int> &, int, int) const;

};


#endif //SIMANNEALING_ANNEALING_H
