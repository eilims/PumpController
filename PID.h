//
// Created by db217620 on 6/25/2018.
//

#ifndef LINKEDLIST_PID_H
#define LINKEDLIST_PID_H


class PID {
private:
    double kc;
    double ti;
    double td;
    int integral;
    int derivativePrevious;
    int setPoint;

public:
    PID(double kc, double ti, double td);

    ~PID();

    int generateNewProcessVariable(int currentReading);

    double getKc() const;

    void setKc(double kc);

    double getTi() const;

    void setTi(double ti);

    double getTd() const;

    void setTd(double td);

    int getSetPoint() const;

    void setSetPoint(int setPoint);
};


#endif //LINKEDLIST_PID_H
