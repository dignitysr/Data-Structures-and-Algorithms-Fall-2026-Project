#include "ERLY_List.h"

Car* ERLYList::removeRandomCar(int pCancel) {
	PriorityQueue<Car*> temp;
	Car* removedCar = nullptr;
	Car* car = nullptr;
	int priority;
	while (dequeue(car, priority)) {
		bool removed = false;

		if (rand() % 100 < pCancel && !removedCar) {
			removed = true;
			removedCar = car;
		}
		if (!removed) temp.enqueue(car, priority);
	}

	while (temp.dequeue(car, priority)) enqueue(car, priority);

	return removedCar;
}