//
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_TEACHER_H
#define PROG2_TEACHER_H


#include "Person.h"
#include <iostream>
using namespace std;
class Teacher: public Person{
private:
    string title;
public:
    void ident();

    void setTitle(const string &title);
};


#endif //PROG2_TEACHER_H
