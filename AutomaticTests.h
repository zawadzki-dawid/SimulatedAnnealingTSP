//
// Created by dawid on 16.12.2019.
//

#ifndef SIMANNEALING_AUTOMATICTESTS_H
#define SIMANNEALING_AUTOMATICTESTS_H

#include <string>
#include <vector>
#include "Matrix.h"
#include "Annealing.h"
#include <chrono>
#include <algorithm>

using namespace::std;

class AutomaticTest{

public:
    void test(vector<string>, vector<int>, string, string, int);

    void saveParametersToFile(double, double, double, string, int);

    void saveTestToFile(string, int, int, int, double, double, int, double, string);

};

#endif //SIMANNEALING_AUTOMATICTESTS_H
