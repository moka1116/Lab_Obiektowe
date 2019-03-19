//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_REGULARPRISM_H
#define PROG2_REGULARPRISM_H


#include "RegularPolyhedron.h"
namespace poly {
    class RegularPrism : public RegularPolyhedron {

    public:
        RegularPrism(float bLength, float height, int quant);

       virtual float volume() ;
    };
}

#endif //PROG2_REGULARPRISM_H
