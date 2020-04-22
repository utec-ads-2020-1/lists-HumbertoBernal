#ifndef STACK_H
#define STACK_H

#include <exception>
#include <iostream>

using namespace std;

#define MAX 1000

template <typename T>
class stack {
    T* data;
    int Top;
    int capacity;

public:
    stack(int size = MAX){
        data = new T(size);
        capacity = size;
        Top = 0;
    };

    ~stack(){
        data = nullptr;
        delete [] data;
    };

    void push(T value){
        if(capacity == Top){
            cout <<"The stack is full";
            throw exception();
        } else{
            if(size() != 0){data++;}
            *data = value;
        }
        Top++;
    };

    void pop(){
        data--;
        Top--;
    };

    int top(){
        return *data;
    };

    int size(){
        return Top;
    };

    bool empty(){
        return Top==0 ;
    };

};


#endif