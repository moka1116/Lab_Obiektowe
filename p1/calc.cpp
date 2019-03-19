//
// Created by Kamil Motyka on 03.07.2018.
//

#include <cmath>
#include "calc.h"

void calc::setCoff(float a, float b, float c) {
    this->a=a;
    this->b=b;
    this->c=c;
}
bool calc::isR(float a) {
    return (a>0);
}
bool calc::isZ(float a) {
    return (a==0);
}
float calc::delta(){
    return (float)pow(b,2)-(4*a*c);
}

float calc::x1() {
    if(isR(delta())){
        return (-b+sqrt(delta()))/2;
    }
    else if(isZ(delta())){
        return (-b)/2*a;
    }
    else return 0;
}

float calc::x2() {
    if(isR(delta())){
        return (-b-sqrt(delta()))/2;
    }
    else return 0;
}