#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator(){
            current = new Node<T>;
        };

        ForwardIterator(Node<T>* temp){
            current = new Node<T>;
            current = temp;
        };

        ForwardIterator<T> operator=(ForwardIterator<T>* temp){
            ForwardIterator<T> temp2(temp->current);
            return temp2;
        };

        bool operator!=(ForwardIterator<T> temp){
            return temp.operator*() != current->data;
        };

        ForwardIterator<T> operator++(){
            ForwardIterator<T> temp(this->current->next);
            return temp;
        };

        T operator*(){
            return current->data;
        };
};

#endif