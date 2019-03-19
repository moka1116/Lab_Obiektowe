//
// Created by Kamil Motyka on 05.07.2018.
//

#include "Person.h"
void Person::ident() {
    std::cout<<"name "<<this->name<< std::endl;}

void Person::setName(const string &name) {
    Person::name = name;
}
