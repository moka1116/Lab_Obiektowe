
// Created by Kamil Motyka on 05.07.2018.
//

#ifndef PROG2_LIST_H
#define PROG2_LIST_H
template <typename T>
class List{
    struct Node{
        T value;
        Node *next;
    };
    Node *head, *tail;
public:
    class iterator{
        Node *ptr;
    public:
    iterator(Node *ptr) {
        this->ptr=ptr;
    }
        T operator*(){
            return ptr->value;
        }
    T *operator->(){
        return &(ptr->value);
    }
    bool operator ==(const iterator &right){
        return ptr==right.ptr;
    }
    bool operator !=(const iterator &right){
        return ptr!=right.ptr;
    }
    iterator operator++(){
        ptr=ptr->next;
        return *this;
    }
    iterator operator++(int){
        iterator temp=*this;
        ptr=ptr->next;
        return temp;
    }
    };
    List();
    ~List();
    bool empty();
    int size();
    T front;
    T back;










};




#endif //PROG2_LIST_H
