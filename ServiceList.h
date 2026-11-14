#pragma once
#include "LinkedQueue.h"
#include "Service.h"

class ServiceList: public LinkedQueue<Service> {
	public:
		int getTotalServiceTime() {
			int sum = 0;
			Node <Service>* ptr;
			ptr = frontPtr;
			while (ptr) {
				sum += ptr->getItem().getDuration();
				ptr = ptr->getNext();
			
			}
		}
};