#pragma once
#include "LinkedQueue.h"
#include "Car.h"
class WAIT_EU : public LinkedQueue<Car*> {
	int GetTotalServiceTime(){

		int total;
		Car* carp = nullptr;
		LinkedQueue<Car*> temp;

		if (isEmpty)
		{
			return total;
		}

		while (dequeue(carp))
		{
			total = total + carp->GetTotalServiceTime();
			temp.enqueue(carp);
		}
		return total;

		while (temp.dequeue(carp)) {
			enqueue(carp);
		}

	}
};