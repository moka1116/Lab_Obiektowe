//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_PERSON_H
#define PROG2_PERSON_H

#include <iostream>

using namespace std;
class Person {
protected:
    string name;
public:
    void ident();

    void setName(const string &name);
};



#endif //PROG2_PERSON_H
