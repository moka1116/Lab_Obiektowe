//
// Created by Kamil Motyka on 04.07.2018.
//

#include "Point.h"

namespace pt {
    Point::Point() {
        this->y = 0;
        this->x = 0;
    }

    Point::Point(int a, int b) {
        this->x = a;
        this->y = b;
    }

    int Point::getA() {
        return this->x;
    }

    int Point::getB() {
        return this->y;
    }

    void Point::setA(int a) {
        this->x = a;
    }

    void Point::setB(int b) {
        this->y = b;
    }


}