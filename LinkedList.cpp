//
// Created by db217620 on 6/12/2018.
//

#include "LinkedList.h"

template<class T>

LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
	Node<T> *temp = this->head;
	for(int i; i < this->length; i++){
		delete(temp);
		temp = temp->getNext();
	}
}

//Usable Methods

//Returns the id of Node the inserted item is in
template<class T>
int LinkedList<T>::insertItem(T *item) {
    //Creating node to be inserted into list with the item as data
    Node<T> *node = new Node<T>();
    node->setItem(item);
    node->setId(this->length);
    //Length is increasing by one
    this->length++;
    //Insertion at tail
    insertItem(node);
    //Return id of node containing item pointer
    return node->getId();
}

//Returns the item inside the node with the corresponding id
//Returns NULL if no node with a corresponding id is found
template<class T>
T *LinkedList<T>::findItem(int id) {
    //Searches for the node via id from the head recursively
    return findItem(id, this->head);
}

//Returns the item inside the deleted node
//Returns NULL if no node with the corresponding id is found
template<class T>
T *LinkedList<T>::removeItem(int id) {
    //Case for if the head is the node to be deleted
    if (this->head->getId() == id) {
        Node<T> *temp = this->head;
        T *item = temp->getItem();
        this->head = temp->getNext();
        delete temp;
        this->length--;
        return item;
        //Case for if any other node is to be deleted
    } else {
        //Searches for the node to be deleted recursively from the head
        return removeItem(id, this->head);
    }
}

//Private methods

template<class T>
int LinkedList<T>::insertItem(Node<T> *item) {
    //Condition for empty list
    if (this->head == NULL) {
        this->head = item;
        this->tail = item;
        //Condition for non empty list
    } else {
        this->tail->setNext(item);
        this->tail = item;
    }
}

template<class T>
T *LinkedList<T>::findItem(int id, Node<T> *current) {
    //If the current node is empty this implies the id was not found
    if (current == NULL) {
        return NULL;
        //If the current node id matches return the T object not its pointer
    } else if (current->getId() == id) {
        return current->getItem();
        //If the current node is not a match for the id and is not NULL move one step into the list
    } else {
        return findItem(id, current->getNext());
    }
}

template<class T>
T *LinkedList<T>::removeItem(int id, Node<T> *current) {
    //If the next node is NULL this implies the entire list has been searched
    if (current->getNext() == NULL) {
        return NULL;
        //If the next node is a match
    } else if (current->getNext()->getId() == id) {
        //Create temp for reference
        Node<T> *temp = current->getNext();
        //Get item pointer
        T *item = temp->getItem();
        //Skip over node to be deleted
        current->setNext(temp->getNext());
        //Set tail if the tail node is being deleted
        if (temp == this->tail) {
            this->tail = current;
        }
        //Free node memory location
        delete temp;
        this->length--;
        return item;
        //If the next node is not to be deleted and is not NULL move one step into the lust
    } else {
        return removeItem(id, current->getNext());
    }
}

//Getters

template<class T>
T *LinkedList<T>::getHead() {
    return this->head->getItem();
}

template<class T>
Node<T> *LinkedList<T>::getHeadNode() {
    return this->head;
}

template<class T>
T *LinkedList<T>::getTail() {
    return this->tail->getItem();
}

template<class T>
Node<T> *LinkedList<T>::getTailNode() {
    return this->tail;
}

template<class T>
int LinkedList<T>::getLength() {
    return this->length;
}

template
class LinkedList<int>;
template
class LinkedList<Sensor>;