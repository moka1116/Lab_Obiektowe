//
// Created by Kamil Motyka on 05.07.2018.
//
#include <iostream>

#include "RegularPrism.h"
#include "RegularPyramid.h"
using namespace poly;

int main(){
    RegularPrism a(6,1,3);
    RegularPyramid b(8,12,3);

    std::cout<<"volume "<< a.volume()<< std::endl;
    std::cout<<"volume "<< b.volume()<< std::endl;

    return 0;
}
