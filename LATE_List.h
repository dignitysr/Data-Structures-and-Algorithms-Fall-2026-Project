#pragma once
#include "LinkedQueue.h"
#include "Car.h"
class LATEList: public LinkedQueue<Car*> {
    public:
        Car* cancelRandomCar(int probability);
};