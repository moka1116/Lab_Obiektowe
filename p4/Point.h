//
// Created by Kamil Motyka on 04.07.2018.
//

#ifndef PROG2_POINT_H
#define PROG2_POINT_H

namespace pt {
    class Point {
    private:
        int x;
        int y;
    public:
        Point();
        Point(int a,int b);
        int getA();
        int getB();
        void setA(int a);
        void setB(int b);
    };
}


#endif //PROG2_POINT_H
