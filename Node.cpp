//
// Created by db217620 on 6/12/2018.
//

#include "Node.h"

template <class T>
Node<T>::Node() {
    this->id = 0;
    this->next = NULL;
    this->item = NULL;
}

template <class T>
Node<T>::~Node() {

}

template <class T>
int Node<T>::getId() {
    return this->id;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

template <class T>
T* Node<T>::getItem() {
    return this->item;
}

template <class T>
void Node<T>::setId(int id) {
    this->id = id;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <class T>
void Node<T>::setItem(T* item) {
    this->item = item;
}

template class Node<int>;