//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_REGULARPYRAMID_H
#define PROG2_REGULARPYRAMID_H


#include "RegularPolyhedron.h"
namespace poly {
    class RegularPyramid : public RegularPolyhedron {

    public:
        RegularPyramid(float bLength, float height, int quant);

        float volume();
    };
}


#endif //PROG2_REGULARPYRAMID_H
