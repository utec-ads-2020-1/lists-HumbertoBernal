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
            // Retornas el parámetro?
            this->current = temp.current;
            return temp;
        };

        bool operator!=(BidirectionalIterator<T> temp){
                return temp.current != current;
        };

        BidirectionalIterator<T> operator++(){
            // Si current es null?
            current = current->next;
            return *this;
        };

        BidirectionalIterator<T> operator--(){
            // Si current es null?
            current = current->prev;
            return *this;
        };

        T operator*(){
            // Si current es null?
            return current->data;
        };
};

#endif