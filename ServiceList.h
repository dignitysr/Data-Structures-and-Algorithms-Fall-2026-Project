#pragma once
#include "LinkedQueue.h"
#include "Service.h"

class ServiceList: public LinkedQueue<Service> {
	public:
		int getTotalServiceTime() const;
};