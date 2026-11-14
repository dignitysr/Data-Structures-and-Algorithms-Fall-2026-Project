#pragma once
#include "LinkedQueue.h"
#include "Car.h"

class WaitingList: public LinkedQueue<Car*>
{
	public:
		int getTotalServiceTime() {
			int total;
			Car* carp = nullptr;
			LinkedQueue<Car*> temp;

			if (isEmpty)
			{
				return total;
			}

			while (dequeue(carp))
			{
				total = total + carp->getTotalServiceTime();
				temp.enqueue(carp);
			}
			return total;

			while (temp.dequeue(carp)) {
				enqueue(carp);
			}

		}
};

