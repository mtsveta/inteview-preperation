#pragma once

class Employee{
    std::string firstname;
    std::string lastname;
    int salary;
public:
    Employee(std::string first, std::string last, int sal) :
            firstname(first), lastname(last), salary(sal){

    }
    int getSalary() const {return salary;}
    std::string getSortingName() const {
        return firstname + " " + lastname;
    }
};