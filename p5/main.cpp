//
// Created by Kamil Motyka on 05.07.2018.
//
#include "Student.h"
#include "Teacher.h"
#include "Person.h"
int main(){
    Person a;
    Teacher b;
    Student c;

    a.setName("Person");
    b.setName("Teacher");
    b.setTitle("pro");
    c.setName("Student");
    c.setTerm(2);

    a.ident();
    b.ident();
    c.ident();

    return 0;
}