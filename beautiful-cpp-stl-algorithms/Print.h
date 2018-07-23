#pragma once
#include <iostream>
//#include "Resource.h"
//#include "Employee.h"

void printVector(std::vector<int>& v) {

    std::for_each(begin(v), end(v), [](const int elem) {
        std::cout << elem << ", ";
    });
    std::cout << std::endl;
}

void printVector(std::deque<int>& v) {

    std::for_each(begin(v), end(v), [](const int elem) {
        std::cout << elem << ", ";
    });
    std::cout << std::endl;
}
void printVector(std::vector<Resource>& v){

    std::for_each(begin(v), end(v), [](Resource & r){
        std::cout << r.getValue() << ", ";
    });
    std::cout << std::endl;
}

void printVector(std::vector<Employee>& v){

    std::for_each(begin(v), end(v), [](Employee & r){
        std::cout << r.getSortingName() << " with salary " << r.getSalary() <<  std::endl;
    });
   
}