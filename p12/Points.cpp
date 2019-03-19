//
// Created by Kamil Motyka on 05.07.2018.
//

#include "Points.h"
istream& operator>>(istream& is, point& p){
    is >>p.x;
    is >>p.y;
    return is;
}
ostream& operator<<(ostream& os, point& p){
    os<< p.x << " " <<p.y;
    return os;
}

ostream &Points::operator<<(ostream &os, Points &p) {
    for(int i=0; i<p.size; i++){
        os<< p.arr[i]<<endl;

    }
    return os;
}
