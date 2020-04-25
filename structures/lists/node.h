#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    this->next = nullptr;
    this->prev = nullptr;
    delete next;
    delete prev;
}

#endif