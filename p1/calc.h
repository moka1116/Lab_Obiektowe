//
// Created by Kamil Motyka on 03.07.2018.
//

#ifndef PROG2_CALC_H
#define PROG2_CALC_H


class calc {
private:
    float a;
    float b;
    float c;
public:
    void setCoff(float a, float b, float c);
    bool isR(float a);
    bool isZ(float a);
    float x1();
    float x2();
    float delta();

};


#endif //PROG2_CALC_H
