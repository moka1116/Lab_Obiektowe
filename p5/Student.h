//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_STUDENT_H
#define PROG2_STUDENT_H

#include <iostream>
#include "Person.h"

class Student: public Person {
public:
    int term;
    void ident();

    void setTerm(int term);
};


#endif //PROG2_STUDENT_H
