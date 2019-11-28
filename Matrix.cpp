//
// Created by dawid on 25.11.2019.
//

#include "Matrix.h"

// --------------Desctructor-------------------------------------

Matrix::~Matrix() {
    delete [] matrix;
    delete [] shortestPath;
}

// --------------Constructor-------------------------------------

Matrix::Matrix(string fileName) {

    ifstream file;
    file.open("../PEA/SMALL/"+fileName, ios::out);
    file >> matrixName;
    file >> matrixSize;
    shortestPath = new int[matrixSize];
    if(file.is_open()){
        matrix = new int*[matrixSize];
        for(int i=0; i<matrixSize; i++) {
            shortestPath[i] = 0;
            matrix[i] = new int[matrixSize];
            for (int j = 0; j < matrixSize; j++)
                file >> matrix[i][j];
        }
    }
    else{
        cout<<"File cannot be open!"<<endl;
    }
}

// --------------Matrix Print-------------------------------------

void Matrix::printMatrix() {

    for(int i=0; i<matrixSize;i++){
        for(int j=0; j<matrixSize; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

// --------------Matrix Size-------------------------------------

int Matrix::getMatrixSize() const {
    return matrixSize;
}

// --------------Matrix Name-------------------------------------

std::string Matrix::getName() {
    return matrixName;
}

// --------------Path Value-------------------------------------------

int Matrix::pathValue(int* arr) const{

    int min = 0;
    for(int i=0;i<matrixSize-1;i++)
        min+=matrix[arr[i]][arr[i+1]];
    min+=matrix[arr[matrixSize-1]][0];
    return min;

}

int Matrix::pathValue(vector<int> vec) const{

    int min = 0;
    for(int i=0;i<matrixSize-1;i++)
        min+=matrix[vec[i]][vec[i+1]];
    min+=matrix[vec[matrixSize-1]][0];
    return min;

}

int* const &Matrix::operator[](int i) const{
    return matrix[i];
}