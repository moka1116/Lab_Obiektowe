//
// Created by Kamil Motyka on 05.07.2018.
//

#include "Teacher.h"
#include <iostream>
void Teacher::ident() {
    std::cout<<"name "<<this->name<<" parametr: "<< this->title << std::endl;
}

void Teacher::setTitle(const string &title) {
    Teacher::title = title;
}
