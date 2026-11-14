#pragma once
#include "LinkedQueue.h"
#include "Car.h"
class IDLE_List : public LinkedQueue<Car*> {
    bool InsertCar(Car* car_rescheduled) {
        if (car_rescheduled == nullptr) { return false; }
      

        priQueue<Car*> temp;
        Car* carp = nullptr;
        int Pri = 0;
        if (isEmpty)
        {
            temp.enqueue(car_rescheduled, -car_rescheduled->getVT());
            return true;
        }
  
        while (dequeue(carp)) {
            temp.enqueue(carp, -carp->getVT());
        }

        temp.enqueue(car_rescheduled, -car_rescheduled->getVT());

        while (temp.dequeue(carp, Pri)) {
            enqueue(carp);
        }

        return true;
    }
    bool reshcedule(Car* car_rescheduled,int new_vt,int new_pt) {
        car_rescheduled->setPT(new_pt);
        car_rescheduled->setVT(new_vt);
        InsertCar(car_rescheduled);
    }
};
