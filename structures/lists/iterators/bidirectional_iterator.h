#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator()= default;

        explicit BidirectionalIterator(Node<T>* temp){
            current = temp;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> temp){
            this->current = temp.current;
            return temp;
        };

        bool operator!=(BidirectionalIterator<T> temp){
            if(temp.current == nullptr or this->current == nullptr){
                return temp.current != this->current;
            }else{
                return *temp != current->data;
            }
        };

        BidirectionalIterator<T> operator++(){
            current = current->next;
            return *this;
        };

        BidirectionalIterator<T> operator--(){
            current = current->prev;
            return *this;
        };

        T operator*(){
            return current->data;
        };
};

#endif