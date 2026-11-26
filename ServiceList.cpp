#include "ServiceList.h"

int ServiceList::getTotalServiceTime() const {
	int sum = 0;
	Node <Service*>* ptr;
	ptr = frontPtr;
	while (ptr) {
		sum += ptr->getItem()->getDuration();
		ptr = ptr->getNext();
	}

	return sum;
}

Service* ServiceList::getfirstservice(){
	return frontPtr->getItem();
}

void ServiceList::makeitflixable(WaitEU& eu, WaitMU& mu, WaitWU& wu)
{
	PriorityQueue<Service*> tempPriqeue;
	Service* temp;
	int tempPri;

	while (dequeue(temp)) {

		switch (temp->getServiceType()) {

		case  TYPE_MU: {
			tempPriqeue.enqueue(temp, -mu.getTotalServiceTime());
			break;
		}


		case  TYPE_EU: {

			tempPriqeue.enqueue(temp, -eu.getTotalServiceTime());
			break;

		}


		default: {

			tempPriqeue.enqueue(temp, -wu.getTotalServiceTime());
			break;
			

		}
	}
	}
	while (tempPriqeue.dequeue(temp,tempPri)) {
		enqueue(temp);
	}
}