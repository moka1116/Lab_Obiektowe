#include <iostream>
#include <list>
#include <map>
using namespace std;

template <typename T> list<T> fun(list<T> lista){
    int value=3;
    for (typename list<T>::iterator it=lista.begin(); it!=lista.end(); it++)

    {
        if(*it>value){
            lista.push_back(*it);
        }

    }
     return lista;

};
template <typename T> list<T> fun(list<string> list){


}



int main(){
    list<int> ando={1,4,5,6,1,3};



    return 0;
}