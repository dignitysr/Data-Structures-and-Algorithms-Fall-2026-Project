#include "WaitingList.h"

int WaitingList::getTotalServiceTime() {
	int total = 0;
	Car* carp = nullptr;
	LinkedQueue<Car*> temp;

	if (isEmpty())
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