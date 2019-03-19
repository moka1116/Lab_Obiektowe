//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_REGULARPOLYHEDRON_H
#define PROG2_REGULARPOLYHEDRON_H

namespace poly {
    class RegularPolyhedron {
    private:
        float bLength, bArea, height;
        int quant;
    public:
        RegularPolyhedron(float bLength, float height, int quant);

        RegularPolyhedron();

        virtual float volume()=0;

    protected:
        float getbArea();

        float getheight();
    };

}
#endif //PROG2_REGULARPOLYHEDRON_H
