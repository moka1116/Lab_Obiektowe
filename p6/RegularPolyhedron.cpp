//
// Created by Kamil Motyka on 05.07.2018.
//

#include <cmath>
#include "RegularPolyhedron.h"
namespace poly {

    double bAreac(int number, float length) {
        return 1. / 4 * number * length * length * 1 / tan(M_PI / number);
    }

    RegularPolyhedron::RegularPolyhedron(float bLength, float height, int quant) {
        this->bLength = bLength;
        this->height = height;
        this->quant = quant;
        this->bArea = (float) bAreac(quant, bLength);
    }

    float RegularPolyhedron::getbArea() {
        return this->bArea;

    }

    float RegularPolyhedron::getheight() {
        return this->height;
    }


}