#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator(){
            current = new Node<T>;
        };
        BidirectionalIterator(Node<T>* temp){
            current = new Node<T>;
            current = temp;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> temp){
            BidirectionalIterator<T> temp2(temp.current);
            return temp2;
        };

        bool operator!=(BidirectionalIterator<T> temp){
            return temp.operator*() != current->data;
        };

        BidirectionalIterator<T> operator++(){
            BidirectionalIterator<T> temp(this->current->next);
            return temp;
        };

        BidirectionalIterator<T> operator--(){
            BidirectionalIterator<T> temp(this->current->prev);
            return temp;
        };

        T operator*(){
            return current->data;
        };
};

#endif