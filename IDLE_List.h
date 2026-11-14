#pragma once
#include "LinkedQueue.h"
#include "Car.h"
class IDLEList: public LinkedQueue<Car*> {
    public:
        bool insertCar(Car* car_rescheduled);
        bool reschedule(Car* car_rescheduled,int new_vt,int new_pt);
};
