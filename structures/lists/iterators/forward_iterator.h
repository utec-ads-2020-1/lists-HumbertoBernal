#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator()= default;

        explicit ForwardIterator(Node<T>* temp){
            current = temp;
        };

        ForwardIterator<T> operator=(ForwardIterator<T>* temp){
            ForwardIterator<T> temp2(temp->current);
            return temp2;
        };

        bool operator!=(ForwardIterator<T> temp){
            if(temp.current == nullptr or this->current == nullptr){
                return temp.current != this->current;
            }else{
                return *temp != current->data;
            }
        };

        void operator++(){
            current = current->next;
            };

        T operator*(){
            return current->data;
        };
};

#endif