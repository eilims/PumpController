//
// Created by db217620 on 8/4/2018.
//

#include "SensorList.h"

SensorList::SensorList() {
    this->sensorList = new LinkedList<Sensor>();
}

SensorList::~SensorList() = default;

LinkedList<Sensor> *SensorList::getList() {
    return this->sensorList;
}

unsigned int SensorList::getSensorDataMin() {
    Node<Sensor> *temp = this->sensorList->getHeadNode();
    unsigned int min = temp->getItem()->updateDataViaPin(20);
    for (int i = 1; i < this->sensorList->getLength(); i++) {
        int tempData = temp->getItem()->updateDataViaPin(20);
        if(tempData < min){
            min = tempData;
        }
        temp = temp->getNext();
    }
    return min;
}

unsigned int SensorList::getSensorDataAverage() {
    unsigned int data = 0;
    Node<Sensor> *temp = this->sensorList->getHeadNode();
    for (int i = 0; i < this->sensorList->getLength(); i++) {
        data += temp->getItem()->updateDataViaPin(20);
        temp = temp->getNext();
    }
    return data/this->sensorList->getLength();
}

unsigned int SensorList::getSensorDataMax() {
    Node<Sensor> *temp = this->sensorList->getHeadNode();
    unsigned int max = temp->getItem()->updateDataViaPin(20);
    for (int i = 1; i < this->sensorList->getLength(); i++) {
        unsigned int tempData = temp->getItem()->updateDataViaPin(20);
        if(tempData > max){
            max = tempData;
        }
        temp = temp->getNext();
    }
    return max;
}

