#include<iostream>
#include<vector>
#include <map>
using namespace std;
class Compare {
    int num;
public:
    explicit Compare(int num) : num(num) {};

    bool operator()(int a, int b) {
        map<int, int> mapA;
        map<int, int> mapB;
        while (a > 0) {
            mapA[a % 10]++;
            a /= 10;
        }
        while (b > 0) {
            mapB[b % 10]++;
            b /= 10;
        }
        return mapA[num] < mapB[num];
    }

    void fun(vector<int>::iterator it1, vector<int>::iterator it2, int num) {
        Compare compare(num);
        sort(it1, it2, compare);
    }

    void foo6v2(vector<int>::iterator iter1, vector<int>::iterator iter2, int num) {
        if (num > 9 || num < 0) throw num;
        Compare compare(num);
        sort(iter1, iter2,
             [num](int a, int b) // w nawiasam kwadratowych mowimu do jakis zmiennych ma miec dostêp nasza lambda
                     //w nawiasach okr¹g³ych definiujemy parametry tak jak w zwyklej funkcji
                     //w klamrach cia³o naszej funkcji
             {
                 //robi dokladnie to co funktor
                 map<int, int> mapA;
                 map<int, int> mapB;
                 while (a > 0) {
                     mapA[a % 10]++;
                     a /= 10;
                 }
                 while (b > 0) {
                     mapB[b % 10]++;
                     b /= 10;
                 }
                 return mapA[num] < mapB[num];
             });
    }

    void fun3(vector<int>::iterator it1, vector<int>::iterator it2, int num){
        bool coperator(int a,int b, int num){
                map<int,int>mapA;
                map<int,int>mapB;

                while(a>0){
                    mapA[a%10]++;
                    a/=10;
                }
            while(b>0){
                mapB[b%10]++;
                b/=10;
            }
        return mapA[num]<mapB[num];
        }

    if(9>num|| num<0)throw num;
        auto f=bind(coperator,placeholders::_1,placeholders::_2,num);
        sort(it1,it2,f);


    }


};


