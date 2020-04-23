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
            Node<T>* temp = new Node<T>;
            temp->next = this->head;
            temp->data = value;
            this->head = temp;
            if(this->nodes == 0){this->tail = temp;}
            this->nodes++;
            temp = nullptr;
            delete temp;


        };

        void push_back(T value){
            Node<T>* temp = this->tail;
            while (temp->next != nullptr){temp = temp->next;}
            temp->next = new Node<T>;
            temp = temp->next;
            temp->data = value;
            temp->next = nullptr;
            this->tail = temp;
            if(this->nodes == 0){this->head = temp;}
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
                this->nodes--;
            }else{
                Node<T>* temp = this->head;
                this->head = temp->next;
                temp->killSelf();
                temp = nullptr;
                delete temp;
            }
        };

        void pop_back(){
            if(this->nodes == 0 ){
                cout << "Can't pop back, the ForwardList is empty"<<endl;
                throw exception();
            }else if(this->nodes == 1){
                this->tail->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
                this->nodes--;
            }else{
                Node<T>* temp = this->head;
                while(temp->next->next != nullptr){temp = temp->next;}
                temp -> next = nullptr;
                this->tail->killSelf();
                this->tail = temp;
            }

        };

        T operator[](int position){
            if((position < 1) or (position > this->nodes)){
                cout << "La posición es invalida";
                throw exception();
            }else if(position == 1){
                return this->head->data;
            }else{
                Node<T>* temp = this->head;
                for (int i = 0; i < position-1; ++i){
                    temp = temp->next;
                }
                return temp->data;
            }
        }; /* Cree un Puntero de Node<T> temporal para encontrar
 *                                          el nodo buscado y retornar la data. Pero nose como borrarlo dps de retornar*/

        bool empty(){
            return this->nodes == 0;
        };

        int size(){
            return this->nodes;
        };

        void clear(){
            while (this->head != this->tail){
                this->pop_front();
                this->nodes--;
            }
            this->nodes--;
            this->pop_front();
        };

        void swap(Node<T>* A, Node<T>* B){
            Node<T>* temp = B;
            B->data = A->data;
            B->next = A;
            A->data = temp->data;
            A->next = temp;
            temp = nullptr;
            delete temp;
        };

        void sort(){
            if (this->nodes <= 1){
                cout << "The list is empty, there is nothing to sort";
                throw exception();
            }else{
                Node<T> *temp;
                for (int i = 0; i < this->nodes-1 ; ++i) {
                    temp = this->head;
                    for (int j = 0; j < this->nodes-i-1 ; ++j) {
                        if(temp->data > temp->next->data){
                            if(temp == this->head){this->head = temp->next;}
                            swap(temp, temp->next);
                        } else{
                            temp = temp->next;
                        }
                    }
                }
                temp= nullptr;
                delete temp;
            }
        };

        void reverse(){
            if(this->nodes == 0){
                cout << "The list is empty";
                throw exception();
            }else{
                Node<T>* temp;
                for (int i = 0; i < this->nodes-1; ++i) {
                    temp = this->head;
                    for (int j = 0; j < this->nodes - i - 1; ++j) {
                        if (temp == this->head) {this->head = temp->next;}
                        if(temp->next == this->tail){this->tail = temp;}
                        swap(temp, temp->next);
                    }
                }
            }
        };

        ForwardIterator<T> begin(){
            ForwardIterator<T> temp(this->head);
            return temp;
        };
	    ForwardIterator<T> end(){
            ForwardIterator<T> temp(this->tail);
            return temp;
	    };

        string name() {
            return "Forward List";
        }
        /**
         * Merges x into the list by transferring all of its elements at their respective
         * ordered positions into the container (both containers shall already be ordered).
         *
         * This effectively removes all the elements in x (which becomes empty), and inserts
         * them into their ordered position within container (which expands in size by the number
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue,
         * or whether the value_type supports move-construction or not.
        */
        void merge(ForwardList<T>& mergeList){
            this->tail->next = mergeList.head;
            this->tail = mergeList.tail;
            this->nodes += mergeList.nodes;
        };
};



#endif