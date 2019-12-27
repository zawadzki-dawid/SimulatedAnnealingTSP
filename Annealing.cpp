//
// Created by dawid on 25.11.2019.
//

#include "Annealing.h"
#include "chrono"

std::default_random_engine generator;

std::uniform_real_distribution<double> distribution(0.0,1.0);

Annealing::Annealing(const Matrix &matrix) : matrix(matrix){
    _min = INT_MAX;
}

int Annealing::min() const {
    return _min;
}

bool Annealing::accept(int min, int minC, double temp) {
    if (minC <= min) {
        if(minC < _min)
            _min = minC;
            return true;
    } else {
        double prob = exp((min - minC) / temp);
        double dist = distribution(generator);
        if ( dist < prob) {
            return true;

        }
    }
    return false;
}

void Annealing::invert(vector<int> & path, int start, int end) {
    int level = 0;
    for (int i = start; i <= end - level; i++) {
        swap(path[i], path[end - level]);
        level++;
    }
}

int Annealing::countSetCost(vector<int> & path, int start, int end) const {
    int sum = 0;
    for(int i=start-1; i<end; i++)
        sum+=matrix[path[i]][path[i+1]];
    if(end == matrix.getMatrixSize() - 1)
        sum+=matrix[path[end]][0];
    else
        sum+=matrix[path[end]][path[end+1]];
    return sum;
}

void Annealing::annealingInvert(vector<int> path, double cooling, double endTemp, double temp, int step){
    srand(time(NULL));
    vector<int> pathC(path);
    int min = matrix.pathValue(path);
    int minC;
    int start;
    int end;
    int stepLength =  matrix.getMatrixSize()*matrix.getMatrixSize();
    int noChangeCounter;
    while(temp > endTemp) {
        noChangeCounter = 0;
        for (int i = 0; i < stepLength; i++) {
            start = rand() % (matrix.getMatrixSize() - 2) + 1;
            end = rand() % (matrix.getMatrixSize() - start - 1) + start + 1;
            invert(pathC, start, end);
            minC = matrix.pathValue(path);
            if (accept(min, minC, temp)) {
                min = minC;
                path = pathC;
            }else{
                pathC = path;
                noChangeCounter++;
            }
        }
        temp *= cooling;
        if(noChangeCounter == stepLength) {
            break;
        }
    }
}

void Annealing::annealingAcc(vector<int> path,double cooling, double endTemp, double temp, int step, int reduce){
    srand(time(NULL));

    vector<int> pathC(path);

    int min = matrix.pathValue(path);

    int minC = min;

    int start;

    int end;

    int noChangeCounter;
    int changeCounter;

    while(temp > endTemp) {
        noChangeCounter = 0;
        changeCounter = 0;
        for (int i = 0; i < step; i++) {
            start = rand() % (matrix.getMatrixSize() - 2) + 1;

            end = rand() % (matrix.getMatrixSize() - start - 1) + start + 1;

          /*  if(end < (matrix.getMatrixSize()-1))
                minC -= (matrix[pathC[start - 1]][pathC[start]] + matrix[pathC[end]][pathC[end + 1]]);
            else
                minC -= (matrix[pathC[start - 1]][pathC[start]] + matrix[pathC[end]][0]);*/

            invert(pathC, start, end);

            minC = matrix.pathValue(pathC);

            /*if(end < (matrix.getMatrixSize()-1))
                minC += (matrix[pathC[start - 1]][pathC[start]] + matrix[pathC[end]][pathC[end + 1]]);
            else
                minC += (matrix[pathC[start - 1]][pathC[start]] + matrix[pathC[end]][0]);*/

            if (accept(min, minC, temp)) {
                min = minC;

                path = pathC;
                noChangeCounter = 0;
                changeCounter++;
            }else{
                pathC = path;

                minC = min;

                noChangeCounter++;
                changeCounter = 0;
            }
            if(changeCounter == reduce)
                break;
        }
        if(noChangeCounter == step)
            break;
        temp *= cooling;

    }
}

void Annealing::annealingAccAsym(vector<int> path, double cooling, double endTemp, double temp, int step, int reduce){
    srand(time(NULL));
    vector<int> pathC(path);
    int min = matrix.pathValue(path);
    int minC = min;
    int start;
    int end;
    int noChangeCounter;
    int changeCounter;
    while(temp > endTemp) {
        noChangeCounter = 0;
        changeCounter = 0;
        for (int i = 0; i < step; i++) {
            start = rand() % (matrix.getMatrixSize() - 2) + 1;
            end = rand() % (matrix.getMatrixSize() - start - 1) + start + 1;
            minC -= countSetCost(pathC, start, end);
            invert(pathC, start, end);
            minC += countSetCost(pathC, start, end);
            if (accept(min, minC, temp)) {
                min = minC;
                path = pathC;
                noChangeCounter = 0;
                changeCounter++;
            }else{
                pathC = path;
                minC = min;
                  noChangeCounter++;
                  changeCounter = 0;
            }
            if(changeCounter == reduce)
                break;
        }
        if(noChangeCounter == step)
          break;
        temp *= cooling;

    }
}