#include "LATE_List.h"

Car* LATEList::cancelRandomCar(int probability) {
	if (probability <= 0) return nullptr;
	if (!frontPtr) return nullptr;

	Node<Car*>* ptr = frontPtr;
	Car* selectedCar;
	while (ptr) {
		if (rand() % 100 < probability) {
			Node<Car*>* temp = ptr->getNext();
			if (!temp) {
				dequeue(selectedCar);
				return selectedCar;
			}
			ptr->setNext(temp->getNext());
			if (temp == backPtr) backPtr = ptr;
			selectedCar = temp->getItem();
			delete temp;
			return selectedCar;
		}
		ptr = ptr->getNext();
	}

	return nullptr;
}