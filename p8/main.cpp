#include <iostream>
#include "Point.h"
#include <vector>
#include <cmath>
using namespace std;

vector<Point> checker(const Point & a, const Point & b, const vector<Point>& vec){
vector<Point> result;
    for(Point c : vec){
        if(c.x >= a.x && c.y>= a.y && c.x <= b.x && c.y <=b.y){
            result.push_back(c);
        }
    }

    return result;
}

int main(){
    vector<Point> Marzena;
    Point a(2,3),b(3,2),c(8,11),d(1,1),e(4,5),f(280,100);
    Marzena.push_back(d);
    Marzena.push_back(b);
    Marzena.push_back(c);
    Marzena.push_back(e);

    vector<Point> res= checker(a, f,Marzena);

    for(Point p : res){
        cout<<p.x<<" "<<p.y<<endl;
    }

    return 0;
}