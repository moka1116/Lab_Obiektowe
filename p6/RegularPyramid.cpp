//
// Created by Kamil Motyka on 05.07.2018.
//

#include "RegularPyramid.h"
namespace poly {
    float RegularPyramid::volume() {
        return (float) 1. / 3 * getbArea() * getheight();
    }

    RegularPyramid::RegularPyramid(float bLength, float height, int quant) : RegularPolyhedron(bLength, height, quant) {

    }

}