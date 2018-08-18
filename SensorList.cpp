//
// Created by db217620 on 8/4/2018.
//

#include "SensorList.h"

SensorList::SensorList() {
    this->sensorList = new LinkedList<Sensor>();
}

SensorList::~SensorList(){
	delete(sensorList);
}

LinkedList<Sensor> *SensorList::getList() {
    return this->sensorList;
}

void SensorList::addSensor(Sensor *sensor){
	this->sensorList->insertItem(sensor);
}

unsigned int SensorList::getSensorDataMin(int samples) {
    Node<Sensor> *temp = this->sensorList->getHeadNode();
    unsigned int min = temp->getItem()->updateDataViaPin(samples);
    for (int i = 1; i < this->sensorList->getLength(); i++) {
        unsigned int tempData = temp->getItem()->updateDataViaPin(samples);
        if(tempData < min){
            min = tempData;
        }
        temp = temp->getNext();
    }
    return min;
}

unsigned int SensorList::getSensorDataAverage(int samples) {
    unsigned int data = 0;
    Node<Sensor> *temp = this->sensorList->getHeadNode();
    for (int i = 0; i < this->sensorList->getLength(); i++) {
        data += temp->getItem()->updateDataViaPin(samples);
        temp = temp->getNext();
    }
    return data/this->sensorList->getLength();
}

unsigned int SensorList::getSensorDataMax(int samples) {
    Node<Sensor> *temp = this->sensorList->getHeadNode();
    unsigned int max = temp->getItem()->updateDataViaPin(samples);
    for (int i = 1; i < this->sensorList->getLength(); i++) {
        unsigned int tempData = temp->getItem()->updateDataViaPin(samples);
        if(tempData > max){
            max = tempData;
        }
        temp = temp->getNext();
    }
    return max;
}

