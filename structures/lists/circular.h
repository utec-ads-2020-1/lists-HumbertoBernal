#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front(){
            if (this->nodes != 0){
                return this->head->data;
            }else{
                throw "There is no front, the ForwardList is empty";
            }
        };

        T back(){
            if (this->nodes != 0){
                return this->tail->data;
            }else{
                throw "There is no back, the ForwardList is empty";
            }
        };

        void push_front(T value){
            auto* temp = new Node<T>;
            temp->data = value;
            temp->next = this->head;
            if(this->nodes == 0){
                this->tail = temp;
            }else{
                this->head->prev = temp;
            }
            this->head = temp;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            this->nodes++;
            temp = nullptr;
            delete temp;
        };

        void push_back(T value){
            auto* temp = new Node<T>;
            temp->data = value;
            if(this->nodes == 0){
                temp->next = this->tail;
                temp->prev = this->head;
                this->head = temp;
            }else{
                temp->next = this->head;
                temp->prev = this->tail;
                this->tail->next = temp;
            }
            this->tail = temp;
            this->head->prev = this->tail;
            this->nodes++;
            temp = nullptr;
            delete temp;
        };

        void pop_front(){
            if(this->nodes > 1 ){
                Node<T>* temp = this->head;
                this->head = this->head->next;
                temp->killSelf();
                temp = nullptr;
                delete temp;
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }else{
                this->head->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->nodes--;
        };

        void pop_back(){
            if(this->nodes > 1){
                Node<T>* temp = this->tail;
                this->tail = this->tail->prev;
                this->tail->next = this->head;
                temp->killSelf();
                temp = nullptr;
                delete temp;
                this->head->prev = this->tail;
            }else{
                this->tail->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->nodes--;
        };

        T operator[](int position){
            position +=1;
            if(position > this->nodes){
                throw "La posición es invalida";
            }else if(position == 1){
                return this->head->data;
            }else if(position <= (this->size()+1)/2){
                Node<T>* temp = this->head;
                for (int i = 0; i < ((position+1)/2); ++i){
                    temp = temp->next;
                }
                return temp->data;
            }else{
                Node<T>* temp = this->tail;
                for (int i = 0; i < (this->size()-position); ++i){
                    temp = temp->prev;
                }
                return temp->data;

            }
        };

        bool empty(){
            return this->nodes == 0;
        };

        int size(){
            return this->nodes;
        };

        void clear(){
            if(this->nodes > 1){
                while (this->head != this->tail){
                    this->pop_front();
                }
            }
            this->pop_front();
        };

        void sort(){
            if (this->nodes > 1){
                Node<T> *temp;
                for (int i = 0; i < this->nodes-1 ; ++i) {
                    temp = this->head;
                    temp->next = this->head->next;
                    for (int j = 0; j < this->nodes-i-1 ; ++j) {
                        if(temp->data > temp->next->data){
                            this->swapL(temp, temp->next);
                        }
                        temp = temp->next;
                    }
                }
            }
        };

        void swapL(Node<T>* A, Node<T>* B){
            auto* temp2 = new Node<T>;
            temp2->data = A->data;
            A->data = B->data;
            B->data = temp2->data;
            temp2 = nullptr;
            delete temp2;
        };

        void reverse(){
            if(this->nodes > 1){
                Node<T> *temp, *temp2;
                temp = this->head;
                temp2 = this->tail;
                for (int i = 0; i < (this->nodes)/2 ; ++i) {
                    this->swapL(temp,temp2);
                    temp = temp->next;
                    temp2 = temp2->prev;
                }
            }
        };

        BidirectionalIterator<T> begin(){
            BidirectionalIterator<T> it(this->head);
            return it;
        };

        BidirectionalIterator<T> end(){
            BidirectionalIterator<T> it(this->tail);
            return it;
        };

        string name() {
            return "Circular Linked List";
        }

        void merge(CircularLinkedList<T>& mergeList){
            if(this->head == nullptr){
                this->head= mergeList.head;
            }else if(mergeList.head != nullptr){
                this->tail->next = mergeList.head;
            }
            this->tail = mergeList.tail;
            this->tail->next = this->head;
            this->nodes += mergeList.nodes;
            mergeList.head = nullptr;
            mergeList.tail = nullptr;
            mergeList.nodes = 0;
        };

};

#endif