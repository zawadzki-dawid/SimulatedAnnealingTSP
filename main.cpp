#include <iostream>
#include "Matrix.h"
#include "Annealing.h"
#include <chrono>
#include <algorithm>

int main() {

    srand(time(NULL));

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    Matrix matrix{"data58.txt"};

    vector<int> path;

    double cooling = 0.9;

    double temp = 10000000000.0;

    double endTemp = 0.0001;

    int step = matrix.getMatrixSize()*matrix.getMatrixSize();

    int reduce = 10*matrix.getMatrixSize();

    for(int i=0 ; i<matrix.getMatrixSize(); i++)
        path.push_back(i);

    shuffle(path.begin()+1, path.end(), default_random_engine(seed));

    Annealing annealing{matrix};

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();

    annealing.annealingAccAsym(path, cooling, endTemp, temp, step, reduce);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";

    cout<<annealing.min()<<endl;

    return 0;
}