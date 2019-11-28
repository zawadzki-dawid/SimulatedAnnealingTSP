//
// Created by dawid on 25.11.2019.
//

#include "Solution.h"

Solution::Solution(int size) {
    path.reserve(size);
    _value = INT_MAX;
}

void Solution::addNode(int node, int value) {
    path.push_back(node);
    _value+=value;
}

void Solution::addNode(int node) {
    path.push_back(node);
}

void Solution::setValue(int value){
    _value = value;
}

int Solution::value() {
    return _value;
}

void Solution::print() {
    for(auto e : path)
        std::cout<<e<<" ";

}

void Solution::pop(){
    path.pop_back();
}

void Solution::printReverse() {
    for(int i= pathLength()-1;i>=0;i--)
        std::cout<<path[i]<<" ";

}

void Solution::clear() {
    path.clear();
    _value = 0;

}

int Solution::nodeValue(int i){
    return path[i];
}

int Solution::pathLength() {
    return path.size();
}
