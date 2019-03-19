//
// Created by Kamil Motyka on 03.07.2018.
//

#include "Villager.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Villager::Villager() {
    this->age = rand() % 101;
    string names[] = {"andrew", "john", "jannet", "alex", "onufry"};
    this->name = names[rand() % 4];
    this->maxAge = age + rand() % 50;
    this->sex = rand() % 2;
    cout << "born " << this->name << endl;

}

Villager::Villager(string name, int age, int maxAge) {
    this->age = age;
    this->name = name;
    this->maxAge = maxAge;
    srand((unsigned) time(0));
    this->sex = rand() % 2;
    cout << "born " << this->name << endl;
}

void Villager::info() {
    cout << "age " << this->age << " name : " << this->name << " max age : " << this->maxAge << " sex : " << this->sex
         << endl;
}

Villager::~Villager() {
    cout << "died: " << this->name << endl;
}

void Villager::up() {
    if (this->age >= this->maxAge) {
        delete this;
    } else if (this->age == this->maxAge) {
        delete this;
    } else {
        this->age++;

    }

}

