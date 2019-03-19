//
// Created by Kamil Motyka on 05.07.2018.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "../p8/Point.h"
bool compareX(const Point &p,const Point &q){
    return p.x < q.x;
}
bool compareY(const Point &p,const Point &q){
    return p.y < q.y;
}
using namespace std;
int main(){
    Point a(3,3);
    Point b(2,11);
    Point c(1,118);
    vector<Point>Alpha;
    Alpha.push_back(a);
    Alpha.push_back(b);
    Alpha.push_back(c);


    cout<<"standard "<<endl;
    cout<<endl;
    for(Point p: Alpha){
        cout<<p.x<<" "<<p.y<<endl;
    }
    sort(Alpha.begin(),Alpha.end(),compareX);
    cout<<"po X "<<endl;
    cout<<endl;

    for(Point p: Alpha){
        cout<<p.x<<" "<<p.y<<endl;
    }
    cout<<"po Y "<<endl;
    cout<<endl;

    sort(Alpha.begin(),Alpha.end(),compareY);
    for(Point p: Alpha){
        cout<<p.x<<" "<<p.y<<endl;
    }
    cout<<endl;
    return 0;
}