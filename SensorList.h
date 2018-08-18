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
	//Cosntructs intitally with an empty list
    SensorList();

	//Deletes sensorList
    ~SensorList();

	//Returns list in the event a direct manipulation is desired
    LinkedList<Sensor>* getList();
	
	//Adds a new sensor to the sensorList
	//It is recommended that the sensor's member fields are fully populated
	//before adding as there is no easy way to access sensors after insertion
	void addSensor(Sensor *sensor);

	//Returns the minimum data point from the set of averaged sensor readings
	//"samples" number of points per sensor is averaged then added to set of data
    unsigned int getSensorDataMin(int samples);

	//The return data is the average of all data in the set of averaged sensor readings
	//"samples" number of points per sensor is averaged then added to set of data
    unsigned int getSensorDataAverage(int samples);

	
	//Returns the maximum data point from the set of averaged sensor readings
	//"samples" number of points per sensor is averaged then added to set of data
    unsigned int getSensorDataMax(int samples);

};


#endif //LINKEDLIST_SENSORLIST_H
