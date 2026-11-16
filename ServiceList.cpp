#include "ServiceList.h"

int ServiceList::getTotalServiceTime() const {
	int sum = 0;
	Node <Service>* ptr;
	ptr = frontPtr;
	while (ptr) {
		sum += ptr->getItem().getDuration();
		ptr = ptr->getNext();
	}

	return sum;
}
