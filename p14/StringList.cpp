//
// Created by Kamil Motyka on 06.07.2018.
//
#include <iostream>
#include "StringList.h"
#include <list>
using namespace std;

list<string> StringList::operator+(const StringList &l, string a) {
    l.lista.push_back(a);
}

list<string> StringList::operator-(const StringList &l, string a) {
    for(typename &l.lista<string>::iterator it=l.lista.begin(); it!= l.lista.end(); it++){
        //for (typename list<T>::iterator it=lista.begin(); it!=lista.end(); it++)

    }


}
