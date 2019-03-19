#include <iostream>
#include <algorithm>

template <typename T>
T min(T *a, T *b){
    T&min= *a;

    for(T *i=a; i<b; i++) {
        if(min>*i)
            min=*i;
    }
    return min;
}
template <typename T>
T mi(T a, T b){
    if(a>b) return a;
    else return b;

}
