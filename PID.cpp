//
// Created by db217620 on 6/25/2018.
//

#include "PID.h"

PID::PID(double kc, double ti, double td) {
    this->kc = kc;
    this->ti = ti;
    this->td = td;
}

PID::~PID() {

}

int PID::generateNewProcessVariable(int currentReading) {
    currentReading = this->setPoint - currentReading;

    int proportional = (int) (kc * currentReading);
    int currentIntegral = (int) (ti * kc * currentReading);
    int currentDerivative = (int) (td * kc * currentReading);

    this->integral += currentIntegral;
    int derivative = derivativePrevious - currentDerivative;

    derivativePrevious = currentDerivative;

    return derivative + this->integral + derivative;
}

double PID::getKc() const {
    return kc;
}

void PID::setKc(double kc) {
    PID::kc = kc;
}

double PID::getTi() const {
    return ti;
}

void PID::setTi(double ti) {
    PID::ti = ti;
}

double PID::getTd() const {
    return td;
}

void PID::setTd(double td) {
    PID::td = td;
}

int PID::getSetPoint() const {
    return setPoint;
}

void PID::setSetPoint(int setPoint) {
    PID::setPoint = setPoint;
}
