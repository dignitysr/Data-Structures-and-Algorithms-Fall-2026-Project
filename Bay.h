#pragma once
#include <iostream>
#include <string>
#include "LinkedQueue.h"
#include "DEFS.h"

class Bay
{
	private:
		BayType type;
		int maxCapacity;
		int carCount;

	public:
		void setType(BayType _type);
		void setMaxCapacity(int x);
		void setCarCount(int x);
		void incrementCount();
		int getCapacity();
		int getcarCount();
		BayType getType();

};

