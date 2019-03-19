//
// Created by Kamil Motyka on 03.07.2018.
//

#include <iostream>
#include "Villager.h"
#include "Household.h"

using namespace std;
int main(){

  Villager a("Jannet",2,3);
  Villager b;
  a.info();
  b.info();

    int g;
    a.up();
    a.up();

    cin>>g;

    return 0;
}