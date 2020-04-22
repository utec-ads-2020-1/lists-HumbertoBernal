#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class queue {
    T* data;
    int top;
    int capacity;

public:
    queue(int size = MAX){
        data = new T(size);
        capacity = size;
        top = 0;
    };

    ~queue(){
        data = nullptr;
        delete [] data;
    };

    void goBackwardTo(int size){
        for (int i = 0; i < size ; ++i){data--;}
    };
    void goForwardTo(int size){
        for (int i = 0; i < size ; ++i){data++;}
    };

    void push(T value){
        if(capacity == top ){
            capacity *= 2;
            T* temp = new T(capacity);
            for (int i = 0; i < top; ++i) {
                *temp = *data;
                temp++;
                data++;
            }
            data = temp;
            data++;
            *data = value;
            top++;
            delete temp;
            goBackwardTo(top);
        } else{
            if (top != 0){goForwardTo(top);}
            *data = value;
            if (top != 0){goBackwardTo(top);}
            top++;

        }
    };

    void pop(){
        if(empty()){
            std::cout << "Can't pop, the queue is empty"<<endl;
            throw std::exception();
        }else{
            top--;
        }
    };

    int front(){
        return *data;
    };
    int back(){
        if(top != 0){goForwardTo(top-1);}
        return *data;

    };

    int size(){
        return top;
    };
    bool empty(){
        return top==0;
    };
};

#endif