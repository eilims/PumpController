#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    LinkedList<int>* list = new LinkedList<int>();
    int data = 5;
    int id = list->insertItem(&data);
    int data2 = 7;
    int id2 = list->insertItem(&data2);
    int data3 = 10;
    int id3 = list->insertItem(&data3);
    int item = *list->getHead();
    data3 = *list->removeItem(id3);
    int item2 = *list->findItem(id);
    int* item3 = list->findItem(3);
    return 0;
}