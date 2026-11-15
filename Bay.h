#pragma once
#include <iostream>
#include <string>
#include "LinkedQueue.h"
#include "DEFS.h"

class Bay
{
	private:
		int bayID;
		BayType type;
		int maxCapacity;
		int carCount;

	public:
		
		void setType(BayType _type);
		void setID(int ID);
		void setMaxCapacity(int x);
		void setCarCount(int x);
		void incrementCount();
		void decrementCount();
		int getCapacity();
		int getID();
		int getCarCount();
		BayType getType();
		bool isBusy();
		virtual ~Bay() {}
		friend ostream& operator<<(ostream& os, const Bay* B);
		friend ostream& operator<<(ostream& os, Bay* B);
};

