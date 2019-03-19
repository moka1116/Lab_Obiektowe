//
// Created by Kamil Motyka on 05.07.2018.
//

#include "Student.h"
#include <iostream>

void Student::ident() {
    std::cout<<"name "<<this->name<<" parametr: "<< this-> term<< std::endl;
}

void Student::setTerm(int term) {
    Student::term = term;
}

