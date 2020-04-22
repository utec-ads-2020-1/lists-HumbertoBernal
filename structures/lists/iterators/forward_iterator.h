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
            current = temp;
        };

        ForwardIterator<T> operator=(ForwardIterator<T> temp){
            this->current = temp.current;
        };

        bool operator!=(ForwardIterator<T> temp){
            return  temp.current != this->current;
        };

        ForwardIterator<T> operator++(){
            this->current = this->current->next;
        };

        T operator*(){
            return this->current->data;
        };
};

#endif