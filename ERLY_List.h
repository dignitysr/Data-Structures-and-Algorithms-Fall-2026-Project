#pragma once
#pragma once
#include "priQueue.h"
#include "Car.h"

class ERLYList: public PriorityQueue<Car*> {
    public:
        Car* removeRandomCar(int pCancel);
};