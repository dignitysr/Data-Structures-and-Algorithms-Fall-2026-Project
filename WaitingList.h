#pragma once
#include "LinkedQueue.h"
#include "Car.h"

class WaitingList: public LinkedQueue<Car*>
{
	public:
		int getTotalServiceTime();
};

