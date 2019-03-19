//
// Created by Kamil Motyka on 03.07.2018.
//

#ifndef PROG2_VILLAGER_H
#define PROG2_VILLAGER_H

#include <iostream>

using namespace std;
class Villager {
private:
    string name;
    int age;
    int maxAge;
    bool sex;
public:
    Villager();

    ;
    Villager(string name,int age, int maxAge);
    void info();
    void up();
    ~Villager();
};

#endif //PROG2_VILLAGER_H
