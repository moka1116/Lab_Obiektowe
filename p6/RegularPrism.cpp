//
// Created by Kamil Motyka on 05.07.2018.
//

#include "RegularPrism.h"
namespace poly {
   float RegularPrism::volume() {
        return getbArea() * getheight();
    }

    RegularPrism::RegularPrism(float bLength, float height, int quant): RegularPolyhedron(bLength, height, quant)  {

    }
}