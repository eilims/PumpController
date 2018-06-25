//
// Created by db217620 on 6/12/2018.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

//#include <Arduino.h>
#include <windef.h>

template <class T>

class Node {

private:
    int id;
    Node<T>* next;
    T* item;

public:
    //Constructor and Deconstructor
    Node();
    ~Node();

    //Getters
    int getId();
    Node<T>* getNext();
    T* getItem();

    //Setters
    void setId(int id);
    void setNext(Node<T>* next);
    void setItem(T* item);


};


#endif //LINKEDLIST_NODE_H
