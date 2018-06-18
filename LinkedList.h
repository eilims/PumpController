//
// Created by db217620 on 6/12/2018.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

//#include "Node.h"
//#include <windef.h>
#include <Arduino.h>

template <class T>
class LinkedList {

private:
    //Member variables
    Node<T>* head;
    Node<T>* tail;
    int length;

    //Private methods
    int insertItem(Node<T>* item);
    T* findItem(int id, Node<T>* current);
    T* removeItem(int id, Node<T>* current);

public:
    //Constructor and Deconstructor
    LinkedList();
    ~LinkedList();

    //Usable Methods
    int insertItem(T* item);
    T* findItem(int id);
    T* removeItem(int id);

    //Getters
    T* getHead();
    T* getTail();
    int getLength();

    //Setters are not allowed

};


#endif //LINKEDLIST_LINKEDLIST_H
