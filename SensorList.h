//
// Created by db217620 on 8/4/2018.
//

#ifndef LINKEDLIST_SENSORLIST_H
#define LINKEDLIST_SENSORLIST_H


#include "LinkedList.h"
#include "Node.h"
#include "Sensor.h"

class SensorList {
private:
    LinkedList<Sensor> *sensorList;

public:
    SensorList();

    ~SensorList();

    LinkedList<Sensor>* getList();

    unsigned int getSensorDataMin();

    unsigned int getSensorDataAverage();

    unsigned int getSensorDataMax();

};


#endif //LINKEDLIST_SENSORLIST_H
