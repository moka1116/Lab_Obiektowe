#include <iostream>
#include <list>
#include <map>
using namespace std;

template <typename T>
map<T,int> fun(list<T> lista){
    int value=0;
    for (typename list<T>::iterator it=lista.begin(); it!=lista.end(); it++)

    {
        value++;

    }
    map<T,int> a;
    T b;
    a[b]=value;

    return a;

};
template <typename T>
map<string,int> fun(list<string>){


};

int main(){

    return 0;
}