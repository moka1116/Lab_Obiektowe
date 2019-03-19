//
// Created by Kamil Motyka on 11/10/2018.
//

#include <iostream>
int main(){
        int length=8;
        int current;
        int i;
    int x[8]={8,9,5,3,1,7,2,1};
        for (int j = 1; j < length; j++) {
            current = x[j];
            i = j - 1;
            while (current> x[i] && i >= 0) {
                x[i + 1] = x[i];
                i--;
            }
            x[i + 1] = current;
        }
    for(int i=0; i<=7; i++){
        std::cout<<x[i]<<std::endl;
    }
    };
