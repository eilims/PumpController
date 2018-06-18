#include <iostream>
#include <assert.h>
#include "LinkedList.h"
#include "Node.h"


int unitTest_LinkedList(){
    LinkedList<int> list;
    int data = 5;
    int data2 = 7;
    int data3 = 10;
    int id = list.insertItem(&data);
    assert(id == 0);
    int id2 = list.insertItem(&data2);
    assert(id2 == 1);
    int id3 = list.insertItem(&data3);
    assert(id3 == 2);
    int item = *list.getHead();
    assert(item = data);
    int newData3 = *list.removeItem(id3);
    assert(newData3 == data3);
    int item2 = *list.findItem(id);
    assert(item2 == 5);
    int* item3 = list.findItem(3);
    assert(item3 == NULL);
    int* item4 = list.getTail();
    assert(*item4 == data2);
    int length = list.getLength();
    assert(length == 2);
    std::cout << "Linked List Unit Test Pass" << std::endl;
    return 0;
}

int unitTest_Node(){
    Node<int> node;
    Node<int> nextNode;
    int id0 = 0;
    int id1 = 1;
    int item0 = 10;
    int item1 = 20;

    node.setId(id0);
    nextNode.setId(id1);
    assert(node.getId() == id0);
    assert(nextNode.getId() == id1);

    node.setNext(&nextNode);
    nextNode.setNext(&node);
    assert(node.getNext() == &nextNode);
    assert(nextNode.getNext() == &node);

    node.setItem(&item0);
    nextNode.setItem(&item1);
    assert(*node.getItem() == item0);
    assert(*nextNode.getItem() == item1);

    std::cout << "Node Unit Test Pass" << std::endl;
    return 0;
}


int main() {
    std::cout << "Hello, World! Beginning Testing" << std::endl;
    unitTest_Node();
    unitTest_LinkedList();
    return 0;
}

