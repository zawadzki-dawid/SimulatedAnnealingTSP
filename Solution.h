//
// Created by dawid on 25.11.2019.
//

#ifndef SIMANNEALING_SOLUTION_H
#define SIMANNEALING_SOLUTION_H

#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    Solution()=default;
    explicit Solution(int);
    void addNode(int node, int value);
    void addNode(int node);
    void setValue(int value);
    int nodeValue(int i);
    int pathLength();
    int value();
    void print();
    void pop();
    void printReverse();
    void clear();

private:
    std::vector<int> path{};
    int _value;

};

#endif //SIMANNEALING_SOLUTION_H
