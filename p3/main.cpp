//
// Created by Kamil Motyka on 03.07.2018.
//

#include <iostream>
#include "Polygon.h"

using namespace std;
int main(){

    Polygon a;
    Polygon b(23);
    a.add(Polygon::point{2,3});
    a.polygon(2);


    return 0;
}