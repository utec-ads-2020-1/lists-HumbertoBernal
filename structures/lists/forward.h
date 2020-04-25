#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front(){
            if (this->nodes != 0){
                return this->head->data;
            }else{
                cout << "There is no front, the ForwardList is empty";
                throw exception();
            }
        };

        T back(){
            if (this->nodes != 0){
                return this->tail->data;
            }else{
                cout << "There is no back, the ForwardList is empty";
                throw exception();
            }
        };

        void push_front(T value){
            auto* temp = new Node<T>;
            temp->next = this->head;
            temp->data = value;
            this->head = temp;
            if(this->nodes == 0){this->tail = temp;}
            this->nodes++;
            temp = nullptr;
            delete temp;
            this->head->prev = nullptr;
        };

        void push_back(T value){
            auto* temp = new Node<T>;
            temp->data = value;
            if(this->nodes == 0){
                temp->data = value;
                temp->next = nullptr;

                this->head = temp;
                this->tail = temp;

            }else{
                temp->next = this->tail->next;
                this->tail->next = temp;
                this->tail = temp;
            }
            this->nodes++;
            temp = nullptr;
            delete temp;
        };

        void pop_front(){
            if(this->nodes == 0 ){
                cout << "Can't pop front, the ForwardList is empty"<<endl;
                throw exception();
            }else if(this->nodes == 1){
                this->head->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node<T>* temp = this->head;
                this->head = temp->next;
                temp->killSelf();
                temp = nullptr;
                delete temp;
            }
            this->nodes--;
        };

        void pop_back(){
            if(this->nodes == 0 ){
                cout << "Can't pop back, the ForwardList is empty"<<endl;
                throw exception();
            }else if(this->nodes == 1){
                this->tail->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node<T>* temp = this->head;
                while(temp->next->next != nullptr){temp = temp->next;}
                temp -> next = nullptr;
                this->tail->killSelf();
                this->tail = temp;
            }
            this->nodes--;
        };

        T operator[](int position){
            if((position > this->nodes)){
                throw "La posición es invalida";
            }else if(position == 0){
                return this->head->data;
            }else{
                Node<T>* temp = this->head;
                for (int i = 0; i < position; ++i){
                    temp = temp->next;
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

        void swapL(Node<T>* A, Node<T>* B){
            auto* temp2 = new Node<T>;
            temp2->data = A->data;
            A->data = B->data;
            B->data = temp2->data;
            temp2 = nullptr;
            delete temp2;
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
                temp= nullptr;
            }
        };

        void reverse(){
            if(this->nodes > 1){
                Node<T> *temp;
                for (int i = 0; i < this->nodes-1 ; ++i) {
                    temp = this->head;
                    temp->next = this->head->next;
                    for (int j = 0; j < this->nodes-i-1 ; ++j) {
                        auto* temp2 = new Node<T>;
                        temp2->data = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = temp2->data;
                        temp2 = nullptr;
                        delete temp2;
                        temp = temp->next;
                    }
                }
                temp= nullptr;
            }
        };

        ForwardIterator<T> begin(){
            ForwardIterator<T> temp(this->head);
            return temp;
        };
        ForwardIterator<T> end(){
            ForwardIterator<T> temp(this->tail->next);
            return temp;
        };

        string name() {
            return "Forward List";
        }

        void merge(ForwardList<T>& mergeList){

            if(this->head == nullptr){
                this->head= mergeList.head;
            }else if(mergeList.head == nullptr){
                return;
            }else{
                this->tail->next = mergeList.head;
            }
            this->tail = mergeList.tail;
            this->nodes += mergeList.nodes;
            mergeList.head = nullptr;
            mergeList.tail = nullptr;
            mergeList.nodes = 0;
        };
};

#endif