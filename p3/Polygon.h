//
// Created by Kamil Motyka on 04.07.2018.
//

#ifndef PROG2_POLYGON_H
#define PROG2_POLYGON_H


class Polygon {
public:
    struct point {
        float x;
        float y;
    };

    Polygon();

    Polygon(int cap);

    Polygon(Polygon &p);

    ~Polygon();

    void add(point a);

    point &polygon(int index);

private:
    point *ind;
    int maxCap;
    int actCap;
};


#endif //PROG2_POLYGON_H
