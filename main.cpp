#include <iostream>
#include "AutomaticTests.h"
#include <string>

using namespace std;

int main() {

    vector<string> symList={"data10.txt", "data11.txt", "data12.txt", "data13.txt", "data14.txt", "data15.txt", "data16.txt", "data18.txt", "data21.txt", "data24.txt", "data26.txt", "data29.txt", "data42.txt", "data58.txt", "data120.txt"};
    vector<string> asymList={"data323.txt", "data358.txt", "data403.txt", "data443.txt"};
    vector<int> symValues={212, 202, 264, 269, 125, 291, 156, 187, 2707, 1272, 937, 1610, 699, 25395, 6942};
    vector<int> asymValues={ 1326, 1163, 2465, 2720};

    AutomaticTest symAnnealing;

    string filePath = "../DATA/SYM/";

    symAnnealing.test(symList, symValues, filePath, "../DATA/RESULTS/sym_acc_sym_10_no_acc.txt", 10);

    return 0;
}