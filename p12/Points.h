//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_POINTS_H
#define PROG2_POINTS_H

#include <iostream>

using namespace std;
struct point {
    float x;
    float y;
};

istream &operator>>(istream &is, point &p);

ostream &operator<<(ostream &os, point &p);

class Points{
    point *arr;
    int size;
ostream &operator<<(ostream &os,Points &p);


};

#endif //PROG2_POINTS_H
