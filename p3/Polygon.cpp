//
// Created by Kamil Motyka on 04.07.2018.
//

#include <algorithm>
#include "Polygon.h"

Polygon::Polygon(Polygon &p) {
    actCap=p.actCap;
    maxCap=p.maxCap;

    ind=new point[actCap];
    std::copy(p.ind,p.ind+actCap,this->ind);

}
Polygon::Polygon() {
    maxCap=4;
    actCap=0;
    ind= new point[4];
}
Polygon::Polygon(int cap) {
    if (cap % 4 == 0) {
        actCap = 0;
        maxCap = cap;
    } else {
        cap = cap + cap % 4;
        actCap = 0;
        maxCap = cap;
    }
}
Polygon::~Polygon() {
    free(ind);
}
void Polygon::add(point a) {
    if(actCap<maxCap){
        ind[actCap+1]=a;
    }else maxCap+=4;
}

Polygon::point &Polygon::polygon(int index) {
    return ind[index];
}





