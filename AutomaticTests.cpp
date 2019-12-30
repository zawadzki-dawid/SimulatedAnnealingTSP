//
// Created by dawid on 16.12.2019.
//

#include "AutomaticTests.h"

void AutomaticTest::test(vector<string> files, vector<int> values, string filePath, string saveTo, int repeat) {

    srand(time(NULL));

    double cooling = 0.9;

    double temp = 10000000000.0;

    double endTemp = 0.0001;

    saveParametersToFile(cooling, temp, endTemp, saveTo, repeat);

    for(int i=0; i<files.size(); i++){
        std::chrono::time_point<std::chrono::system_clock> start, end;
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        Matrix matrix{files[i], filePath};
        int step = matrix.getMatrixSize()*matrix.getMatrixSize();
        int reduce = 10*matrix.getMatrixSize();
        Annealing annealing{matrix};
        double seconds = 0.0;
        int value = 0;
        int max = 0;
        for(int j=0; j<repeat; j++) {
            vector<int> path;
            for (int i = 0; i < matrix.getMatrixSize(); i++)
                path.push_back(i);
            shuffle(path.begin() + 1, path.end(), default_random_engine(seed));
            start = std::chrono::system_clock::now();
            annealing.annealingAcc(path, cooling, endTemp, temp, step, reduce);
            end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            value += annealing.min();
            if(max < annealing.min())
                max = annealing.min();
            seconds += elapsed_seconds.count();
        }
        double diffrence = (((double)value/(double)repeat - (double)values[i])/(double)values[i])*(double)100;
        double maxDiffrence =  (((double)max - (double)values[i])/(double)values[i])*(double)100;
        saveTestToFile(matrix.getName(), matrix.getMatrixSize(), values[i], value/repeat, diffrence, seconds/(double)repeat, max, maxDiffrence, saveTo);
    };
}

void AutomaticTest::saveParametersToFile(double cooling, double temp, double endTemp, string saveTo, int repeat) {
    ofstream file;
    file.open(saveTo, ios::app);
    file<<"Poczatkowa temperatura: "<<temp<<endl;
    file<<"Temperatura schladzania: "<<cooling<<endl;
    file<<"Temperatura koncowa: "<<endTemp<<endl;
    file<<"Ilosc poworzen kazdej proby: "<<repeat<<endl;
    file<<endl;
    file.close();
}

void AutomaticTest::saveTestToFile(string fileName, int size, int realMin, int calculatedMin, double diffrence, double time, int max, double maxDiffrence, string saveTo) {
    ofstream file;
    file.open(saveTo, ios::app);
    file<<"Nazwa pliku: "<<fileName<<endl;
    file<<"Rozmiar problemu: "<<size<<endl;
    file<<"Optymalny wynik: "<<realMin<<endl;
    file<<"Sredni wynik: "<<calculatedMin<<endl;
    file<<"Srednia roznica procentowa: "<<diffrence<<endl;
    file<<"Najwiekszy wynik: "<<max<<endl;
    file<<"Najwieksza roznica procentowa: "<<maxDiffrence<<endl;
    file<<"Sredni czas: "<<time<<endl;
    file<<endl;
    file.close();
}