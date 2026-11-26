#pragma once
#include "LinkedQueue.h"

class Car;

class WaitingList: public LinkedQueue<Car*>
{
	public:
		int getTotalServiceTime();
};

