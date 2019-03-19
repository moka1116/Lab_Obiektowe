//
// Created by Kamil Motyka on 04.07.2018.
//

#include "Household.h"
#include "Villager.h"
#include <iostream>

void Household::aup() {
    for(int i=0; i<=this->quan; i++){
        if(cap[i]!=nullptr ){
            cap[i]->up();


        }
    }

}