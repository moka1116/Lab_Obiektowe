//
// Created by Kamil Motyka on 06.07.2018.
//

#ifndef PROG2_STRINGLIST_H
#define PROG2_STRINGLIST_H

#include <iostream>
#include <list>
using namespace std;

class StringList {
public:
    list<string>lista;
   friend list<string> operator+(const StringList &l,string a);
   friend list<string> operator-(const StringList &l,string a);
};


#endif //PROG2_STRINGLIST_H
